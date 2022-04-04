//
// "$Id: code.cxx,v 1.9.2.9.2.6 2003/08/02 21:17:30 easysw Exp $"
//
// Code output routines for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2003 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "fltk-bugs@fltk.org".
//

#include <stdio.h>
#include <stdlib.h>
#include "../src/flstring.h"
#include <stdarg.h>

#include <FL/Fl.H>
#include "Fl_Type.h"
#include "alignment_panel.h"
#include <FL/fl_utf8.H>

static FILE *code_file;
static FILE *header_file;

extern char i18n_program[];
extern int i18n_type;
extern const char* i18n_include;
extern const char* i18n_function;
extern const char* i18n_file;
extern const char* i18n_set;

// return true if c can be in a C identifier.  I needed this so
// it is not messed up by locale settings:
int is_id(char c) {
  return c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9' || c=='_';
}

////////////////////////////////////////////////////////////////
// Generate unique but human-readable identifiers:

struct id {
  char* text;
  void* object;
  id *left, *right;
  id (const char* t, void* o) : text(strdup(t)), object(o) {left = right = 0;}
  ~id();
};

id::~id() {
  delete left;
  free((void *)text);
  delete right;
}

static id* id_root;

const char* unique_id(void* o, const char* type, const char* name, const char* label) {
  char buffer[128];
  char* q = buffer;
  while (*type) *q++ = *type++;
  *q++ = '_';
  const char* n = name;
  if (!n || !*n) n = label;
  if (n && *n) {
    while (*n && !is_id(*n)) n++;
    while (is_id(*n)) *q++ = *n++;
  }
  *q = 0;
  // okay, search the tree and see if the name was already used:
  id** p = &id_root;
  int which = 0;
  while (*p) {
    int i = strcmp(buffer, (*p)->text);
    if (!i) {
      if ((*p)->object == o) return (*p)->text;
      // already used, we need to pick a new name:
      sprintf(q,"%x",++which);
      p = &id_root;
      continue;
    }
    else if (i < 0) p = &((*p)->left);
    else p  = &((*p)->right);
  }
  *p = new id(buffer, o);
  return (*p)->text;
}

////////////////////////////////////////////////////////////////
// return current indentation:

static const char* spaces = "                ";
int indentation;
const char* indent() {
  int i = indentation; if (i>16) i = 16;
  return spaces+16-i;
}

////////////////////////////////////////////////////////////////
// declarations/include files:
// Each string generated by write_declare is written only once to
// the header file.  This is done by keeping a binary tree of all
// the calls so far and not printing it if it is in the tree.

struct included {
  char *text;
  included *left, *right;
  included(const char *t) {
    text = strdup(t);
    left = right = 0;
  }
  ~included();
};

included::~included() {
  delete left;
  free((void *)text);
  delete right;
}
static included *included_root;

int write_declare(const char *format, ...) {
  va_list args;
  char buf[1024];
  va_start(args, format);
  vsnprintf(buf, sizeof(buf), format, args);
  va_end(args);
  included **p = &included_root;
  while (*p) {
    int i = strcmp(buf,(*p)->text);
    if (!i) return 0;
    else if (i < 0) p = &((*p)->left);
    else p  = &((*p)->right);
  }
  fprintf(header_file,"%s\n",buf);
  *p = new included(buf);
  return 1;
}

////////////////////////////////////////////////////////////////

// silly thing to prevent declaring unused variables:
// When this symbol is on, all attempts to write code don't write
// anything, but set a variable if it looks like the varaible "o" is used:
int varused_test;
int varused;

// write an array of C characters (adds a null):
void write_cstring(const char *w, int length) {
  if (varused_test) return;
  const char *e = w+length;
  int linelength = 1;
  putc('\"', code_file);
  for (; w < e;) {
    int c = *w++;
    switch (c) {
    case '\b': c = 'b'; goto QUOTED;
    case '\t': c = 't'; goto QUOTED;
    case '\n': c = 'n'; goto QUOTED;
    case '\f': c = 'f'; goto QUOTED;
    case '\r': c = 'r'; goto QUOTED;
    case '\"':
    case '\'':
    case '\\':
    QUOTED:
      if (linelength >= 77) {fputs("\\\n",code_file); linelength = 0;}
      putc('\\', code_file);
      putc(c, code_file);
      linelength += 2;
      break;
    case '?': // prevent trigraphs by writing ?? as ?\?
      if (*(w-2) == '?') goto QUOTED;
      // else fall through:
    default:
      if (c >= ' ' && c < 127) {
	// a legal ASCII character
	if (linelength >= 78) {fputs("\\\n",code_file); linelength = 0;}
	putc(c, code_file);
	linelength++;
	break;
      }
      // otherwise we must print it as an octal constant:
      c &= 255;
      if (c < 8) {
	if (linelength >= 76) {fputs("\\\n",code_file); linelength = 0;}
	fprintf(code_file, "\\%o",c);
	linelength += 2;
      } else if (c < 64) {
	if (linelength >= 75) {fputs("\\\n",code_file); linelength = 0;}
	fprintf(code_file, "\\%o",c);
	linelength += 3;
      } else {
	if (linelength >= 74) {fputs("\\\n",code_file); linelength = 0;}
	fprintf(code_file, "\\%o",c);
	linelength += 4;
      }
      // We must not put more numbers after it, because some C compilers
      // consume them as part of the quoted sequence.  Use string constant
      // pasting to avoid this:
      c = *w;
      if (w < e && (c>='0'&&c<='9' || c>='a'&&c<='f' || c>='A'&&c<='F')) {
	putc('\"', code_file); linelength++;
	if (linelength >= 79) {fputs("\n",code_file); linelength = 0;}
	putc('\"', code_file); linelength++;
      }
      break;
    }
  }
  putc('\"', code_file);
}

// write a C string, quoting characters if necessary:
void write_cstring(const char *w) {write_cstring(w,strlen(w));}

void write_c(const char* format,...) {
  if (varused_test) {varused = 1; return;}
  va_list args;
  va_start(args, format);
  vfprintf(code_file, format, args);
  va_end(args);
}

void write_h(const char* format,...) {
  if (varused_test) return;
  va_list args;
  va_start(args, format);
  vfprintf(header_file, format, args);
  va_end(args);
}

#include <FL/filename.H>
int write_number;

// recursively dump code, putting children between the two parts
// of the parent code:
static Fl_Type* write_code(Fl_Type* p) {
  p->write_code1();
  Fl_Type* q;
  for (q = p->next; q && q->level > p->level;) q = write_code(q);
  p->write_code2();
  return q;
}

extern const char* header_file_name;

int write_code(const char *s, const char *t) {
  write_number++;
  delete id_root; id_root = 0;
  indentation = 0;
  if (!s) code_file = stdout;
  else {
    FILE *f = fl_fopen(s,"w");
    if (!f) return 0;
    code_file = f;
  }
  if (!t) header_file = stdout;
  else {
    FILE *f = fl_fopen(t,"w");
    if (!f) {fclose(code_file); return 0;}
    header_file = f;
  }
  const char *hdr = "\
// generated by Fast Light User Interface Designer (fluid) version %.4f\n\n";
  fprintf(header_file, hdr, FL_VERSION);
  fprintf(code_file, hdr, FL_VERSION);

  {char define_name[102];
  const char* a = fl_filename_name(t);
  char* b = define_name;
  if (!isalpha(*a)) {*b++ = '_';}
  while (*a) {*b++ = isalnum(*a) ? *a : '_'; a++;}
  *b = 0;
  fprintf(header_file, "#ifndef %s\n", define_name);
  fprintf(header_file, "#define %s\n", define_name);
  }  

  write_declare("#include <FL/Fl.H>");
  if (i18n_type && i18n_include[0]) {
    if (i18n_include[0] != '<' &&
        i18n_include[0] != '\"')
      write_c("#include \"%s\"\n", i18n_include);
    else
      write_c("#include %s\n", i18n_include);
    if (i18n_type == 2) {
      if (i18n_file[0]) write_c("extern nl_catd %s;\n", i18n_file);
      else {
        write_c("// Initialize I18N stuff now for menus...\n");
        write_c("#include <locale.h>\n");
	write_c("static char *_locale = setlocale(LC_MESSAGES, \"\");\n");
        write_c("static nl_catd _catalog = catopen(\"%s\", 0);\n",
                   i18n_program);
      }
    }
  }
  if (t && include_H_from_C) {
    if (*header_file_name == '.' && strchr(header_file_name, '/') == NULL) {
      write_c("#include \"%s\"\n", fl_filename_name(t));
    } else {
      write_c("#include \"%s\"\n", t);
    }
  }
  for (Fl_Type* p = Fl_Type::first; p;) {
    // write all static data for this & all children first
    p->write_static();
    for (Fl_Type* q = p->next; q && q->level > p->level; q = q->next)
      q->write_static();
    // then write the nested code:
    p = write_code(p);
  }

  delete included_root; included_root = 0;

  if (!s) return 1;
  int x = fclose(code_file);
  code_file = 0;
  fprintf(header_file, "#endif\n");
  int y = fclose(header_file);
  header_file = 0;
  return x >= 0 && y >= 0;
}

int write_strings(const char *sfile) {
  FILE *fp = fl_fopen(sfile, "w");
  Fl_Type *p;
  Fl_Widget_Type *w;
  int i;

  if (!fp) return 1;

  switch (i18n_type) {
  case 0 : /* None, just put static text out */
      fprintf(fp, "# generated by Fast Light User Interface Designer (fluid) version %.4f\n",
	      FL_VERSION);
      for (p = Fl_Type::first; p; p = p->next) {
        if (p->is_widget()) {
	  w = (Fl_Widget_Type *)p;

	  if (w->label()) {
	    for (const char *s = w->label(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            putc('\n', fp);
	  }

	  if (w->tooltip()) {
	    for (const char *s = w->tooltip(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            putc('\n', fp);
	  }
	}
      }
      break;
  case 1 : /* GNU gettext, put a .po file out */
      fprintf(fp, "# generated by Fast Light User Interface Designer (fluid) version %.4f\n",
	      FL_VERSION);
      for (p = Fl_Type::first; p; p = p->next) {
        if (p->is_widget()) {
	  w = (Fl_Widget_Type *)p;

	  if (w->label()) {
	    const char *s;

	    fputs("msgid \"", fp);
	    for (s = w->label(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            fputs("\"\n", fp);

	    fputs("msgstr \"", fp);
	    for (s = w->label(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            fputs("\"\n", fp);
	  }

	  if (w->tooltip()) {
	    const char *s;

	    fputs("msgid \"", fp);
	    for (s = w->tooltip(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            fputs("\"\n", fp);

	    fputs("msgstr \"", fp);
	    for (s = w->tooltip(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            fputs("\"\n", fp);
	  }
	}
      }
      break;
  case 2 : /* POSIX catgets, put a .msg file out */
      fprintf(fp, "$ generated by Fast Light User Interface Designer (fluid) version %.4f\n",
	      FL_VERSION);
      fprintf(fp, "$set %s\n", i18n_set);
      fputs("$quote \"\n", fp);

      for (i = 1, p = Fl_Type::first; p; p = p->next) {
        if (p->is_widget()) {
	  w = (Fl_Widget_Type *)p;

	  if (w->label()) {
	    fprintf(fp, "%d \"", i ++);
	    for (const char *s = w->label(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            fputs("\"\n", fp);
	  }

	  if (w->tooltip()) {
	    fprintf(fp, "%d \"", i ++);
	    for (const char *s = w->tooltip(); *s; s ++)
	      if (*s < 32 || *s > 126 || *s == '\"')
		fprintf(fp, "\\%03o", *s);
	      else
		putc(*s, fp);
            fputs("\"\n", fp);
	  }
	}
      }
      break;
  }

  return fclose(fp);
}

////////////////////////////////////////////////////////////////

void Fl_Type::write_static() {}
void Fl_Type::write_code1() {
  write_h("// Header for %s\n", title());
  write_c("// Code for %s\n", title());
}
void Fl_Type::write_code2() {}

//
// End of "$Id: code.cxx,v 1.9.2.9.2.6 2003/08/02 21:17:30 easysw Exp $".
//

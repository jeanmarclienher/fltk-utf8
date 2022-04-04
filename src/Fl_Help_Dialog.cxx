// generated by Fast Light User Interface Designer (fluid) version 1.0100

#include "../FL/Fl_Help_Dialog.H"
#include "flstring.h"
#include <FL/fl_ask.H>

inline void Fl_Help_Dialog::cb_view__i(Fl_Help_View*, void*) {
  if (view_->changed())
{
  index_ ++;

  if (index_ >= 100)
  {
    memmove(line_, line_ + 10, sizeof(line_[0]) * 90);
    memmove(file_, file_ + 10, sizeof(file_[0]) * 90);
    index_ -= 10;
  }

  max_ = index_;

  strlcpy(file_[index_], view_->filename(),sizeof(file_[0]));
  line_[index_] = view_->topline();

  if (index_ > 0)
    back_->activate();
  else
    back_->deactivate();

  forward_->deactivate();
  window_->label(view_->title());
}
else if (view_->filename())
{
  strlcpy(file_[index_], view_->filename(), sizeof(file_[0]));
  line_[index_] = view_->topline();
};
}
void Fl_Help_Dialog::cb_view_(Fl_Help_View* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_view__i(o,v);
}

inline void Fl_Help_Dialog::cb_Close_i(Fl_Button*, void*) {
  window_->hide();
}
void Fl_Help_Dialog::cb_Close(Fl_Button* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_Close_i(o,v);
}

inline void Fl_Help_Dialog::cb_back__i(Fl_Button*, void*) {
  if (index_ > 0)
  index_ --;

if (index_ == 0)
  back_->deactivate();

forward_->activate();

if (strcmp(view_->filename(), file_[index_]) != 0)
  view_->load(file_[index_]);

view_->topline(line_[index_]);
}
void Fl_Help_Dialog::cb_back_(Fl_Button* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_back__i(o,v);
}

inline void Fl_Help_Dialog::cb_forward__i(Fl_Button*, void*) {
  if (index_ < max_)
  index_ ++;

if (index_ >= max_)
  forward_->deactivate();

back_->activate();

if (strcmp(view_->filename(), file_[index_]) != 0)
  view_->load(file_[index_]);

view_->topline(line_[index_]);
}
void Fl_Help_Dialog::cb_forward_(Fl_Button* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_forward__i(o,v);
}

inline void Fl_Help_Dialog::cb_smaller__i(Fl_Button*, void*) {
  if (view_->textsize() > 8)
  view_->textsize(view_->textsize() - 2);

if (view_->textsize() <= 8)
  smaller_->deactivate();
larger_->activate();
}
void Fl_Help_Dialog::cb_smaller_(Fl_Button* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_smaller__i(o,v);
}

inline void Fl_Help_Dialog::cb_larger__i(Fl_Button*, void*) {
  if (view_->textsize() < 18)
  view_->textsize(view_->textsize() + 2);

if (view_->textsize() >= 18)
  larger_->deactivate();
smaller_->activate();
}
void Fl_Help_Dialog::cb_larger_(Fl_Button* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_larger__i(o,v);
}

const char* fl_show_previous_help_page = "Show the previous help page.";
const char* fl_make_the_help_text_smaller = "Make the help text smaller.";
const char* fl_show_next_help_page = "Show the next help page.";
const char* fl_make_the_help_text_larger = "Make the help text larger.";
const char* fl_help_dialog = "Help Dialog";

inline void Fl_Help_Dialog::cb_find__i(Fl_Input*, void*) {
  find_pos_ = view_->find(find_->value(), find_pos_);
}
void Fl_Help_Dialog::cb_find_(Fl_Input* o, void* v) {
  ((Fl_Help_Dialog*)(o->parent()->user_data()))->cb_find__i(o,v);
}

Fl_Help_Dialog::Fl_Help_Dialog() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = window_ = new Fl_Double_Window(530, 385, fl_help_dialog);
    w = o;
    o->user_data((void*)(this));
    { Fl_Help_View* o = view_ = new Fl_Help_View(10, 10, 510, 330);
      o->box(FL_DOWN_BOX);
      o->color(49);
      o->selection_color(15);
      o->labeltype(FL_NORMAL_LABEL);
      o->labelfont(0);
      o->labelsize(14);
      o->labelcolor(56);
      o->callback((Fl_Callback*)cb_view_);
      o->align(FL_ALIGN_TOP);
      o->when(FL_WHEN_RELEASE);
      o->end();
      Fl_Group::current()->resizable(o);
    }
    { Fl_Button* o = new Fl_Button(425, 350, 95, 25, fl_close);
      o->callback((Fl_Callback*)cb_Close);
      o->label(fl_close);
    }
    { Fl_Button* o = back_ = new Fl_Button(355, 350, 25, 25, "@<-");
      o->tooltip(fl_show_previous_help_page);
      o->shortcut(0xff51);
      o->labelcolor(2);
      o->callback((Fl_Callback*)cb_back_);
    }
    { Fl_Button* o = forward_ = new Fl_Button(390, 350, 25, 25, "@->");
      o->tooltip(fl_show_next_help_page);
      o->shortcut(0xff53);
      o->labelcolor(2);
      o->callback((Fl_Callback*)cb_forward_);
    }
    { Fl_Button* o = smaller_ = new Fl_Button(285, 350, 25, 25, "F");
      o->tooltip(fl_make_the_help_text_smaller);
      o->labelfont(1);
      o->labelsize(10);
      o->callback((Fl_Callback*)cb_smaller_);
    }
    { Fl_Button* o = larger_ = new Fl_Button(320, 350, 25, 25, "F");
      o->tooltip(fl_make_the_help_text_larger);
      o->labelfont(1);
      o->labelsize(16);
      o->callback((Fl_Callback*)cb_larger_);
    }
    { Fl_Input* o = find_ = new Fl_Input(10, 350, 265, 25);
      o->callback((Fl_Callback*)cb_find_);
      o->when(FL_WHEN_ENTER_KEY_ALWAYS);
    }

    o->end();
  }
  back_->deactivate();
forward_->deactivate();

index_ = -1;
max_  = 0;
find_pos_ = 0;

fl_register_images();
}

Fl_Help_Dialog::~Fl_Help_Dialog() {
  delete window_;
}

int Fl_Help_Dialog::h() {
  return (window_->h());
}

void Fl_Help_Dialog::hide() {
  window_->hide();
}

void Fl_Help_Dialog::load(const char *f) {
  view_->set_changed();
view_->load(f);
window_->label(view_->title());
}

void Fl_Help_Dialog::position(int xx, int yy) {
  window_->position(xx, yy);
}

void Fl_Help_Dialog::resize(int xx, int yy, int ww, int hh) {
  window_->resize(xx, yy, ww, hh);
}

void Fl_Help_Dialog::show() {
  window_->show();
}

void Fl_Help_Dialog::show(int argc, char **argv) {
  window_->show(argc, argv);
}

void Fl_Help_Dialog::textsize(uchar s) {
  view_->textsize(s);

if (s <= 8)
  smaller_->deactivate();
else
  smaller_->activate();

if (s >= 18)
  larger_->deactivate();
else
  larger_->activate();
}

uchar Fl_Help_Dialog::textsize() {
  return (view_->textsize());
}

void Fl_Help_Dialog::topline(const char *n) {
  view_->topline(n);
}

void Fl_Help_Dialog::topline(int n) {
  view_->topline(n);
}

int Fl_Help_Dialog::visible() {
  return (window_->visible());
}

int Fl_Help_Dialog::w() {
  return (window_->w());
}

int Fl_Help_Dialog::x() {
  return (window_->x());
}

int Fl_Help_Dialog::y() {
  return (window_->y());
}

//
// "$Id: Fl_Tabs.cxx,v 1.6.2.10.2.20 2004/07/27 16:02:21 easysw Exp $"
//
// Tab widget for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2004 by Bill Spitzak and others.
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

// This is the "file card tabs" interface to allow you to put lots and lots
// of buttons and switches in a panel, as popularized by many toolkits.

// Each child widget is a card, and it's label() is printed on the card tab.
// Clicking the tab makes that card visible.

#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/fl_draw.H>

#define BORDER 2
#define EXTRASPACE 10

// return the left edges of each tab (plus a fake left edge for a tab
// past the right-hand one).  These position are actually of the left
// edge of the slope.  They are either seperated by the correct distance
// or by EXTRASPACE or by zero.
// Return value is the index of the selected item.

int Fl_Tabs::tab_positions(int* p, int* wp) {
  int selected = 0;
  Fl_Widget*const* a = array();
  int i;
  p[0] = Fl::box_dx(box());
  for (i=0; i<children(); i++) {
    Fl_Widget* o = *a++;
    if (o->visible()) selected = i;

    int wt = 0; int ht = 0;
    o->measure_label(wt,ht);

    wp[i]  = wt+EXTRASPACE;
    p[i+1] = p[i]+wp[i]+BORDER;
  }
  int r = w();
  if (p[i] <= r) return selected;
  // uh oh, they are too big:
  // pack them against right edge:
  p[i] = r;
  for (i = children(); i--;) {
    int l = r-wp[i];
    if (p[i+1] < l) l = p[i+1];
    if (p[i] <= l) break;
    p[i] = l;
    r -= EXTRASPACE;
  }
  // pack them against left edge and truncate width if they still don't fit:
  for (i = 0; i<children(); i++) {
    if (p[i] >= i*EXTRASPACE) break;
    p[i] = i*EXTRASPACE;
    int W = w()-1-EXTRASPACE*(children()-i) - p[i];
    if (wp[i] > W) wp[i] = W;
  }
  // adjust edges according to visiblity:
  for (i = children(); i > selected; i--) {
    p[i] = p[i-1]+wp[i-1];
  }
  return selected;
}

// return space needed for tabs.  Negative to put them on the bottom:
int Fl_Tabs::tab_height() {
  int H = h();
  int H2 = y();
  Fl_Widget*const* a = array();
  if (tab_height_ > -1) return tab_height_;
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (o->y() < y()+H) H = o->y()-y();
    if (o->y()+o->h() > H2) H2 = o->y()+o->h();
  }
  H2 = y()+h()-H2;
  if (H2 > H) return (H2 <= 0) ? 0 : -H2;
  else return (H <= 0) ? 0 : H;
}

void Fl_Tabs::tab_height(int h) {
  tab_height_ = h;
}

// this is used by fluid to pick tabs:
Fl_Widget *Fl_Tabs::which(int event_x, int event_y) {
  int H = tab_height();
  if (H < 0) {
    if (event_y > y()+h() || event_y < y()+h()+H) return 0;
  } else {
    if (event_y > y()+H || event_y < y()) return 0;
  }
  if (event_x < x()) return 0;
  int p[128], wp[128];
  tab_positions(p, wp);
  for (int i=0; i<children(); i++) {
    if (event_x < x()+p[i+1]) return child(i);
  }
  return 0;
}

int Fl_Tabs::handle(int event) {

  Fl_Widget *o;
  int i;

  switch (event) {

  case FL_PUSH: {
    int H = tab_height();
    if (H >= 0) {
      if (Fl::event_y() > y()+H) return Fl_Group::handle(event);
    } else {
      if (Fl::event_y() < y()+h()+H) return Fl_Group::handle(event);
    }}
  case FL_DRAG:
  case FL_RELEASE:
    o = which(Fl::event_x(), Fl::event_y());
    if (event == FL_RELEASE) {
      push(0);
      if (o && value(o)) {
        set_changed();
	do_callback();
      }
    } else push(o);
    if (Fl::visible_focus() && event == FL_RELEASE) Fl::focus(this);
    return 1;
  case FL_FOCUS:
  case FL_UNFOCUS:
    if (!Fl::visible_focus()) return Fl_Group::handle(event);
    if (Fl::event() == FL_RELEASE ||
	Fl::event() == FL_SHORTCUT ||
	Fl::event() == FL_KEYBOARD) {
      int H = tab_height();
      if (H >= 0) {
        H += Fl::box_dy(box());
	damage(FL_DAMAGE_SCROLL, x(), y(), w(), H);
      } else {
        H = Fl::box_dy(box()) - H;
        damage(FL_DAMAGE_SCROLL, x(), y() + h() - H, w(), H);
      }
      return 1;
    } else return Fl_Group::handle(event);
  case FL_KEYBOARD:
    switch (Fl::event_key()) {
      case FL_Left:
        if (child(0)->visible()) return 0;
	for (i = 1; i < children(); i ++)
	  if (child(i)->visible()) break;
	value(child(i - 1));
	set_changed();
	do_callback();
        return 1;
      case FL_Right:
        if (child(children() - 1)->visible()) return 0;
	for (i = 0; i < children(); i ++)
	  if (child(i)->visible()) break;
	value(child(i + 1));
	set_changed();
	do_callback();
        return 1;
      case FL_Down:
        redraw();
        return Fl_Group::handle(FL_FOCUS);
      default:
        break;
    }
  default:
    return Fl_Group::handle(event);

  }
}

int Fl_Tabs::push(Fl_Widget *o) {
  if (push_ == o) return 0;
  if (push_ && !push_->visible() || o && !o->visible())
    redraw();
  push_ = o;
  return 1;
}

// The value() is the first visible child (or the last child if none
// are visible) and this also hides any other children.
// This allows the tabs to be deleted, moved to other groups, and
// show()/hide() called without it screwing up.
Fl_Widget* Fl_Tabs::value() {
  Fl_Widget* v = 0;
  Fl_Widget*const* a = array();
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (v) o->hide();
    else if (o->visible()) v = o;
    else if (!i) {o->show(); v = o;}
  }
  return v;
}

// Setting the value hides all other children, and makes this one
// visible, iff it is really a child:
int Fl_Tabs::value(Fl_Widget *newvalue) {
  Fl_Widget*const* a = array();
  int ret = 0;
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (o == newvalue) {
      if (!o->visible()) ret = 1;
      o->show();
    } else {
      o->hide();
    }
  }
  return ret;
}

enum {LEFT, RIGHT, SELECTED};

void Fl_Tabs::draw() {
  Fl_Widget *v = value();
  int H = tab_height();

  if (damage() & FL_DAMAGE_ALL) { // redraw the entire thing:
    draw_box(box(), x(), y()+(H>=0?H:0), w(), h()-(H>=0?H:-H), v ? v->color() : color());
    if (v) draw_child(*v);
  } else { // redraw the child
    if (v) update_child(*v);
  }
  if (damage() & (FL_DAMAGE_SCROLL|FL_DAMAGE_ALL)) {
    int p[128]; int wp[128];
    int selected = tab_positions(p,wp);
    int i;
    Fl_Widget*const* a = array();
    for (i=0; i<selected; i++)
      draw_tab(x()+p[i], x()+p[i+1], wp[i], H, a[i], LEFT);
    for (i=children()-1; i > selected; i--)
      draw_tab(x()+p[i], x()+p[i+1], wp[i], H, a[i], RIGHT);
    if (v) {
      i = selected;
      draw_tab(x()+p[i], x()+p[i+1], wp[i], H, a[i], SELECTED);
    }
  }
}

void Fl_Tabs::draw_tab(int x1, int x2, int W, int H, Fl_Widget* o, int what) {
  int sel = (what == SELECTED);
  int dh = Fl::box_dh(box());
  int dy = Fl::box_dy(box());

  if ((x2 < x1+W) && what == RIGHT) x1 = x2 - W;

  if (H >= 0) {
    if (sel) fl_clip(x1, y(), x2 - x1, H + dh - dy);
    else fl_clip(x1, y(), x2 - x1, H);

    H += dh;

    draw_box(box(), x1, y(), W, H,
             sel ? fl_color_average(selection_color(), o->selection_color(), 0.5f)
	         : o->selection_color());

    o->draw_label(x1, y(), W, H, FL_ALIGN_CENTER);

    if (Fl::focus() == this && o->visible())
      draw_focus(box(), x1, y(), W, H);

    fl_pop_clip();
  } else {
    H = -H;

    if (sel) fl_clip(x1, y() + h() - H - dy, x2 - x1, H + dy);
    else fl_clip(x1, y() + h() - H, x2 - x1, H);

    H += dh;

    draw_box(box(), x1, y() + h() - H, W, H,
             sel ? fl_color_average(selection_color(), o->selection_color(), 0.5f)
	         : o->selection_color());

    o->draw_label(x1, y() + h() - H, W, H, FL_ALIGN_CENTER);

    if (Fl::focus() == this && o->visible())
      draw_focus(box(), x1, y() + h() - H, W, H);

    fl_pop_clip();
  }
}

Fl_Tabs::Fl_Tabs(int X,int Y,int W, int H, const char *l) :
  Fl_Group(X,Y,W,H,l)
{
  box(FL_THIN_UP_BOX);
  push_ = 0;
  tab_height_ = -1;
}

//
// End of "$Id: Fl_Tabs.cxx,v 1.6.2.10.2.20 2004/07/27 16:02:21 easysw Exp $".
//

// generated by Fast Light User Interface Designer (fluid) version 1.0100

#include "keyboard_ui.h"

MyWindow *my_window=(MyWindow *)0;

Fl_Output *key_output=(Fl_Output *)0;

Fl_Output *text_output=(Fl_Output *)0;

Fl_Dial *roller_x=(Fl_Dial *)0;

Fl_Dial *roller_y=(Fl_Dial *)0;

MyWindow* make_window() {
  MyWindow* w;
  { MyWindow* o = my_window = new MyWindow(494, 203);
    w = o;
    { Fl_Button* o = new Fl_Button(15, 60, 20, 20, "Esc ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Escape));
    }
    { Fl_Button* o = new Fl_Button(50, 60, 20, 20, "F1");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+1));
    }
    { Fl_Button* o = new Fl_Button(70, 60, 20, 20, "F2");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+2));
    }
    { Fl_Button* o = new Fl_Button(90, 60, 20, 20, "F3");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+3));
    }
    { Fl_Button* o = new Fl_Button(110, 60, 20, 20, "F4");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+4));
    }
    { Fl_Button* o = new Fl_Button(140, 60, 20, 20, "F5");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+5));
    }
    { Fl_Button* o = new Fl_Button(160, 60, 20, 20, "F6");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+6));
    }
    { Fl_Button* o = new Fl_Button(180, 60, 20, 20, "F7");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+7));
    }
    { Fl_Button* o = new Fl_Button(200, 60, 20, 20, "F8");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+8));
    }
    { Fl_Button* o = new Fl_Button(230, 60, 20, 20, "F9");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+9));
    }
    { Fl_Button* o = new Fl_Button(250, 60, 20, 20, "F10");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+10));
    }
    { Fl_Button* o = new Fl_Button(270, 60, 20, 20, "F11");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+11));
    }
    { Fl_Button* o = new Fl_Button(290, 60, 20, 20, "F12");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_F+12));
    }
    { Fl_Button* o = new Fl_Button(325, 60, 20, 20, "Print ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Print));
    }
    { Fl_Button* o = new Fl_Button(345, 60, 20, 20, "Sclk ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Scroll_Lock));
    }
    { Fl_Button* o = new Fl_Button(365, 60, 20, 20, "Paus ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Pause));
    }
    { Fl_Button* o = new Fl_Button(15, 90, 20, 20, "`");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(35, 90, 20, 20, "1");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(55, 90, 20, 20, "2");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(75, 90, 20, 20, "3");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(95, 90, 20, 20, "4");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(115, 90, 20, 20, "5");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(135, 90, 20, 20, "6");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(155, 90, 20, 20, "7");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(175, 90, 20, 20, "8");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(195, 90, 20, 20, "9");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(215, 90, 20, 20, "0");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(235, 90, 20, 20, "-");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(255, 90, 20, 20, "=");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(275, 90, 35, 20, "Bksp");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_BackSpace));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(325, 90, 20, 20, "Ins ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Insert));
    }
    { Fl_Button* o = new Fl_Button(345, 90, 20, 20, "Home");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Home));
    }
    { Fl_Button* o = new Fl_Button(365, 90, 20, 20, "pgup ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Page_Up));
    }
    { Fl_Button* o = new Fl_Button(400, 90, 20, 20, "Num");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Num_Lock));
    }
    { Fl_Button* o = new Fl_Button(420, 90, 20, 20, "/");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'/'));
    }
    { Fl_Button* o = new Fl_Button(440, 90, 20, 20, "*");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'*'));
    }
    { Fl_Button* o = new Fl_Button(460, 90, 20, 20, "-");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'-'));
    }
    { Fl_Button* o = new Fl_Button(15, 110, 27, 20, "Tab");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Tab));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(42, 110, 20, 20, "Q");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(62, 110, 20, 20, "W");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(82, 110, 20, 20, "E");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(102, 110, 20, 20, "R");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(122, 110, 20, 20, "T");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(142, 110, 20, 20, "Y");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(162, 110, 20, 20, "U");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(182, 110, 20, 20, "I");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(202, 110, 20, 20, "O");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(222, 110, 20, 20, "P");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(242, 110, 20, 20, "[");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(262, 110, 20, 20, "]");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(282, 110, 28, 20, "\\");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)('|'));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(325, 110, 20, 20, "Del ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Delete));
    }
    { Fl_Button* o = new Fl_Button(345, 110, 20, 20, "End ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_End));
    }
    { Fl_Button* o = new Fl_Button(365, 110, 20, 20, "pgdn ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Page_Down));
    }
    { Fl_Button* o = new Fl_Button(400, 110, 20, 20, "7");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'7'));
    }
    { Fl_Button* o = new Fl_Button(420, 110, 20, 20, "8");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'8'));
    }
    { Fl_Button* o = new Fl_Button(440, 110, 20, 20, "9");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'9'));
    }
    { Fl_Button* o = new Fl_Button(460, 110, 20, 40, "+");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'+'));
      o->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(15, 130, 36, 20, "Lock");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Caps_Lock));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(51, 130, 20, 20, "A");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(71, 130, 20, 20, "S");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(91, 130, 20, 20, "D");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(111, 130, 20, 20, "F");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(131, 130, 20, 20, "G");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(151, 130, 20, 20, "H");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(171, 130, 20, 20, "J");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(191, 130, 20, 20, "K");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(211, 130, 20, 20, "L");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(231, 130, 20, 20, ";");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(251, 130, 20, 20, "\'");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(271, 130, 39, 20, "Enter");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Enter));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(400, 130, 20, 20, "4");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'4'));
    }
    { Fl_Button* o = new Fl_Button(420, 130, 20, 20, "5");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'5'));
    }
    { Fl_Button* o = new Fl_Button(440, 130, 20, 20, "6");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'6'));
    }
    { Fl_Button* o = new Fl_Button(15, 150, 45, 20, "Shift");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Shift_L));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(60, 150, 20, 20, "Z");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(80, 150, 20, 20, "X");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(100, 150, 20, 20, "C");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(120, 150, 20, 20, "V");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(140, 150, 20, 20, "B");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(160, 150, 20, 20, "N");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(180, 150, 20, 20, "M");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(200, 150, 20, 20, ",");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(220, 150, 20, 20, ".");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(240, 150, 20, 20, "/");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb);
    }
    { Fl_Button* o = new Fl_Button(260, 150, 50, 20, "Shift");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Shift_R));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(345, 150, 20, 20, "@8->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(47);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Up));
    }
    { Fl_Button* o = new Fl_Button(400, 150, 20, 20, "1");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'1'));
    }
    { Fl_Button* o = new Fl_Button(420, 150, 20, 20, "2");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'2'));
    }
    { Fl_Button* o = new Fl_Button(440, 150, 20, 20, "3");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'3'));
    }
    { Fl_Button* o = new Fl_Button(460, 150, 20, 40);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP_Enter));
    }
    { Fl_Button* o = new Fl_Button(15, 170, 30, 20, "Ctrl");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Control_L));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(45, 170, 30, 20, "Meta ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Meta_L));
    }
    { Fl_Button* o = new Fl_Button(75, 170, 30, 20, "Alt ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Alt_L));
    }
    { Fl_Button* o = new Fl_Button(105, 170, 85, 20);
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(' '));
    }
    { Fl_Button* o = new Fl_Button(190, 170, 30, 20, "Alt ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Alt_R));
    }
    { Fl_Button* o = new Fl_Button(220, 170, 30, 20, "Meta ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Meta_R));
    }
    { Fl_Button* o = new Fl_Button(250, 170, 30, 20, "Menu ");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Menu));
    }
    { Fl_Button* o = new Fl_Button(280, 170, 30, 20, "Ctrl");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Control_R));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(325, 170, 20, 20, "@4->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(47);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Left));
    }
    { Fl_Button* o = new Fl_Button(345, 170, 20, 20, "@2->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(47);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Down));
    }
    { Fl_Button* o = new Fl_Button(365, 170, 20, 20, "@6->");
      o->labeltype(FL_SHADOW_LABEL);
      o->labelsize(10);
      o->labelcolor(47);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Right));
    }
    { Fl_Button* o = new Fl_Button(400, 170, 40, 20, "0");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'0'));
      o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
    { Fl_Button* o = new Fl_Button(440, 170, 20, 20, ".");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'.'));
    }
    { Fl_Button* o = new Fl_Button(400, 10, 20, 10, "shift ");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_SHIFT));
    }
    { Fl_Button* o = new Fl_Button(420, 10, 20, 10, "lock ");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_CAPS_LOCK));
    }
    { Fl_Button* o = new Fl_Button(440, 10, 20, 10, "ctrl");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_CTRL));
    }
    { Fl_Button* o = new Fl_Button(460, 10, 20, 10, "alt");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_ALT));
    }
    { Fl_Button* o = new Fl_Button(400, 20, 20, 10, "num");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_NUM_LOCK));
    }
    { Fl_Button* o = new Fl_Button(420, 20, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x20));
    }
    { Fl_Button* o = new Fl_Button(440, 20, 20, 10, "meta ");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_META));
    }
    { Fl_Button* o = new Fl_Button(460, 20, 20, 10, "sclk");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_SCROLL_LOCK));
    }
    { Fl_Button* o = new Fl_Button(400, 30, 20, 10, "b1");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON1));
    }
    { Fl_Button* o = new Fl_Button(420, 30, 20, 10, "b2");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON2));
    }
    { Fl_Button* o = new Fl_Button(440, 30, 20, 10, "b3");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(FL_BUTTON3));
    }
    { Fl_Button* o = new Fl_Button(460, 30, 20, 10, "whl");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x800));
    }
    { Fl_Button* o = new Fl_Button(400, 40, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x1000));
    }
    { Fl_Button* o = new Fl_Button(420, 40, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x2000));
    }
    { Fl_Button* o = new Fl_Button(440, 40, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x4000));
    }
    { Fl_Button* o = new Fl_Button(460, 40, 20, 10, "?");
      o->box(FL_THIN_UP_BOX);
      o->selection_color(3);
      o->labelsize(8);
      o->callback((Fl_Callback*)shift_cb, (void*)(0x8000));
    }
    { Fl_Output* o = key_output = new Fl_Output(15, 15, 170, 30, "Fl::event_key():");
      o->labelsize(8);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Box* o = new Fl_Box(395, 10, 85, 40, "Fl::event_state():");
      o->labelsize(8);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Output* o = text_output = new Fl_Output(195, 15, 190, 30, "Fl::event_text():");
      o->labelsize(8);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Button* o = new Fl_Button(400, 60, 20, 20, "help");
      o->labelsize(8);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_Help));
    }
    { Fl_Button* o = new Fl_Button(420, 60, 20, 20, "=");
      o->labelsize(10);
      o->callback((Fl_Callback*)key_cb, (void*)(FL_KP+'='));
    }
    { Fl_Dial* o = roller_x = new Fl_Dial(440, 60, 20, 20, "x:");
      o->box(FL_ROUND_UP_BOX);
      o->selection_color(49);
      o->labelsize(9);
      o->step(0.1);
      o->callback((Fl_Callback*)wheel_cb);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Dial* o = roller_y = new Fl_Dial(460, 60, 20, 20, "y:");
      o->box(FL_ROUND_UP_BOX);
      o->selection_color(49);
      o->labelsize(9);
      o->step(0.1);
      o->callback((Fl_Callback*)wheel_cb);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    o->end();
  }
  return w;
}

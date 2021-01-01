#pragma once

#include "glibmm/ustring.h"
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include <vector>

class Calculator : public Gtk::Window {
    public:
        Calculator();
        virtual ~Calculator();
        void btn_rightclick_test();
    
    protected:
        // Signal handlers
        void on_button_clicked(Glib::ustring data);
        void btn_append_text(Glib::ustring data);
        void tu_was(Glib::ustring a, Glib::ustring b);

        // Child Widgets
        Gtk::Box m_main_box;
        Gtk::Grid m_grid;

        std::vector<Gtk::Button> m_VecButton;

        Gtk::Button m_button;
        Gtk::Label m_label;

        Glib::ustring m_label_text;
};

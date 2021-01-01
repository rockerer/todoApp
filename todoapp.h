#pragma once

#include "gtkmm/hvbox.h"
#include "gtkmm/menu.h"
#include "gtkmm/menubar.h"
#include "gtkmm/menuitem.h"
#include <gtkmm.h>


class TodoApp : public Gtk::Window {
    public:
        TodoApp();
        virtual ~TodoApp();

        void btn_clicked();
        bool on_timer();


    protected:
        // ======================
        // main application stuff
        // ======================

        Gtk::VBox mainLayout;

        Gtk::Button m_btn_exit;

        // ======================
        // Menu related stuff
        // ======================
        Gtk::MenuBar menuBar;
        Gtk::MenuItem menuFile;
        Gtk::Menu subMenuFile;
        Gtk::MenuItem menuFileOpen, menuFileClose;

        Gtk::MenuItem menuTodo;
        Gtk::Menu subMenuTodo;
        Gtk::MenuItem menuTodoAdd, menuTodoDelete;

        // ======================
        // Functions
        // ======================
        void quit();

};

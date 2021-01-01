#include "todoapp.h"
#include "gio/gmenu.h"
#include "glibmm/main.h"
#include "gtkmm/box.h"
#include "sigc++/functors/mem_fun.h"
#include <functional>
#include <iostream>
#include <chrono>
#include "gtkmm/application.h"
#include "glibmm.h"
#include "sigc++/functors/ptr_fun.h"

TodoApp::TodoApp() :
    m_btn_exit("Huhu!!!")
{
    // set up the application window
    set_title("Todo-Application");
    set_border_width(10);
    set_default_size(600, 800);

    // add the main layout
    // needed for menu and body
    add(mainLayout);

    // build menu
    mainLayout.pack_start(menuBar, Gtk::PackOptions::PACK_SHRINK);

    // append submenu file
    menuFile.set_label("File");
    menuFile.set_submenu(subMenuFile);
    menuBar.append(menuFile);

    menuFileOpen.set_label("Open");
    menuFileOpen.signal_activate().connect( [] {
            std::cout << "Open\n";});
    subMenuFile.append(menuFileOpen);

    menuFileClose.set_label("Close");
    menuFileClose.signal_activate().connect(
//            sigc::ptr_fun(&Gtk::Main::quit));
            sigc::mem_fun(*this, &TodoApp::quit));
    subMenuFile.append(menuFileClose);

    menuBar.show_all();

    m_btn_exit.signal_clicked().connect([] {
            std::cout << "Hello, i was clicked\n";
                });
    mainLayout.pack_end(m_btn_exit);
    m_btn_exit.show();

    mainLayout.show();
    show();
}

TodoApp::~TodoApp() {
}

void TodoApp::btn_clicked() {
    std::cout << "Button was clicked\n";
}

bool TodoApp::on_timer() {
    std::cout << "Zeit\n";
    return true;
}

void TodoApp::quit() {
    std::cout << "Ich bin dann mal raus\n";
//    this->close();
    this->close();
}

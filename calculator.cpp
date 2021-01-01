#include "calculator.h"
#include "glibmm/ustring.h"
#include "sigc++/adaptors/bind.h"
#include "sigc++/functors/mem_fun.h"
#include "sigc++/functors/ptr_fun.h"
#include <iostream>
#include <string>

Calculator::Calculator()
{
    // Set title
    set_title("Calculator in Progress");

    // Set border width
    set_border_width(10);

    // add box container
    m_main_box.set_orientation(Gtk::Orientation::ORIENTATION_VERTICAL);
    add(m_main_box);
    // add(m_grid);

    // add label
    m_label = Gtk::Label(m_label_text);
    m_label.show();
    m_main_box.pack_start(m_label);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m_VecButton.emplace_back(std::to_string(1 + j + 3 * i));
            m_VecButton.back().signal_clicked().connect(
                    sigc::bind<Glib::ustring>(
                        sigc::mem_fun(*this, &Calculator::btn_append_text),
                        std::to_string(1 + j + 3 * i)));

            m_grid.attach(m_VecButton.back(), j, i);

            m_VecButton.back().set_hexpand();
            m_VecButton.back().set_vexpand();
            m_VecButton.back().show();
        }
    }

    m_VecButton.emplace_back("+");
    /*
       m_VecButton.back().signal_clicked().connect(
       sigc::bind<Glib::ustring>(
       sigc::mem_fun(*this, &Calculator::on_button_clicked), "+"));
       m_VecButton.back().signal_clicked().connect(
       sigc::bind<Glib::ustring>(
       sigc::mem_fun(*this, &Calculator::btn_append_text), "+"));
       */

//       m_VecButton.back().signal_clicked().connect(
//            sigc::mem_fun(*this, &Calculator::btn_rightclick_test));
    
    // i need to run sigc::mem_fun, if i use a function inside a class
    // and ptr_fun if i use a function outside of a class
    m_VecButton.back().signal_clicked().connect(
            sigc::mem_fun(*this,
                &Calculator::btn_rightclick_test));

    // g_signal_connect(m_VecButton.back(), "button-press-event",
    //     G_CALLBACK(Calculator::btn_rightclick_test), NULL);

    m_grid.attach(m_VecButton.back(), 3, 0, 1, 2);

    m_VecButton.back().set_hexpand();
    m_VecButton.back().set_vexpand();
    m_VecButton.back().show();
    
    m_VecButton.emplace_back("Blaaa");
    m_VecButton.back().signal_clicked().connect(
            sigc::bind<Glib::ustring, Glib::ustring>(
            sigc::mem_fun(*this, &Calculator::tu_was), "la", "bbbb"));
    /*
    m_VecButton.back().signal_clicked().connect(
            sigc::bind<Glib::ustring, Glib::ustring>(
                sigc::mem_fun(*this, &Calculator::tu_was), "aaaaa", "bbbbb"));
    */

    m_VecButton.back().show();
    m_grid.attach(m_VecButton.back(), 8,8,2,2);

    m_grid.set_hexpand(false);
    m_grid.set_halign(Gtk::ALIGN_FILL);
    m_grid.set_vexpand(false);
    // m_grid.set_valign(Gtk::ALIGN_FILL);
    m_grid.show();
    m_main_box.pack_end(m_grid);

    m_button = Gtk::Button("Ich bin ein Knopf!");
    m_button.show();
    m_main_box.pack_end(m_button);

    m_main_box.show();

    for (const auto &x : m_main_box.get_children())
    {
        std::cout << x->get_name() << "\n";
    }
    // m_grid.show();
}

Calculator::~Calculator()
{
}

void Calculator::on_button_clicked(Glib::ustring data)
{
    std::cout << "Button " << data << " was pressed\n";
}

void Calculator::tu_was(Glib::ustring a , Glib::ustring b) {
    std::cout << a << ", " << b << "\n";
}

void Calculator::btn_append_text(Glib::ustring data)
{
    std::cout << "Button was pressed: " << data << "\n";
    this->m_label_text.append(data);
    std::cout << "Content: " << this->m_label_text;
    this->m_label.set_text(this->m_label_text);
}

void Calculator::btn_rightclick_test() {
    std::cout << this->m_label_text;
    std::cout << "hmpf\n";
}

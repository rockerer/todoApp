#include "todoapp.h"
#include <gtkmm/application.h>

int main(int argc, char **argv) {

    auto app = Gtk::Application::create(argc, argv, "org.rockerer.example");
    TodoApp todoApp;
    return app->run(todoApp);
}

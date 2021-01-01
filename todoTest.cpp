#include "todo.h"
#include "todoentry.h"
#include <iostream>

int main() {
    Todo t;
    std::cout << t.getCount() << "\n";
    TodoEntry te;
    te.setName("Horst").setProgress(10)
        .setDetails("HungaBunga").setProgress(-1).setProgress(10);
    t.insertTodo(std::move(te));
    t.insertTodo(std::move(TodoEntry().setName("Walther").setProgress(50)));
    std::cout << t.getCount() << "\n";
    if(auto x = t.getTodo(0)) {
        std::cout << x->getName() << "\n";
    }
    if(auto x = t.getTodo(1)) {
        std::cout << x->getName() << "\n";
    }
    t.updateTodo(1, TodoEntry(t.getTodo(1).value()).setName("Florian"));
    if(auto x = t.getTodo(1)) {
        std::cout << x->getName() << "\n";
    }
    std::cout << te;
    te.setName("asdiushadfioahsdf").setDetails("huhuhuhuh");
    std::cout << te;
    t.insertTodo(std::move(te));
    te.setProgress(-1);
    std::cout << te;
}

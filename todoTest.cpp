#include "todo.h"
#include "todoentry.h"
#include <iostream>
#include <optional>
#include <utility>

int TodoEntry::created = 0;
int TodoEntry::copied = 0;
int TodoEntry::moved = 0;

int main() {

    Todo t;
    std::cout << t.getCount() << "\n";
    std::cout << "==========\n";

    TodoEntry te;
    te.setDetails("SECRET").setProgress(10)
        .setName("Some Name1").setProgress(-1).setProgress(10);
    std::cout << "==========\n";
    te.setProgress(100);

    t.insertTodo(std::move(te));

    std::cout << "==========\n";
    TodoEntry te1;
    te1.setName("Some Oather Name 1").setProgress(100).setDetails("Ich bin geheim!");
    t.insertTodo(std::move(te1));
    std::cout << "==========\n";

    if( auto x = t.getTodo(1)) {
        t.updateTodo(1,x.value().setName("Other Name 1").setProgress(50));
        t.insertTodo(TodoEntry().setName("Some Name 1").setDetails("Koch"));
    }

    std::cout << "==========\n";

    std::cout << t.getCount() << "\n";
    t.printAll();


    std::cout << "==========\n";
    std::cout << "Created: " << TodoEntry::created << "\n";
    std::cout << "Copied: " << TodoEntry::copied << "\n";
    std::cout << "Moved: " << TodoEntry::moved << "\n";
}

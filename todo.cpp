#include "todo.h"
#include <list>
#include <optional>
#include <iostream>

Todo::Todo() {
//    std::cout << "New TodoList created\n";
}

Todo::~Todo() {
//    std::cout << "TodoList destroyed\n";
}

// check, if this makes problems with 
// loosing the original object
void Todo::insertTodo(TodoEntry && todoEntry){
    this->m_vec_todo.push_back(std::move(todoEntry));
}

std::optional<const TodoEntry> Todo::getTodo(int index){
    if(index < static_cast<int>(this->m_vec_todo.size())) {
        return this->m_vec_todo.at(index);
    }
    return std::nullopt;
}

void Todo::updateTodo(int index, TodoEntry newTodoEntry){
    if(index < static_cast<int>(this->m_vec_todo.size())) {
        this->deleteTodo(index);
        this->m_vec_todo.insert(this->m_vec_todo.begin() + index, newTodoEntry);
    }
}
void Todo::deleteTodo(int index){
    if(index < static_cast<int>(this->m_vec_todo.size())) {
        this->m_vec_todo.erase(
                this->m_vec_todo.begin() +  index);
    }
}

int Todo::getCount() {
    return this->m_vec_todo.size();
}

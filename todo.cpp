#include "todo.h"
#include "todoentry.h"
#include <list>
#include <optional>
#include <iostream>
#include <utility>

Todo::Todo() {
//    std::cout << "New TodoList created\n";
    this->m_vec_todo.reserve(10);
}

Todo::~Todo() {
//    std::cout << "TodoList destroyed\n";
}

// check, if this makes problems with 
// loosing the original object
void Todo::insertTodo(TodoEntry &&todoEntry){
    this->m_vec_todo.push_back(
            std::forward<TodoEntry>(todoEntry)
    );
}

std::optional<TodoEntry> Todo::getTodo(int index){
    if(index >= 0 && index < static_cast<int>(this->m_vec_todo.size())) {
        return std::optional(this->m_vec_todo.at(index));
    }
    return std::nullopt;
}

void Todo::updateTodo(int index, TodoEntry &&newTodoEntry){
    if(index >= 0 && index < static_cast<int>(this->m_vec_todo.size())) {
        this->deleteTodo(index);
        this->m_vec_todo.emplace(
               this->m_vec_todo.begin() + index, std::forward<TodoEntry>(newTodoEntry));
        /*
        this->m_vec_todo.insert(this->m_vec_todo.begin() + index, newTodoEntry);
        */
    }
}
void Todo::deleteTodo(int index){
    if(index >= 0 && index < static_cast<int>(this->m_vec_todo.size())) {
        this->m_vec_todo.erase(
                this->m_vec_todo.begin() +  index);
    }
}

int Todo::getCount() {
    return this->m_vec_todo.size();
}

void Todo::printAll() {
    for(auto &x: m_vec_todo) {
        std::cout << x << "\n";
    }
}

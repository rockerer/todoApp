#pragma once

#include "todoentry.h"
#include <string>
#include <vector>
#include <optional>

class Todo{
    public:
        Todo();
        virtual ~Todo();

        void insertTodo(TodoEntry &&);
        std::optional<TodoEntry> getTodo(int);
        void updateTodo(int, TodoEntry &&);
        void deleteTodo(int);

        int getCount();

        void printAll();

        // ggf. noch search
        // aber das kommt spaeter

    protected:
        std::vector<TodoEntry> m_vec_todo;
};

#pragma once

#include <iostream>
#include <string>
class TodoEntry {
    public:
        // Contructors
        TodoEntry();
        TodoEntry(const TodoEntry &);
        TodoEntry(TodoEntry &&);
        // assignment operators
        TodoEntry & operator=(const TodoEntry &);
        TodoEntry & operator=(TodoEntry &&);
        virtual ~TodoEntry();

        // getters
        int getProgress() const;
        std::string getName() const;
        std::string getDetails() const;

        TodoEntry & setProgress(int);
        TodoEntry & setName(std::string);
        TodoEntry & setDetails(std::string);

        friend std::ostream & operator<<(std::ostream &os, const TodoEntry & te);

    protected:
        std::string m_Name;
        int m_progress;
        std::string m_details;
};

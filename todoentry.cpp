#include "todoentry.h"
#include <cstdlib>
#include <iostream>
#include <utility>

TodoEntry::TodoEntry() :
    m_Name("John Doe"),
    m_progress(0),
    m_details("Details")
{
    created++;
}

TodoEntry::TodoEntry(const TodoEntry & todoEntry) :
    m_Name(     std::move(todoEntry.m_Name)),
    m_progress( std::move(todoEntry.m_progress)),
    m_details(  std::move(todoEntry.m_details))
{
    copied++;
}

TodoEntry::TodoEntry(TodoEntry &&rhs) :
    m_Name(     std::move(rhs.m_Name)),
    m_progress( std::move(rhs.m_progress)),
    m_details(  std::move(rhs.m_details))
{
    rhs.m_progress = 0;
    moved++;
}

TodoEntry & TodoEntry::operator=(const TodoEntry &rhs) {
    this->m_Name = rhs.m_Name;
    this->m_details = rhs.m_details;
    this->m_progress = rhs.m_progress;
    return * this;
}

TodoEntry & TodoEntry::operator=(TodoEntry && rhs) {
    this->m_Name = std::move(rhs.m_Name);
    this->m_progress = std::move(rhs.m_progress);
    this->m_details = std::move(rhs.m_details);

    rhs.m_progress = 0;

    return * this;
}

TodoEntry::~TodoEntry(){
}

// getters
int TodoEntry::getProgress() const {
    return this->m_progress;
};

std::string TodoEntry::getName() const {
    return this->m_Name;
};

std::string TodoEntry::getDetails() const {
    return this->m_details;
}

// setters
TodoEntry && TodoEntry::setProgress(int progress){
    this->m_progress = progress;
    return std::move(* this);
}

TodoEntry && TodoEntry::setName(std::string name){
    this->m_Name = name;
    return std::move(* this);
}

TodoEntry && TodoEntry::setDetails(std::string details){
    this->m_details = details;
    return std::move(* this);
}

std::ostream & operator<<(std::ostream &os, const TodoEntry & te) {
            os << "Name: " << te.m_Name << "\nProgress: " << te.m_progress 
                << "\nDetails: " << te.m_details << "\n";
            return os;
        }

#include "../include/task.h"

int Task::nextId = 1;

Task::Task(std::string& desc)
    :id(nextId), description(std::move(desc)), isCompleted(false){
    nextId++;
}

auto Task::getId() const -> int{
    return this->id;
}

auto Task::getIsCompleted() const -> bool {
    return this->isCompleted;
}

auto Task::getDescription() const -> std::string{
    return this->description;
}

void Task::toggleCompleted(){
    isCompleted = !isCompleted;
}

auto Task::toString() const -> std::string{
    std::stringstream sstr;

    sstr << "[" << id << "] " << description;

    if (isCompleted) {
        sstr<<" \t\t[FINISHED]";
    } else {
        sstr<<" \t\t[UNFINISHED]";
    }

    return sstr.str();
}

auto Task::toFileString() const -> std::string{
    std::stringstream sstr;

    sstr<<id<<"|"<<description<<"|"<<(isCompleted ? "1" : "0");
    return sstr.str();
}

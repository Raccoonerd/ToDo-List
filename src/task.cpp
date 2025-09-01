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

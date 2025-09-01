#pragma once
#include "task.h"
#include <vector>
#include <iostream>

class TaskManager{
private:
    std::vector<Task> tasks;

public:
    TaskManager() = default;

    void add();
    void remove();

    void displayTasks() const;
};

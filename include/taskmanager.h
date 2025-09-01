#pragma once
#include "task.h"
#include <vector>
#include <iostream>
#include <algorithm>

class TaskManager{
private:
    std::vector<Task> tasks;

public:
    TaskManager() = default;

    void add();
    bool remove(int id);

    void displayTasks() const;
};

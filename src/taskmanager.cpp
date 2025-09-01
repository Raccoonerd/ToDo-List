#include "../include/taskmanager.h"


void TaskManager::add(){
    std::string dsc;
    std::cout<<"Enter Description:\n";
    std::getline(std::cin, dsc);
    tasks.emplace_back(dsc);
}

bool TaskManager::remove(int taskId){
    auto it = std::find_if(tasks.begin(), tasks.end(), 
                           [taskId](const Task& task){
                           return task.getId() == taskId;
                           });

    if (it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}

void TaskManager::toggleComplete(int taskId){
    auto it = std::find_if(tasks.begin(), tasks.end(),
                           [taskId](const Task& task){
                           return task.getId() == taskId;
                           });

    if (it != tasks.end()) {
        it->toggleCompleted();
    }
}

void TaskManager::displayTasks() const{
    for (const auto& task : tasks){
        std::cout<<task.toString()<<"\n";
    }
}

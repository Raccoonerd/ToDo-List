#include "../include/taskmanager.h"


void TaskManager::add(){
    std::string dsc;
    std::cout<<"Enter Description:\n";
    std::getline(std::cin, dsc);
    tasks.emplace_back(dsc);
}

void TaskManager::displayTasks() const{
    for (const auto& task : tasks){
        std::cout << task.getId() << " | " << task.getDescription() << "\n";
    }
}

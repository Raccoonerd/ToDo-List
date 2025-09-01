#include "../include/taskmanager.h"

int main(int argc, char* argv[]){
    TaskManager taskmgr;
    
    taskmgr.add();
    taskmgr.add();
    taskmgr.add();

    taskmgr.displayTasks();

    taskmgr.remove(2);

    std::cout<<"\n\n";

    taskmgr.displayTasks();

    return 0;

}

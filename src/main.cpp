#include "../include/taskmanager.h"

int main(int argc, char* argv[]){
    TaskManager taskmgr;
    
    taskmgr.add();
    taskmgr.add();

    taskmgr.displayTasks();

    return 0;

}

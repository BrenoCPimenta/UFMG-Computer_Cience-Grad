#include <iostream>
#include "Task.hpp"

int main(){

    int quantum;
    int processes;
    int id;
    int time_start;
    int time_end;
    std::vector<Task> tasks_vector;

    std::cin >> quantum >> processes;

    
    for(int i = 0; i<processes; i++){
        std::cin >> id >> time_start >> time_end; 
	
	Task* task_object = new Task(id, time_start, time_end);
	
	tasks_vector.push_back(*task_object);

	delete task_object;

    } 

    TaskScheduler* task_scheduler_object = new TaskScheduler(quantum, tasks_vector);
    task_scheduler_object-> processSchedule();
    task_scheduler_object-> printReport();
    delete task_scheduler_object;

    return 0;
}

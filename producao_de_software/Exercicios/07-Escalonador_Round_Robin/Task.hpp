#ifndef TASK_H
#define TASK_H

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>


struct Task{
	int id;
	int arrival;
	int duration;
	int end;
	Task(int,int,int);
};


struct TaskScheduler{
	int quantum;
	std::list<Task*> scheduler_queue;
	std::vector<Task> sorted_tasks_vector;
	
	TaskScheduler(int, std::vector<Task>);
	
	void processSchedule();
	void printReport();
};


#endif

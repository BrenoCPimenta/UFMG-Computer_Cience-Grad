#include "Task.hpp"

Task::Task(int _id, int _arrival, int _duration){
	id = _id;
	arrival = _arrival;
	duration = _duration;
	end = 0;
}

TaskScheduler::TaskScheduler(int _quantum, std::vector<Task> origin_tasks){
	this->quantum = _quantum;

	//Sort tasks by id
	Task aux_small_task(0,0,0);
	int small_task_index;
		
	while(origin_tasks.size() !=0){
		aux_small_task = origin_tasks[0];
		small_task_index = 0;

		for(int i = 0; i <origin_tasks.size(); i++){
			if(aux_small_task.id > origin_tasks[i].id){
		       		aux_small_task = origin_tasks[i];
				small_task_index = i;
			}
       		}		       
		this->sorted_tasks_vector.push_back(aux_small_task);
		origin_tasks.erase(origin_tasks.begin()+small_task_index);
	}
}

void TaskScheduler::processSchedule(){
	int cnt_final = 1;
	int quantum_cnt = -1;
	int time = -1;
	
	while(cnt_final != 0){
		time += 1;
		quantum_cnt += 1;
		
		//Adicionando tempo de execucao aos processos	
		for(int i = 0; i < sorted_tasks_vector.size(); i++){
			if(sorted_tasks_vector[i].duration != 0){
				sorted_tasks_vector[i].end+=1;
			}	
		}


		//Adicionando ao final da lista as tarefas no seus arrival moments
		for(int i = 0; i < sorted_tasks_vector.size(); i++){
			if(sorted_tasks_vector[i].arrival == time){
				scheduler_queue.push_back(&sorted_tasks_vector[i]);
			}
		}
		
		//Caso o processo acabe antes de completar o quantum
		if(scheduler_queue.front()->duration  == 0){			
			scheduler_queue.pop_front();
			quantum_cnt = 0;
		}
		

		//Caso o quantum complete o ciclo
		if(quantum_cnt == this->quantum){
			quantum_cnt = 0;

			if(scheduler_queue.front()->duration > 0){
				scheduler_queue.push_back(scheduler_queue.front());
			}
			scheduler_queue.pop_front();
		}
		
		//Verificando se todos os programas ja foram processados	
		cnt_final = 0;
		for(int i = 0; i < sorted_tasks_vector.size(); i++){
			if(sorted_tasks_vector[i].duration > 0){
				cnt_final+=1;
			}	
		}
		
		//Consumindo a duracao da tarefa em processamento
		if(scheduler_queue.size() != 0){
			scheduler_queue.front()->duration--;
		}

	}

}

void TaskScheduler::printReport(){
	for(int i = 0; i < sorted_tasks_vector.size(); i++){
		std::cout<< "Task " << sorted_tasks_vector[i].id 
			<<", Duration: [" << sorted_tasks_vector[i].arrival
			<<","<<sorted_tasks_vector[i].end<<"]"
		<< std::endl;
	}
}
	


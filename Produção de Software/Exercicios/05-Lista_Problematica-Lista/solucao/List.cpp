#include "List.hpp"

List::List(){
	this->size = 0;
	this->head = NULL;
}

void List::insert(int value){
    	Node* node = new Node;
	node->value = value;
	node->next = this->head;
	this->head = node;
	this->size++;
}

void List::clearList() {
	Node *last = this->head; //Soh para nao iniciar como nullptr
	Node *current = this->head;
	this->head = NULL;

	while(last != NULL){
		last = current->next;
		delete current;
		current = last;
	}
	this->size = 0;
}

void List::print(){
	Node* head = this->head;
	if (this->size > 0){
		while(head){
			std::cout << head->value << " ";
			head = head->next;
		}
		std::cout<<std::endl;
	}
	else{
	    std::cout<<"-"<<std::endl;
		return;
	}
}

int List::removeFirst(){
	Node* current = head;
	this->head = this->head->next;
	delete current;
	this->size--;
	return 1; 
}

int List::indexOf(int value){
	if (this->size > 0){
		Node* head = this->head;
		int index = 0;
		while(head && head->value != value){
			index++;
			head = head->next;
		}
		if (head->value == value)
			return index; 
		return -1;
	}
	else{
		return -1;
	}
}

void List::remove(int value){
	if(this->size == 0){
		return;
	}
	else if(this->head->value == value){
		Node* current = head;
		this->head = this->head->next;
		delete current;
		this->size--;
		return;
	}
	else{
		Node* previous = this->head;
		Node* current = head->next;
		while(current != NULL) {
			if(current->value == value) {
				break;
			}
			else {
				previous = current;
				current = current->next;
			}
		}
		if(current == NULL) {
			return;
		}
		else {
			this->size--;
			previous->next = current->next;
			delete current;
		}
	}
}

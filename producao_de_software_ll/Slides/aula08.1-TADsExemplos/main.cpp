#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include "Disciplina.hpp"

void createMap(std::string line, std::map<std::string, std::set<std::string>> *alocacao){
	std::stringstream parser(line);
	std::vector<std::string> parsedString;
	while(parser.good()){
		std::string substring;
		getline(parser, substring, ',');
		parsedString.push_back(substring);
	}
	if(alocacao->find(parsedString[0]) == alocacao->end()){
		std::set<std::string> s;
		s.insert(parsedString[2]);
		alocacao->insert({parsedString[0], s});
	}
	else{
		alocacao->at(parsedString[0]).insert(parsedString[2]);
	}
}

void printMap(std::map<std::string, std::set<std::string>> *alocacao){
	std::map<std::string, std::set<std::string>>::iterator it;
	for(it = alocacao->begin(); it != alocacao->end(); it++){
		std::cout<<it->first<<" Salas: ";
		for (std::string sala : it->second){
			std::cout<<sala<<", ";
		}
		std::cout<<std::endl;
	}
}

int main(){
	std::string line;
	std::map<std::string, std::set<std::string>> alocacao;
	std::ifstream disciplinas("disciplinas.csv");
	if(!disciplinas){
		std::cout<<"Failed"<<std::endl;
		exit(1);
	}
	while (std::getline(disciplinas, line)){
		createMap(line, &alocacao);
	}
	disciplinas.close();
	printMap(&alocacao);
	/*
	* Outras operações...
	*/
	return 0;
}
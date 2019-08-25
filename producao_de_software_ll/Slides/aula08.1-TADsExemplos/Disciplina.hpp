#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

struct Disciplina{
	std::string nome;
	std::string codigo;
	std::string local;
	Disciplina(std::string, std::string, std::string);
	/*
	* Outros atributos
	*/
};

#endif
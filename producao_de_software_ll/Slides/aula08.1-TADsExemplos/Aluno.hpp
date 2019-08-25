#ifndef ALUNO_H
#define ALUNO_H

#include <string>

struct Aluno{
	std::string nome;
	float nota;
	Aluno(std::string, float);
	/*
	* Outros atributos...
	*/
};

struct aluno_comparator_f{
	bool operator()(const Aluno &a1, const Aluno &a2) const{
		return a1.nota > a2.nota;
	}
};

#endif
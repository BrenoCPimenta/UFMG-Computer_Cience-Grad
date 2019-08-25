#ifndef MUSICA_H
#define MUSICA_H

#include <string>

struct Musica{
	std::string nome;
	std::string artista;
	std::string album;
	Musica(std::string, std::string, std::string);
	/*
	* Outros atributos...
	*/
};

#endif
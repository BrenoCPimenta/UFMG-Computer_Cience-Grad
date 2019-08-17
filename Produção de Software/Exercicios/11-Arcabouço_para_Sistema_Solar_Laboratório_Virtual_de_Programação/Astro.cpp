#include "Astro.hpp"

void Astro::fill(string nome,int temp,int raio,float g,string gas)
{	this->nome = nome;
	this->temp = temp;
	this->raio = raio;
	this->gravidade = g;
	this->gas = gas;
}

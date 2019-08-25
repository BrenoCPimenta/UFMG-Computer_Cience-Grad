#include "Controle.hpp"

void Controle::setCanal(int c){
	this->tv->setCanal(c);
}
void Controle::setVolume(int v){
	this->tv->setVolume(v);
}


void Controle::aumentaVolume(){
	int v = tv->getVolume();
	tv->setVolume(v+1);
}
void Controle::diminuiVolume(){
	int v = tv->getVolume();
	tv->setVolume(v-1);
}



void Controle::aumentaCanal(){
	int v = tv->getCanal();
	tv->setCanal(v+1);
}
void Controle::diminuiCanal(){
	int v = tv->getCanal();
	tv->setCanal(v-1);
}


Controle::Controle(Televisao *t){
	this->tv = t;
}

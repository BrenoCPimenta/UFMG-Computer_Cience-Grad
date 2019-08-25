#include "Televisao.hpp"


void Televisao::setCanal(int c){
	if(c>99){
		this->canal = 0;
	}else if(c<0){
		this->canal = 99;
	}else{
		this->canal = c;
	}
}

void Televisao::setVolume(int v){
	if(v<0){
	       this->volume = 0;
	}else if(v>20){
		this->volume = 20;
	}else{
		this->volume = v;
	}
}

int Televisao::getCanal(){
	return this->canal;
}

int Televisao::getVolume(){
	return this->volume;
}

/*OBS: O codigo a seguir depende do compilador:
 * Caso deh erro na compilacao favor descomenta-lo
 */ 
//Televisao::Televisao(){}

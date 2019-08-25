#include <iostream>
#include <sstream>
#include <string>

#include "Indice.hpp"

int main(){
	std::string text = "";
	std::string aux;
	
	std::cout << "Por favor entre com o texto: " << std::endl;
	while(getline(std::cin, aux)){
	    if(aux=="") break;
	    if(aux[0] != ' ') aux = ' '+aux;
	    text += aux;
	}
	
	if(text == ""){
	    std::cout << "Entradas nulas não são válidas." << std::endl;
	    return 0;
	}

	Indice* indice_object = new Indice(text);

	indice_object->printBigWordsData();

	delete indice_object;


	return 0;
}

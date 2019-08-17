#include <iostream>
#include <string>

#include "Televisao.hpp"
#include "Controle.hpp"

using namespace std;

int main()
{
    Televisao *tv = new Televisao();
    Controle *controle = new Controle(tv);
    string entrada;
    int entradaValor;

    while(cin>>entrada){

	if(entrada == "SC"){
		cin >> entradaValor;
		controle->setCanal(entradaValor);
	}else if(entrada == "SV"){
		cin >> entradaValor;
		controle->setVolume(entradaValor);
	}else if(entrada == "MC"){
  		cout<<tv->getCanal()<<endl;
	}else if(entrada == "MV"){
		cout<<tv->getVolume()<<endl;
	}else if(entrada == "AC"){
		controle->aumentaCanal();
	}else if(entrada == "AV"){
		controle->aumentaVolume();
	}else if(entrada == "DC"){
		controle->diminuiCanal();
	}else if(entrada == "DV"){
		controle->diminuiVolume();
	}else{
		cout<<"Essa entrada não é válida"<<endl;
	}

    }
	

    delete tv;
    delete controle;

    return 0;
}

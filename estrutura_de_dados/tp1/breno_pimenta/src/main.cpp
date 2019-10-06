#include "lista/CelulaEspecial.hpp"
#include "lista/Lista.hpp"
#include "camadas/ControleCamadas.hpp"

#include <iostream>

using namespace std;

int main(){
  char inNumb[199999]; 
  char cmd; 
  int numb;
  int movimentos;

  
  Lista* lista = new Lista();

  while(true){
      
    cin>>inNumb;
 
    //Condicao de parada
    if(inNumb[0] == 'E') break;

    cin>>cmd;

    numb = atoi(inNumb);

    if(cmd == 'i'){
      lista->addValor(numb);
    }

    if(cmd == 'r'){
      lista->removerValor(numb);
    }

    if(cmd == 'p'){
      ControleCamadas* ctl = new ControleCamadas(lista);
      movimentos = ctl->calcularMovimentos(numb); 
      delete ctl;
      cout<<movimentos<<endl;
    }

  }

  delete lista;

  return 0;
}

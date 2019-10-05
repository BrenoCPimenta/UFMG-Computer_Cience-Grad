#include "src/lista/CelulaEspecial.hpp";
#include "src/lista/Lista.hpp";
#include "src/camadas/ControleCamadas.hpp";

#include <iostream>

using namespace std;

int main(){

  Lista* lista = new Lista();
  lista->addValor(1);
  lista->addValor(2);
  lista->addValor(3);
  lista->addValor(35);
  lista->addValor(22);
  
  ControleCamadas* ctl = new ControleCamadas(lista);
  
  int movimentos = ctl->calcularMovimentos(5); 
  cout<<"\n\n\n\n\n\n"<<movimentos<<endl;

  delete lista;
  delete ctl;

  return 0;
}

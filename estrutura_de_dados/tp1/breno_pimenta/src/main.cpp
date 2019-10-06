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
  bool exitFlag = true;
  int cnt = 0;

  
  Lista* lista = new Lista();

  while(exitFlag){
    if(!cin.good()){
      exitFlag = false;
    }


    if(cnt != 0 && exitFlag){
      cout<<movimentos<<endl;
    }
    cnt++;
    cin>>inNumb;
    cin>>cmd;
    numb = atoi(inNumb);
    if(cmd == 'i'){
      lista->addValor(numb);
      cnt = 0;
    }
    if(cmd == 'r'){
      lista->removerValor(numb);
      cnt = 0;
    }
    if(exitFlag){
      if(cmd == 'p'){
        ControleCamadas* ctl = new ControleCamadas(lista);
        movimentos = ctl->calcularMovimentos(numb); 
        delete ctl;
      }
    }
  }

  lista->esvaziar();
  delete lista;
  return 0;
}

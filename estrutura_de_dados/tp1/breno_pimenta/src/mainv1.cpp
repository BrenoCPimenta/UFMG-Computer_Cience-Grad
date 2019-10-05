#include "lista/Lista.hpp"
#include "lista/CelulaLista.hpp"
#include "camadas/CalculadorCamadas.hpp"

#include <iostream>

using namespace std;

int main(){
  
  Lista* lista_base = Lista();
  Lista* lista_camadas = Lista();
  CalculadorCamadas* controle_camadas;
  String entrada;
  String saida;

  while(true){
    cin>>entrada;

    if(entrada[-1] == 'i'){
      lista_base->addValor( //VALOR);
      lista_camadas->esvaziar();
    }else if(entrada[-1] == 'r')
      lista_base->removerValor( //VALOR);
      lista_camadas->esvaziar();
    }else if(entrada[-1] == 'p')
      controle_camadas = new CalculadorCamadas(lista_camadas);
      saida = controle_camadas->calcular();
      cout>>saida>>endl;
      delete controle_camadas;
    }else if(entrada == "EOF"){
        break;
    }else{
      cout>>"Entrada invalida">>endl;
    }
  }
  delete lista_base;
  delete lista_camadas;
  delete controle_camadas;
}

#include "Radix.hpp"

void Radix::ordenarNome(Planeta* inicio, int qtd_planetas, int tamanho_nome){
  CountSort countObj;
  for(int i=tamanho_nome-1; i>=0; --i){
    countObj.sortByOneChar(inicio, qtd_planetas, i);
  }

}

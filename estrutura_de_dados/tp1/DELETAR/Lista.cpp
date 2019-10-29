#include "Lista.hpp"

void Lista::addValor(int valor){
  CelulaLista celulaObj = new CelulaLista(valor, this->_topo);
  this->_topo = &celulaObj;
}


bool Lista::removerValor(int valorRem){
  int *aux;
  int iterator = topo;
  while(true){
    if(iterator->valor == valorRem){
      aux = interator->anterior;
      aux->proximo = interator->proximo;
      aux = iterator->proximo;
      aux->anterior = iterator->anterior;
      delete iterator;
      return true;
    }
    if(iterator->proximo == NULL){
      return false;
    }
    iterator = iterator->proximo;

}

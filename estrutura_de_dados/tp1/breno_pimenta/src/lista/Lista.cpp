#include "Lista.hpp"

using namespace std;


Lista::~Lista(){
  this->esvaziar();
}


bool Lista::addValor(int valor){
  CelulaLista celulaObj = new CelulaLista(valor, this->_final_fila);
  this->_final_fila->setAnterior(celulaObj);
  this->_final_fila = celulaObj;
  return true;
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

bool Lista::verificarVazia(){
	if(this->_final_lista == this->_comeco_fila){
		return true;
	}
	return false;
}

bool Lista::esvaziar(){
	while(this->_final_lista != NULL){
    this->_final_lista = this->_final_lista->getProximo();
    delete this->_final_lista->getAnterior();
  }
  return true;
}



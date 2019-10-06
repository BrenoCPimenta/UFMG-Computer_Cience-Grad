#include "Lista.hpp"

#include <iostream>

using namespace std;

Lista::Lista(){
  CelulaEspecial* celulaCabeca = new CelulaEspecial(0);
  this->_comeco_lista = celulaCabeca;
  this->_final_lista = celulaCabeca;
  this->_tamanho = 0;
}

Lista::~Lista(){
  this->esvaziar();
  delete _comeco_lista;
}

bool Lista::addValor(int valor){
  CelulaEspecial* celulaObj = new CelulaEspecial(valor);
  celulaObj->setProximo(this->_final_lista);
  
  this->_final_lista->setAnterior(celulaObj);
  this->_final_lista = celulaObj;

  this->_tamanho++;
  return true;
}

bool Lista::removerValor(int valorRem){

  CelulaEspecial* aux = this->_final_lista;

  while(aux != this->_comeco_lista){
    if(aux->getValor() == valorRem){
      if(aux == this->_final_lista){
        this->_final_lista = this->_final_lista->getProximo();
      }else{
        aux->getAnterior()->setProximo(aux->getProximo());
        aux->getProximo()->setAnterior(aux->getAnterior());
      }
      delete aux;
      this->_tamanho--;
      return true;  
    }
    aux = aux->getProximo();
  }
  return false;
}
      
bool Lista::verificarVazia(){
	if(this->_final_lista == this->_comeco_lista){
		return true;
	}
	return false;
}
bool Lista::esvaziar(){
	while(this->_final_lista != this->_comeco_lista){
    this->_final_lista = this->_final_lista->getProximo();
    delete this->_final_lista->getAnterior();
  }
  this->_tamanho = 0;
  return true;
}


int* Lista::getValores(){
  int* valores = new int[this->_tamanho];
  CelulaEspecial* aux = this->_final_lista;
  for(int i=0; i< this->_tamanho; i++){
    valores[i]= aux->getValor();
    aux=aux->getProximo();
  }
  return valores;
}

int Lista::getTamanho(){
  return this->_tamanho;
}

bool Lista::valorJaArmazenado(int valor){
  CelulaEspecial* aux = this->_final_lista;
  while(aux != this->_comeco_lista){
    if(aux->getValor() == valor){
      return true;
    }
    aux=aux->getProximo();
  }
  return false;
}

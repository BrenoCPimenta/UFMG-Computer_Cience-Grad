#include "Lista.hpp"

#include <iostream>

using namespace std;

Lista::Lista(){
  CelulaEspecial* celulaControle = new CelulaEspecial();
  this->_comeco_lista = celulaControle;
  this->_final_lista = celulaControle;
  this->_tamanho=0;
}

Lista::~Lista(){
  this->esvaziar();
  delete _comeco_lista;
}

bool Lista::addPalavra(char* nome){
  CelulaEspecial* celulaObj = new CelulaEspecial(nome);
  celulaObj->setAnterior(this->_final_lista);
  
  this->_final_lista->setProximo(celulaObj);
  this->_final_lista = celulaObj;
  this->_tamanho++;

  return true;
}

      
bool Lista::verificarVazia(){
	if(this->_final_lista == this->_comeco_lista){
		return true;
	}
	return false;
}

bool Lista::esvaziar(){
	while(this->_final_lista != this->_comeco_lista){
    this->_final_lista = this->_final_lista->getAnterior();
    delete this->_final_lista->getProximo();
  }
  //delete this->_final_lista;
  return true;
}


bool Lista::verificarSePossuiPalavra(char* nome){
  CelulaEspecial* aux = this->_final_lista;
  while(aux != this->_comeco_lista){
    if(*(aux->getNome()) == *nome){
      return true;
    }
    aux=aux->getAnterior();
  }
  return false;
}

CelulaEspecial* Lista::getPalavra(char* nome){
  CelulaEspecial* aux = this->_final_lista;
  while(aux != this->_comeco_lista){
    if(*(aux->getNome()) == *nome){
      return aux;
    }
    aux=aux->getAnterior();
  }
  return NULL;
}

CelulaEspecial* Lista::getPalavra(int index){
  CelulaEspecial* aux = this->_comeco_lista;
  for(int i=0; i<index;i++){
    aux = aux->getProximo();
  }  
  return aux;
}

int Lista::getTamanho(){
  return this->_tamanho;
}

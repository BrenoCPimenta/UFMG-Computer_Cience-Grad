#include "Lista.hpp"

#include <iostream>

using namespace std;

Lista::Lista(){
  char* nome_celula_controle = new char;
  *nome_celula_controle = '!';
  CelulaEspecial* celulaCabeca = new CelulaEspecial(nome_celula_controle);
  this->_comeco_lista = celulaCabeca;
  this->_final_lista = celulaCabeca;
  //this->_tamanho = 0;
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

  //this->_tamanho++;
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
  //this->_tamanho = 0;
  return true;
}


bool Lista::verificarSePossuiPalavra(char* nome){
  CelulaEspecial* aux = this->_final_lista;
  while(aux != this->_comeco_lista){
    cout<<"RODANDO"<<endl;
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
  char* teste;
  *teste = 'e';
  return new CelulaEspecial(teste);
}



/*
int Lista::getTamanho(){
  return this->_tamanho;
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

*/
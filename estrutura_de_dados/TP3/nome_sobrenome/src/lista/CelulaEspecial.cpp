#include "CelulaEspecial.hpp"

using namespace std;


CelulaEspecial::CelulaEspecial(char* nome):_nome(nome){}

void CelulaEspecial::setProximo(CelulaEspecial *proximo){
  this->_proximo = proximo;
}

void CelulaEspecial::setAnterior(CelulaEspecial *anterior){
  this->_anterior = anterior;
}

bool CelulaEspecial::somaUmRepeticao(){
  this->_repeticao++;
  return true;
}


int CelulaEspecial::getRepeticao(){
  return this->_repeticao;
}

char* CelulaEspecial::getNome(){
	return this->_nome;
}


CelulaEspecial* CelulaEspecial::getProximo(){
  return this->_proximo;
}

CelulaEspecial* CelulaEspecial::getAnterior(){
  return this->_anterior;
}

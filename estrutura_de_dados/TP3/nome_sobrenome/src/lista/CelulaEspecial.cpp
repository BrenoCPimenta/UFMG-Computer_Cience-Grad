#include "CelulaEspecial.hpp"

using namespace std;


CelulaEspecial::CelulaEspecial(char* nome):_nome(nome){}

void CelulaEspecial::setValor(int &valor){
  this->_valor=valor;
}

void CelulaEspecial::setProximo(CelulaEspecial *proximo){
  this->_proximo = proximo;
}

void CelulaEspecial::setAnterior(CelulaEspecial *anterior){
  this->_anterior = anterior;
}

void CelulaEspecial::addRepeticao(){
  this->_repeticao++;
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

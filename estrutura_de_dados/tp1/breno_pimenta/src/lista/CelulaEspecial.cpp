#include "CelulaEspecial.hpp"

using namespace std;

CelulaEspecial::CelulaEspecial(/*int camada, */int valor, CelulaEspecial* proximo):/*_camada(camada),*/ _valor(valor), _proximo(proximo){}

CelulaEspecial::CelulaEspecial(/*int camada, */int valor):/*_camada(camada),*/_valor(valor){}

void CelulaEspecial::setValor(int &valor){
  this->_valor=valor;
}

void CelulaEspecial::setProximo(CelulaEspecial *proximo){
  this->_proximo = proximo;
}

void CelulaEspecial::setAnterior(CelulaEspecial *anterior){
  this->_anterior = anterior;
}

int CelulaEspecial::getValor(){
  return this->_valor;
}



CelulaEspecial* CelulaEspecial::getProximo(){
  return this->_proximo;
}

CelulaEspecial* CelulaEspecial::getAnterior(){
  return this->_anterior;
}

/*
void CelulaEspecial::setCamada(int &camada){
  this->_camada=camada;
}

int CelulaEspecial::getCamada(){
  return this->_camada;
}
*/

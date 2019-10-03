#include "CelulaLista.hpp"

CelulaLista::CelulaLista(int valor, int proximo, int anterior):_valor(valor), _proximo(proximo), _anterior(anterior){}

void CelulaLista::setValor(valor){
  this->_valor=valor;
}

void CelulaLista::setProximo(proximo){
  this->_proximo = proximo;
}

void CelulaLista::serAnterior(anterior){
  this->_anterior = anterior;
}

int CelulaLista::getValor(){
  return this->_valor;
}

int CelulaLlista::getProximo(){
  return this->_proximo;
}

int CelulaLista::getAnterior(){
  return this->_anterior;
}

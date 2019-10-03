#include "CelulaLista.hpp"

using namespace std;

CelulaLista::CelulaLista(int valor, CelulaLista* proximo, CelulaLista* anterior):_valor(valor), _proximo(proximo)/*, _anterior(anterior)*/{}


void CelulaLista::setValor(int &valor){
  this->_valor=valor;
}

void CelulaLista::setProximo(CelulaLista proximo){
  this->_proximo = &proximo;
}

void CelulaLista::setAnterior(CelulaLista *anterior){
  this->_anterior = anterior;
}

int CelulaLista::getValor(){
  return this->_valor;
}

CelulaLista* CelulaLista::getProximo(){
  return this->_proximo;
}

CelulaLista* CelulaLista::getAnterior(){
  return this->_anterior;
}

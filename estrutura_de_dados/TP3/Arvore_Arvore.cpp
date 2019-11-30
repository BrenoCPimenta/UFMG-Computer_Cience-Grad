
#include “Arvore.hpp”
#include “No.hpp”

Arvore::Arvore(char* nome, int repeticao){
  this->_raiz = new No(nome, repeticao);
}

int Arvore::getTamanho(){
  return this->_tamanho;
}

char* Arvore::getNomeRaiz(){
  return this->_raiz->getNome();
}


int Arvore::getRepeticaoRaiz(){
  return this->_raiz->getRepeticao();
}
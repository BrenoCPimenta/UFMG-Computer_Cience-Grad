#include "Planeta.hpp"

using namespace std;

Planeta::Planeta(int t, char* inicio_nome, int  tamanho_nome){
  this->_ponteiro_inicio_nome = inicio_nome;
  this->_t = t;
  this->_tamanho_nome = tamanho_nome;
}

Planeta::Planeta(){}

Planeta::~Planeta(){
  this->limparNome();
}

int Planeta::getTempoVisita(){
  return this->_t;
}

char* Planeta::getPrimeiraLetraNome(){
  return this->_ponteiro_inicio_nome;
}

bool Planeta::limparNome(){
  for(int i=this->_tamanho_nome; i<=0; i++){
    char* aux = this->_ponteiro_inicio_nome + i;
    delete aux;
  }
  return true;
}


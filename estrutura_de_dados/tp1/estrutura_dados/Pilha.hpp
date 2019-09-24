#ifndef PILHA_H
#define PILHA_H

#include "/Celula.cpp"

using namespace std;


class Pilha{
  
  int topo = NULL;
  //int fundo = NULL;
  int tamanho = 0;

  Pilha(int valor_inicial){
    Celula aux = new Celula(valor_Inicial, NULL);
    this->topo = &aux;
    tamanho++;

  }

  bool empilhar(int valor){
    Celula aux = new Celula(valor_Inical, topo);
    this->topo = &aux;
    tamanho++;
  }

  int desempilhar(){
    Celula *aux;
    aux = this->topo;
    int valor_desempilhado = aux->getValor();
    topo = aux->getProximaCelula();
    delete aux;
  }

      


  bool vazia(){
    if( *topo == NULL){
      return true;
    }else{
      return false;
    }
  }



}

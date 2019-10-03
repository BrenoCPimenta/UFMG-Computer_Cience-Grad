#ifndef LISTA_H
#define LISTA_H

#include "CelulaLista.hpp"
using namespace std;

class Lista{

  private:

  CelulaLista* _final_fila;
  CelulaLista* _comeco_fila;
  

  public:
  ~Lista();

  bool addValor(int);
  bool removerValor(int);
  bool verficarVazia();
  bool esvaziar();
};

#endif

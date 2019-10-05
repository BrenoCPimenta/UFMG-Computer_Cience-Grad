#ifndef LISTA_H
#define LISTA_H

#include "CelulaEspecial.hpp"
using namespace std;

class Lista{

  private:

  CelulaEspecial* _final_lista;
  CelulaEspecial* _comeco_lista;
  int _tamanho;
  

  public:
  Lista();
  ~Lista();

  bool addValor(int/*, int*/);
  bool removerValor(int);
  bool verificarVazia();
  bool esvaziar();
  int* getValores();
  int getTamanho();
};

#endif

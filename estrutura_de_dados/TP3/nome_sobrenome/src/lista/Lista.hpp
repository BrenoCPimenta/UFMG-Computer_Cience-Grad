#ifndef LISTA_H
#define LISTA_H

#include "CelulaEspecial.hpp"
using namespace std;

class Lista{

  private:

  CelulaEspecial* _final_lista;
  CelulaEspecial* _comeco_lista;
  //int _tamanho;
  

  public:
  Lista();
  ~Lista();

  bool addPalavra(char*);
  bool verificarVazia();
  bool esvaziar();
  bool verificarSePossuiPalavra(char*);
  CelulaEspecial* getPalavra(char*);

  /*
  int* getValores();
  int getTamanho();
  bool valorJaArmazenado(int);
  */
};

#endif
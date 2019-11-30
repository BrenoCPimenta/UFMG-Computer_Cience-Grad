#ifndef ARVORE_H
#define ARVORE_H

#include “No.hpp”

class Arvore{
  
  private:
    No* _raiz;
    int _tamanho;
  
  public:
    Arvore(char*, int);
    No* getRaiz();
    int getTamanho();
    char* getNomeRaiz();
    int getRepeticaoRaiz();
    void joinArvore(No*);
    bool deleteArvore();
  
};

#endif
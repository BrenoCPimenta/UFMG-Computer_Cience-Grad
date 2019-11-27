#ifndef CELULA_H
#define CELULA_H

using namespace std;

class CelulaEspecial{
  private:
    char _nome[63];
    int _repeticao = 1;
    int _codigo = 0;

    CelulaEspecial* _proximo;
    CelulaEspecial* _anterior;
    
  public:
    CelulaEspecial(char*);
    void setProximo(CelulaEspecial*);
    void setAnterior(CelulaEspecial*);
    void addRepeticao();
    int getRepeticao();
    char* getNome();
    CelulaEspecial* getProximo();
    CelulaEspecial* getAnterior();
    
};
#endif 

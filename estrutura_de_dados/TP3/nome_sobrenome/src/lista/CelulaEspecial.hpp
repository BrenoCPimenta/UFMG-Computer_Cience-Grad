#ifndef CELULA_H
#define CELULA_H

using namespace std;

class CelulaEspecial{
  private:
    char* _nome;
    int _repeticao = 1;
    char _codigo[32];

    CelulaEspecial* _proximo;
    CelulaEspecial* _anterior;
    
  public:
    CelulaEspecial();
    CelulaEspecial(char*);
    void setProximo(CelulaEspecial*);
    void setAnterior(CelulaEspecial*);
    bool somaUmRepeticao();
    int getRepeticao();
    char* getNome();
    CelulaEspecial* getProximo();
    CelulaEspecial* getAnterior();
    
};
#endif 

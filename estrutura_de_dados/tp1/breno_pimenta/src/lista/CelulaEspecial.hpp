#ifndef CELULA_H
#define CELULA_H

using namespace std;

class CelulaEspecial{
  private:
    int _valor;
    //int _camada;
    CelulaEspecial* _proximo;
    CelulaEspecial* _anterior;
    
  public:
    CelulaEspecial(/*int,*/ int, CelulaEspecial*);
    CelulaEspecial(/*int,*/ int);
    void setProximo(CelulaEspecial*);
    void setValor(int&);
    void setAnterior(CelulaEspecial*);
    //void setCamada(int&);
    int getValor();
    //int getCamada();
    CelulaEspecial* getProximo();
    CelulaEspecial* getAnterior();
    
};
#endif 

#ifndef CELULA_H
#define CELULA_H

using namespace std;

class CelulaLista{
  private:
    int _valor;
    CelulaLista* _proximo;
    CelulaLista* _anterior;
    
  public:
    CelulaLista(int, CelulaLista*, CelulaLista*);
    void setProximo(CelulaLista);
    void setValor(int&);
    void setAnterior(CelulaLista*);
    int getValor();
    CelulaLista* getProximo();
    CelulaLista* getAnterior();
    
};
#endif 

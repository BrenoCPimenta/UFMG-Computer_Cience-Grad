#ifndef CELULA_H
#define CELULA_H

using namespace std;

public class CelulaLista{
  private:
    int _valor = NULL;
    int _proximo = NULL;
    int _anterior = NULL;
    
  public:
    CelulaLista(int, int, int);
    void setProximo(int);
    void setValor(int);
    void setAnterior(int)
    int getValor();
    int getProximo();
    int getAnterior();
    
}
#endif 

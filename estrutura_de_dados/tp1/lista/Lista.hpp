#ifndef LISTA_H
#define LISTA_H

using namespace std;

class Lista{

  private:

  int final_fila = NULL;
  int comeco_fila = NULL;
  

  public:
  Lista(){}
  ~Lista(){}

  void addValor(int);
  bool removerValor(int);
  bool verficarVazia();
  bool esvaziar();
}

#endif

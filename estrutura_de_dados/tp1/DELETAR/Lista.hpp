#ifndef LISTA_H
#define LISTA_H

class Lista{

  private:

  int final_fila = NULL;
  int comeco_fila = NULL;
  CelulaLista celulaObj;
  

  public:
  Lista(){}
  ~Lista(){}

  void addValor(int);
  bool removerValor(int);
  bool verficarVazia();
  bool esvaziar();
}

#endif

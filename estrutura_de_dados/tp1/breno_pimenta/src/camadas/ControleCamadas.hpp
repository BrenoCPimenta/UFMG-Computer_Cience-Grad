#ifndef CONTROLECAMADAS_H
#define CONTROLECAMADAS_H

#include "../lista/Lista.hpp"
#include "../lista/CelulaEspecial.hpp"


using namespace std;

class ControleCamadas{
  private:
    int _medida;
    //Lista* _lista_base;
    int* _valores_base;
    int _tamanho_base;
    int _tamanho_camada_atual;
    int _camada_final;
    //int _camada_atual; 

    bool verificandoMedidaEmCamada(int*, int);
    Lista* constroiProximaCamada(int*);
  public:
    ControleCamadas(Lista*);
    int calcularMovimentos(int);
};
#endif
  
  

#include <iostream>

using namespace std;
class Camada(){
 

  private:
    int num_camada;
    int num_valores;
    *int camada_anterior = NULL;
    *int camada_proxima = NULL; 
    Lista valores_da_camada;




  public:
  
    Camada(){
     this->num_camada = 0; 
     this->num_valores = 0;
     Lista valores_da_camada = new Lista();
    }


    Camada(*Camada ponteiro_camada_anterior){
      this->num_valores = 0;

      this-> &camada_anterior = &ponteiro_camada_anterior;
      int num_camada_anterior = *ponteiro_camada_anterior->getNumCamada();
      this-> num_camada = num_camada_anterior + 1;
    }


    int getNumCamada(){
      return this->num_camada;
    }


}

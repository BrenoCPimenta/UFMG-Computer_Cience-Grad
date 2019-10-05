#include "ControleCamadas.hpp"

#include <iostream>

ControleCamadas::ControleCamadas(Lista* lista_base)
    :_valores_base(lista_base->getValores()), 
      _tamanho_base(lista_base->getTamanho()){};

int ControleCamadas::calcularMovimentos(int medida){
  this->_medida = medida;
  Lista* nova_camada = new Lista();
  int* valores_atuais;

  //verificando com zero
  if(medida == 0){
    return 0;
  }
  
  //Iniciando parametros para proximas verificacoes 
  this->_camada_final = 1;
  valores_atuais = this->_valores_base;
  this->_tamanho_camada_atual = this->_tamanho_base;
  
  //verificando com 1 ou mais medidas
  while(!this->verificandoMedidaEmCamada(valores_atuais, this->_tamanho_camada_atual)){
    nova_camada = this->constroiProximaCamada(valores_atuais);
    delete valores_atuais;
    valores_atuais = nova_camada->getValores();
    this->_tamanho_camada_atual = nova_camada->getTamanho();
    this->_camada_final++;
    delete nova_camada;
    for(int i=0; i<this->_tamanho_camada_atual;i++){
      cout<<valores_atuais[i]<<endl;
    }
  }
  delete valores_atuais;
  return this->_camada_final;
}  

bool ControleCamadas::verificandoMedidaEmCamada(int* arr, int tamanho_arr){
  for(int i=0; i<tamanho_arr; i++){
    if(arr[i]==this->_medida){
      return true;
    }
  }
  return false;
}

Lista* ControleCamadas::constroiProximaCamada(int* valores_camada_anterior){
  Lista* camada_em_construcao = new Lista();
  int novo_valor;

  for(int i=0; i<this->_tamanho_camada_atual; i++){
    for(int j=0; j<this->_tamanho_base; j++){

      //Caso os dois sejam menores
      if(this->_valores_base[j] < this->_medida && valores_camada_anterior[i]< this-> _medida){
         novo_valor =_valores_base[j] + valores_camada_anterior[i];
      }

      //Caso soh o valor base seja maior
      if(this->_valores_base[j] > this->_medida && valores_camada_anterior[i]< this-> _medida){
         novo_valor =this->_valores_base[j] - valores_camada_anterior[i];
      }

      //Caso ambos os valores sejam maiores
      if(this->_valores_base[j] > this->_medida && valores_camada_anterior[i]> this-> _medida){

        //Sendo ambos maiores que medida e valor da base maior que o atual
        if(this->_valores_base[j] > valores_camada_anterior[i]){
          novo_valor =this->_valores_base[j] - valores_camada_anterior[i];
        }
        //Sendo ambos maiores que medida e valor da base menor que o atual
        else{
          novo_valor = valores_camada_anterior[i] - this->_valores_base[j];
        }
      }
      //Caso soh o valor da camada anterior seja maior
      else{
        novo_valor = valores_camada_anterior[i] - this->_valores_base[j];
      }

      camada_em_construcao->addValor(novo_valor);
    }
  }
  return camada_em_construcao;
}


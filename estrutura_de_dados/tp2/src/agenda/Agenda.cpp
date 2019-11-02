#include "Agenda.hpp"


Agenda::Agenda(Planeta* inicio, int tempo_visita_mes, int quantidade_total_planetas){
  
  //Calculando quantidade de planetas por meses e quantos meses
  int mes_rodada = 0;
  int soma_tempo = 0;
  int quantidade_planeta_rodada = 0;
  for(int i=0; i<quantidade_total_planetas; i++){
    if((soma_tempo + (inicio+i)->getTempoVisita()) > tempo_visita_mes){
      soma_tempo = (inicio+i)->getTempoVisita();
      this->_tamanho_meses[mes_rodada] = quantidade_planeta_rodada;
      mes_rodada++;
      quantidade_planeta_rodada = 1;
    }else{
      quantidade_planeta_rodada++;
      soma_tempo += (inicio+i)->getTempoVisita();
    }
  }
  this->_tamanho_meses[mes_rodada] = quantidade_planeta_rodada;
  this->_quantidade_meses_agenda = mes_rodada+1;

  //Criando array com inicio dos meses
  int calculo_tamanho_mes_continuo = 0;
  //this->_inicio_meses[0] = inicio;
  for(int i=0; i<this->_quantidade_meses_agenda;i++){ 
    this->_inicio_meses[i] = (inicio + calculo_tamanho_mes_continuo); 
    calculo_tamanho_mes_continuo += this->_tamanho_meses[i]; 
  }
}

Agenda::~Agenda(){
  delete[] this->_inicio_meses;
}

int Agenda::getQuantidadeMeses(){
  return this->_quantidade_meses_agenda;
}

Planeta* Agenda::getInicioMes(int indice_mes){
  return _inicio_meses[indice_mes];
}

int Agenda::getTamanhoMes(int indice_mes){
  return this->_tamanho_meses[indice_mes];
}

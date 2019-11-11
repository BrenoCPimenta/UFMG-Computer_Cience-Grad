#include "planeta/Planeta.hpp"
#include "agenda/Agenda.hpp"
#include "merge/Merge.hpp"
#include "count/CountSort.hpp"
#include "radix/Radix.hpp"

#include <iostream>

using namespace std;


int main(){
  int tempo_limite_mes_T;
  int quantidade_planetas_P;
  int tamanho_nome_planeta_x;

  //Lendo parametros iniciais
  cin>>tempo_limite_mes_T>>quantidade_planetas_P>>tamanho_nome_planeta_x;

  //Declarando variaveis para receber dados dos planetas
  int t;
  Planeta planetas[quantidade_planetas_P];

  //Lendo dados dos planetas
  for(int i=0; i<quantidade_planetas_P; i++){
    char* nome_planeta = new char[tamanho_nome_planeta_x];
    cin>>t>>nome_planeta;
    Planeta planeta(t, nome_planeta, tamanho_nome_planeta_x);
    planetas[i] = planeta;
  }

  //Ordenando primeiro por valores
  Merge mergeObj;
  mergeObj.separando(&planetas[0], quantidade_planetas_P);
   
  //Separando os meses
  int quantidade_meses;
  Radix radixObj;
  Agenda agendaObj(planetas, tempo_limite_mes_T, quantidade_planetas_P);
  quantidade_meses = agendaObj.getQuantidadeMeses();

  //Ordenando meses alfabeticamente
  Planeta* inicio_mes;
  int tamanho_mes;
  for(int i=0; i<quantidade_meses; i++){
    inicio_mes = agendaObj.getInicioMes(i);
    tamanho_mes = agendaObj.getTamanhoMes(i);

    radixObj.ordenarNome(inicio_mes, tamanho_mes, tamanho_nome_planeta_x);
   
    //Imprimindo Mes ordenado
    for(int j=0; j<tamanho_mes; j++){
      cout<<i+1<<" ";
      for(int k=0; k<tamanho_nome_planeta_x; k++){
        cout<<(inicio_mes+j)->getPrimeiraLetraNome()[k];
      }
      cout<<" "<<(inicio_mes+j)->getTempoVisita()<<endl;
    }
  } 

  //Limpando nomes que foram alocados dinamicamente
  for(int i=0; i<quantidade_planetas_P; i++){
    planetas[i].limparNome();
  }
}


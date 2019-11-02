#include "planeta/Planeta.hpp"
#include "merge/Merge.hpp"

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

  //Imprimindo valores de planetas
  for(int i=0; i<quantidade_planetas_P; i++){
    cout<<"Planeta "<<i<<": "
        <<"  t:"<<planetas[i].getTempoVisita()
        <<"  nome:"<<planetas[i].getPrimeiraLetraNome()[0]
        <<endl;
  }

  //Ordenando valores
  Merge mergeObj;
  mergeObj.separando(&planetas[0], quantidade_planetas_P);
   

  cout<<"\n\n";
  //Imprimindo valores ORDENADOS de planetas
  for(int i=0; i<quantidade_planetas_P; i++){
    cout<<"Planeta "<<i<<": "
        <<"  t:"<<planetas[i].getTempoVisita()
        <<"  nome:"<<planetas[i].getPrimeiraLetraNome()[0]
        <<endl;
  }

  //Agendar
  int quantidade_meses;
  Agenda agendaObj(planetas, tempo_limite_mes_T, quantidade_planetas_P);
  quantidade_meses = agendaObj.getQuantidadeMeses();

  //Ordenando meses alfabeticamente
  Planeta* inicio_mes;
  int tamanho_mes;
  for(int i=0; i<quantidade_meses; i++){
    inicio_mes = agendaObj.getInicioMes(i);
    tamanho_mes = agendaObj.getTamanhoMes(i);
    Mes mesObj(inicio_mes, tamanho_mes);
    mesObj.ordenarMes();
  } 
 

  //Limpando
  for(int i=0; i<quantidade_planetas_P; i++){
    planetas[i].limparNome();
  }
}

#include "planeta/Planeta.hpp"
#include "merge/Merge.hpp"

#include <iostream>

using namespace std;


int main(){
  int T;
  int quantidade_planetas_P;
  int tamanho_nome_planeta_x;

  //Lendo parametros iniciais
  cin>>T>>quantidade_planetas_P>>tamanho_nome_planeta_x;

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
  /*
  int quantidade_array_planetas = quantidade_planetas_P - 1;
  Merge mergeObj(quantidade_array_planetas);
  mergeObj.separando(&planetas[0], &planetas[quantidade_array_planetas]);
  */
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

/*
  //conferindo e limpando
  for(int i=0; i<quantidade_planetas_P; i++){
    cout<<"Planeta "<<i<<": "
        <<"  t:"<<planetas[i].getTempoVisita()
        <<"  nome:"<<planetas[i].getPrimeiraLetraNome()[0]
        <<endl; 
    planetas[i].limparNome();
  }
*/
}

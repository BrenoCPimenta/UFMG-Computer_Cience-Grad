#include "planeta/Planeta.hpp"

#include <iostream>

using namespace std;

/*
class Planeta{
  public:
    int t;
    char* ponteiro_inicio_nome;
    Planeta(int t, char &inicio_nome){
      this->ponteiro_inicio_nome = &inicio_nome;
      this->t = t;
    } 
    Planeta();
};
*/


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



  //conferindo e limpando
  for(int i=0; i<quantidade_planetas_P; i++){
    cout<<"Planeta "<<i<<": "
        <<"  t:"<<planetas[i].getTempoVisita()
        <<"  nome:"<<planetas[i].getPrimeiraLetraNome()[0]
        <<endl; 
    planetas[i].limparNome();
  }
}

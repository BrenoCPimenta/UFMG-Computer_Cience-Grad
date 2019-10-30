

#include <iostream>

using namespace std;

class Planeta{
  public:
    int t;
    char nome[3];
};



int main(){
  int T;
  int quantidade_planetas_P;
  int tamanho_nome_planeta;

  //Lendo parametros iniciais
  cin>>T>>quantidade_planetas_P>>tamanho_nome_planeta;

  //Declarando variaveis para receber dados dos planetas
  //char nome_planeta [tamanho_nome_planeta];
  char nome_planeta [3];
  int t;
  Planeta planetas[3];

  //Lendo dados dos planetas
  for(int i=0; i<quantidade_planetas_P; i++){
    cin>>t>>nome_planeta;
    planetas[i].t=t;
    for(int j=0;j<3;j++){
      planetas[i].nome[j]=nome_planeta[j];
    }
  }

  for(int i=0; i<quantidade_planetas_P; i++){
    cout<<"Planeta "<<i<<": "<<"  t:"<<planetas[i].t<<"  nome:"<<planetas[i].nome<<endl; 
  }
}

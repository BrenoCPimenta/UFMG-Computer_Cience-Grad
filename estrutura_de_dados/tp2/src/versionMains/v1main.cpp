

#include <iostream>

using namespace std;

int main(){
  int T;
  int quantidade_planetas_P;
  int tamanho_nome_planeta;

  //Lendo parametros iniciais
  cin>>T>>quantidade_planetas_P>>tamanho_nome_planeta;

  //Declarando variaveis para receber dados dos planetas
 // char nome_planeta = new char[tamanho_nome_planeta];
  char nome_planeta [tamanho_nome_planeta];
  int t;

  //Lendo dados dos planetas
  for(int i=0; i<quantidade_planetas_P; i++){
    cin>>t>>nome_planeta;
  }
  cout<<"\nt:"<<t<<"\nNome:"<<nome_planeta<<endl;

 // cout<<"\nT:"<<T<<"\nP:"<<quantidade_planetas<<"\nx"<<tamanho_nome_planeta<<endl;
  
}

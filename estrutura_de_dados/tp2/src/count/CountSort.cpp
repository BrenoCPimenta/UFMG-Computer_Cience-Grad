#include "CountSort.hpp"

#include <iostream>

void CountSort::sortByOneChar(Planeta* inicio, int qtd_planetas, int charNome){

  cout<<"\n Posicao 201"<<endl; 

  //Copiando os planetas para depois move-los
  Planeta copia_planetas[qtd_planetas];
  for(int i=0; i<qtd_planetas; i++){
    copia_planetas[i] = *(inicio + i);
  } 

  cout<<"\n Posicao 202"<<endl; 

  //array com as posicoes correspoondentes aos char's
  int posicao_array[26];

  //inicializando valores do array com zero
  for(int i=0; i<26; i++){
    posicao_array[i] = 0;
  }

  cout<<"\n Posicao 203"<<endl; 

  char* primeira_letra;
  char letra;
  int numero_da_letra;
  //Contando elementos 
  for(int i=0; i<qtd_planetas; i++){
    primeira_letra = (inicio+i)->getPrimeiraLetraNome();
    letra = *(primeira_letra + charNome); 
    numero_da_letra = int(letra) - 97;

    posicao_array[numero_da_letra]++; 
  }

  cout<<"\n Posicao 204"<<endl; 

  cout<<"Posicao array antes de calculo acumulado"<<endl;
  //Imprimindo posicao array antes de acumulo
  for(int i=0; i<26; i++){
    cout<<i<<": "<<posicao_array[i]<<endl;
  }

  //Realizando a soma acumulada no array
  for(int i=1; i<26; i++){
    posicao_array[i] += posicao_array[i-1];
  }
  cout<<"Posicao array depois do calculo acumulado"<<endl;
  //Imprimindo posicao array antes de acumulo
  for(int i=0; i<26; i++){
    cout<<i<<": "<<posicao_array[i]<<endl;
  }
  cout<<"\n Posicao 205"<<endl; 

  //Passando os planetas ordenados para a posicao de origem 
  int posicao_final;
  cout<<"Quantidade de loops: "<< qtd_planetas<<endl;
  //for(int i=qtd_planetas; i >= 0; --i){
  for(int i=qtd_planetas-1; i>=0;--i){
    cout<<"\nInicio loop n"<<i;
    //Buscando o valor numérico da letra da rodada
    primeira_letra = (inicio+i)->getPrimeiraLetraNome();
    letra = *(primeira_letra + charNome);  
    numero_da_letra = int(letra) - 97;

    //Calculando nova posicao do Planeta
    posicao_final = posicao_array[numero_da_letra] - 1;

    //Decrementando posicao ja usada
    posicao_array[numero_da_letra]--;

    cout<<"Posicao final "<< posicao_final <<endl;
    //Passando planeta para sua posicao ordenada
    *(inicio + posicao_final) = copia_planetas[i];
    cout<<"\nFinal loop n"<<i;
  }


  cout<<"\n Posicao 206"<<endl; 

}

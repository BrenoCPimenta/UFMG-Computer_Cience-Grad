#include "CountSort.hpp"

#include <iostream>

void CountSort::sortByOneChar(Planeta* inicio, int qtd_planetas, int charNome){

  //Copiando os planetas para depois move-los
  Planeta copia_planetas[qtd_planetas];
  for(int i=0; i<qtd_planetas; i++){
    copia_planetas[i] = *(inicio + i);
  } 

  //array com as posicoes correspoondentes aos char's
  int posicao_array[26];

  //inicializando valores do array com zero
  for(int i=0; i<26; i++){
    posicao_array[i] = 0;
  }

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

  //Realizando a soma acumulada no array
  for(int i=1; i<26; i++){
    posicao_array[i] += posicao_array[i-1];
  }

  //Passando os planetas ordenados para a posicao de origem 
  int posicao_final;
  int it = qtd_planetas-1; 
  while(it>=0){
    //Buscando o valor numérico da letra da rodada
    primeira_letra = copia_planetas[it].getPrimeiraLetraNome();
    letra = *(primeira_letra + charNome);  
    numero_da_letra = int(letra) - 97;

    //Calculando nova posicao do Planeta
    posicao_final = posicao_array[numero_da_letra] - 1;

    //Decrementando posicao ja usada
    posicao_array[numero_da_letra]--;

    //Passando planeta para sua posicao ordenada
    *(inicio + posicao_final) = copia_planetas[it];
    it--;
  }

}

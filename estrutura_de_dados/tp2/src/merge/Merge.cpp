#include "Merge.hpp"

#include <iostream>
using namespace std;


Planeta* Merge::separando(Planeta* inicio, int tamanho){
  cout<<"Separando :"<<this->cnt<<endl;
  for(int i = 0; i<tamanho;i++){
    cout<<(inicio+i)->getTempoVisita()<<" ";
  }
  this->cnt++;
  cout<<endl;

  //Final do separando, quando chega a um número a recursividade
  if(tamanho  == 1){
    return inicio;
  } 

  //Delimitando separação
  int meio_esquerdo = tamanho/2;
  int meio_direito = tamanho - meio_esquerdo;

  //Chamada recursiva para as duas metades do array
  this->separando(inicio, meio_esquerdo);
  this->separando((inicio + meio_esquerdo), meio_direito);

  //Unindo e ordenando o retorno das duas metades, cada uma já ordenada
  this->unindo(inicio, tamanho);

  return inicio; 
}



void Merge::unindo(Planeta* inicio, int tamanho){
  cout<<"Unindo: ";

  for(int i = 0; i<tamanho;i++){
    cout<<(inicio+i)->getTempoVisita()<<" ";
  }
  cout<<endl;



  //Inicializando memoria auxiliar
  Planeta* planetas = new Planeta[tamanho];

  //Populando memoria auxiliar
  for(int i=0; i<tamanho; i++){
    *(planetas + i) = *(inicio + i);
  }

  //Inicializando ponto de parada para os ponteireos
  int meio= (tamanho/2);
  int final_array = tamanho;

  //Inicializando ponteiros
  Planeta* a_iterator = planetas;
  Planeta* b_iterator = (planetas + (tamanho/2));
  
  //Controles do loop
  bool flag = true;
  int cnt = 0;

  while(flag){
    //Comparando ponteiros e atribuindo valores
    if((a_iterator == (planetas + meio)) && (b_iterator < (planetas + final_array))){
      *(inicio + cnt) = *b_iterator;
      b_iterator++;
    }else if(b_iterator == (planetas + final_array)){
      *(inicio + cnt) = *a_iterator;
      a_iterator++;
    }else if(a_iterator->getTempoVisita() <= b_iterator->getTempoVisita()){
      *(inicio + cnt) = *a_iterator;
      a_iterator++;
    }else if(a_iterator->getTempoVisita() > b_iterator->getTempoVisita()){
      *(inicio + cnt) = *b_iterator;
      b_iterator++;
    }

    cnt++;

    //Verificando termino
    if((a_iterator == (planetas + meio)) && (b_iterator == (planetas + final_array))){
      flag = false; 
    }
  }
  //Liberando espaço da memória auxiliar
  delete[] planetas;

  cout<<"Final Unindo: ";
  for(int i = 0; i<tamanho;i++){
    cout<<(inicio+i)->getTempoVisita()<<" ";
  }
  cout<<endl;

}

#include "Merge.hpp"


Merge::Merge(int quantidade_planetas){
  this->_quantidade_planetas = quantidade_planetas;
}



Planeta* Merge::separando(Planeta* inicio, Planeta* ultimo){
  if(inicio == ultimo){
    return inicio;
  } 

  Planeta* meio_esquedo;
  meio_esquerdo = (inicio/ultimo)/2;
  Planeta* meio_direiro;
  meio_direito = meio_esquerdo+1;

  this->separando(inicio, meio_esquerdo);
  this->separando(meio_direito, ultimo);

  return $this->unindo(inicio,
                       meio_esquerdo,
                       meio_direito,
                       ultimo);
  return inicio;
}

void Merge::unindo(Planeta* a_inicio, Planeta* a_final, Planeta* b_inicio, Planeta* b_final){
 
    //Criando memoria auxiliar 
    Planeta* planetas_armazenados_em_ordem;  

    //Populando memoria auxiliar
    int tamanho = a_inicio - b_final;
    for(int i=0; i<tamanho; i++){
      *(planetas_armazenados_em_ordem + i) = *(a_inicio + i);
    }
    //Criando iterators:
    Planeta* a_iterator;
    a_iterator = planetas_armazenados_em_ordem;

    Planeta* b_iterator;
    b_iterator = planetas_armazenados_em_ordem + (b_inicio - a_inicio); 

    //Criando pontos de parada
    Planeta* a_final_memoria_auxiliar;
    a_final_memoria_auxiliar = planetas_armazenados_em_ordem + (a_final - a_inicio);

    Planeta* b_final_memoria_auxiliar;
    b_final_memoria_auxiliar = planetas_armazenados_em_ordem + (b_final - a_inicio); 


    bool flag = true;
    int cnt = 0;

    
    while(flag){
      if(a_iterator == a_final_memoria_auxiliar){
        *(a_inicio + cnt) = *b_iterator;
        b_iterator++;
      }else if(b_iterator == b_final_memoria_auxiliar){
        *(a_inicio + cnt) = *a_iterator;
        a_iterator++;
      }else{
        if(*a_iterator.getTempoVisita() >= *b_iterator.getTempoVisita(){
            *(a_inicio + cnt) = *a_iterator;
            a_iterator++;
        }else{
            *(a_inicio + cnt) = *b_iterator;
            b_iterator++;
        }
      }    

      cnt++;

      if(a_iterator == a_final_memoria_auxiliar && b_iterator == b_final_memoria_auxiliar){
        flag=false;
      }
    }

    //Liberando espaço usado como memoria auxiliar
    for(int i=tamanho; i<=0; i++){
      delete (planetas_armazenados_em_ordem + i);
    }
} 


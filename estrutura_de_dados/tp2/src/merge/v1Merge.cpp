#include "Merge.hpp"

#include <iostream>
using namespace std;


Merge::Merge(int quantidade_planetas){
  this->_quantidade_planetas = quantidade_planetas;
}




Planeta* Merge::separando(Planeta* inicio, Planeta* ultimo){
  this->cnt++;
  cout<<"Separando: "<<this->cnt<<endl;
  
  if(inicio == ultimo){
    return inicio;
  } 

  Planeta* fake_inicio;
  fake_inicio = inicio;
  while(true){
    cout<<fake_inicio->getTempoVisita()<<" ";
    if(fake_inicio == ultimo){
      cout<<endl;
      break;
    }
    fake_inicio++;
  }

  Planeta* meio_esquerdo;
  meio_esquerdo = inicio + (ultimo-inicio)/2;
  Planeta* meio_direito;
  meio_direito = meio_esquerdo+1;

  this->separando(inicio, meio_esquerdo);
  this->separando(meio_direito, ultimo);

  this->unindo(inicio,
               meio_esquerdo,
               meio_direito,
               ultimo);

  //Testando Unindo
  fake_inicio = inicio;
  while(true){
    cout<<fake_inicio->getTempoVisita()<<" ";
    if(fake_inicio == ultimo){
      cout<<endl;
      break;
    }
    fake_inicio++;
  }
  return inicio;
}

void Merge::unindo(Planeta* a_inicio, Planeta* a_final, Planeta* b_inicio, Planeta* b_final){
    this->unicnt++;
    cout<<"Unindo: "<<this->unicnt<<endl;

    cout<<"Valores de entrada"<<endl;
    cout<<"A inicio: "<<a_inicio->getTempoVisita()<<endl;
    cout<<"A final: "<<a_final->getTempoVisita()<<endl;
    cout<<"B inicio: "<<b_inicio->getTempoVisita()<<endl;
    cout<<"B final: "<<b_final->getTempoVisita()<<endl;

    //Criando memoria auxiliar 
    int tamanho =  b_final - a_inicio;
    Planeta* planetas_armazenados_em_ordem[tamanho];  

    cout<<"TAMANHO: "<<tamanho<<endl;

    //Populando memoria auxiliar
    for(int i=0; i<tamanho; i++){
      *planetas_armazenados_em_ordem[i] = *(a_inicio + i);
    }

    //Criando iterators:
    Planeta* a_iterator;
    a_iterator = planetas_armazenados_em_ordem[0];

    Planeta* b_iterator;
    b_iterator = planetas_armazenados_em_ordem[0] + (b_inicio - a_inicio); 

    //Criando pontos de parada
    Planeta* a_final_memoria_auxiliar;
    a_final_memoria_auxiliar = planetas_armazenados_em_ordem[0] + (a_final - a_inicio);

    Planeta* b_final_memoria_auxiliar;
    b_final_memoria_auxiliar = planetas_armazenados_em_ordem[0] + (b_final - a_inicio); 

    bool flag = true;
    int cnt = 0;
    Planeta* fake_inicio;

    cout<<"ENTRANDO LOOP"<<endl;
    while(flag){
      cout<<"Loop Interno Unindo: "<<cnt<<endl;

      cout<<"Memoria Auxiliar Antes"<<endl;

      cout<<"ParteA"<<endl;
      fake_inicio = a_iterator;
      while(true){
        if(fake_inicio == a_final_memoria_auxiliar){
          break;
        }
        cout<<fake_inicio->getTempoVisita()<<" ";
        fake_inicio++;
      }

      cout<<"ParteB"<<endl;
      fake_inicio = b_iterator;
      while(true){
        if(fake_inicio == b_final_memoria_auxiliar){
          break;
        }
        cout<<fake_inicio->getTempoVisita()<<" ";
        fake_inicio++;
      }
      cout<<"\n"<<endl;

      if(a_iterator == a_final_memoria_auxiliar){
        *(a_inicio + cnt) = *b_iterator;
        b_iterator++;
      }else if(b_iterator == b_final_memoria_auxiliar){
        *(a_inicio + cnt) = *a_iterator;
        a_iterator++;
      }else{
        if(a_iterator->getTempoVisita() >= b_iterator->getTempoVisita()){
            *(a_inicio + cnt) = *a_iterator;
            a_iterator++;
        }else{
            *(a_inicio + cnt) = *b_iterator;
            b_iterator++;
        }
      }    
      cout<<"Memoria Auxiliar Depois"<<endl;

      cout<<"ParteA"<<endl;
      fake_inicio = a_iterator;
      while(true){
        if(fake_inicio == a_final_memoria_auxiliar){
          break;
        }
        cout<<fake_inicio->getTempoVisita()<<" ";
        fake_inicio++;
      }

      cout<<"ParteB"<<endl;
      fake_inicio = b_iterator;
      while(true){
        if(fake_inicio == b_final_memoria_auxiliar){
          break;
        }
        cout<<fake_inicio->getTempoVisita()<<" ";
        fake_inicio++;
      }
      cout<<"\n"<<endl;

      cnt++;


      if(a_iterator == a_final_memoria_auxiliar && b_iterator == b_final_memoria_auxiliar){
        flag=false;
      }
    }
  
    cout<<"Fez o loop"<<endl;
    //Liberando espaço usado como memoria auxiliar
    for(int i=tamanho; i<=0; i++){
      delete (planetas_armazenados_em_ordem + i);
    }

    cout<<"deletou a porra toda"<<endl;
} 


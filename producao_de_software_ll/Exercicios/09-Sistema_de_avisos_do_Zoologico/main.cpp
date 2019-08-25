#include <iostream>
#include <map>

#include "Animal.hpp"

using namespace std;


void imprimindoAlertas(	map<string, Animal> animais, map<string, Animal> nomesAnimaisPerderamMuitoPeso, int hoje){
		//Verificacao de animais acima do peso
			for(auto animal : nomesAnimaisPerderamMuitoPeso){
				cout<<"Semana "
				    <<hoje
				    <<": Aviso! Animal "
				    <<animal.first
				    <<" perdeu 10% ou mais de seu peso."
				    <<endl;
			}	
			//Animais com muito tempo sem pesagem
			for(auto animal : animais){
				if(animal.second.getTempoPesagem(hoje) > 1){
					cout<<"Semana "
					    <<hoje
					    <<": Aviso! Animal "
					    <<animal.first
					    <<" nao foi pesado por "
					    <<animal.second.getTempoPesagem(hoje)
					    <<" semanas."
					    <<endl;


				}
			}
}



int main(){
	
	char entrada;
	int hoje=0;
	string nome;
	int peso;
	map<string, Animal> animais;
	map<string, Animal> nomesAnimaisPerderamMuitoPeso; 

	while(cin>>entrada){
		//Troca de semana
		if(entrada=='S'){
			imprimindoAlertas(animais, nomesAnimaisPerderamMuitoPeso, hoje);
			
			//Limpando controle de animais que emagreceram muito
			nomesAnimaisPerderamMuitoPeso.clear();
			//Atualizando à nova data
			cin >> hoje;

		}else if(entrada == 'P'){
			cin >> nome;
			cin >> peso;
			
			if(animais.count(nome)){
				float porcentagem = peso/(animais[nome].getPeso());
				if(porcentagem <= 0.9){
					nomesAnimaisPerderamMuitoPeso[nome]=animais[nome];
				}
			       	animais[nome].setPeso(peso, hoje);	
			}else{
				Animal objectAnimal;
				animais[nome] = objectAnimal;
			       	animais[nome].setPeso(peso, hoje);	
			}

		}else{
			cout<<"Entrada inválida"<<endl;
		}

	}


	imprimindoAlertas(animais, nomesAnimaisPerderamMuitoPeso, hoje);
	return 0;
}

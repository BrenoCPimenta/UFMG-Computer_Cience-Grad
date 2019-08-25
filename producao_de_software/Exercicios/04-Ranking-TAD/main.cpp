#include "Estudante.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

//Retornar a posição descresecnte de valores dentro de um array
void ordenar(float valores[3], int &disposicao0, int &disposicao1, int &disposicao2){

    if(valores[0] < valores[1]){
        if(valores[1] < valores[2]){
            disposicao0=2;
            disposicao1=1;
            disposicao2=0;
        }else{
            if(valores[0] < valores[2]){
                disposicao0=1;
                disposicao1=2;
                disposicao2=0;
            }else{
                disposicao0=1;
                disposicao1=0;
                disposicao2=2;
            }
        }
    }else{
        if(valores[0] < valores[2]){
            disposicao0 = 2;
            disposicao1 = 0;
            disposicao2 = 1;
        }else{
            if(valores[1] < valores[2]){
                disposicao0=0;
                disposicao1=2;
                disposicao2=1;
            }else{
                disposicao0=0;
                disposicao1=1;
                disposicao2=2;
            }
        }
    }
    
}


int main(){
	Estudante *estudante_em_analise = new Estudante;

	Estudante *estudantes_top = new Estudante[3];
	
	int posicao[3] = {0,0,0};
	float rsg[] = {-1.0, -1.0, -1.0};
    float *menor_rsg = nullptr;
    Estudante *menor_estudante = nullptr;
    
	int i;
	int j;
	for(i=0; i<10; i++){
		//Lendo a entrada do estudante
		cin >> estudante_em_analise->matricula
		    >> estudante_em_analise->nome;

		for(j=0; j<5; j++){
			cin >> estudante_em_analise->notas[j];
		}


        //Apontando para o menor rsg dos 3 tops
        if(menor_rsg == nullptr){
            if(rsg[0] < rsg[1]){
                if(rsg[0] < rsg[2]){
                    menor_rsg = &rsg[0];
                    menor_estudante = &estudantes_top[0];
                } else {
                    menor_rsg = &rsg[2];
                    menor_estudante = &estudantes_top[2];
                }
            } else{
                if(rsg[2] < rsg[1]){
                    menor_rsg = &rsg[2];
                    menor_estudante = &estudantes_top[2];
                }else{
                    menor_rsg = &rsg[1];
                    menor_estudante = &estudantes_top[1];
                }
            }
        }
        
		//Caso o RSG do aluno em analise seja maior do que o menor rsg dos tops
		if(*menor_rsg < estudante_em_analise->calcularRSG()){
		    *menor_rsg = estudante_em_analise->calcularRSG();
		    *menor_estudante = *estudante_em_analise;
		    menor_rsg = nullptr;
		    menor_estudante = nullptr;
		}
		//Caso de rsg iguais, comparacao de matriculas
		else if(*menor_rsg == estudante_em_analise->calcularRSG()){
		    if(menor_estudante->matricula > estudante_em_analise->matricula){
    		    *menor_estudante = *estudante_em_analise;
		    }
		}
		
		
	}

    ordenar(rsg, posicao[0], posicao[1], posicao[2]);
	
	cout << fixed;
	for(i=0; i<3; i++){
		cout << estudantes_top[ posicao[i] ].matricula << " " 
		     << estudantes_top[ posicao[i] ].nome << " "
		     << setprecision(2) << rsg[ posicao[i] ] << endl;
	}
	
	menor_rsg = nullptr;
    menor_estudante = nullptr;
    delete menor_rsg;
    delete menor_estudante;
	delete estudante_em_analise;
	delete[] estudantes_top;
	

	return 0;
}
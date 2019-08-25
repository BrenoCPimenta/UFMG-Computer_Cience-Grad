/*	Codigo para calculo de entrada e saida de cofrinhos
 *	Breno de Castro Pimenta
 *	UFMG - 05/10/2017
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[]){

	int bln, i, w, l, cnt, aux;
	int N, J, Z, parcial;

	char entrada[11], Jchar[5], Zchar[5];

	bln = 1;    //TRUE
	cnt = 0;


	//Repeticao enquanto "N" nao eh zero
	while(bln){
		scanf("%d",&N);


		//Analisa se o "N" eh zero para finalizar programa
		if(N<=0){
			bln = 0;   //FALSE


		}else{
			//Imprime e enumera o teste
			cnt++;
			printf("Teste %d\n", cnt);


			//Repeticao para as entradas dos valores
			for(i=0 ; i<N ; i++){
				scanf("%s",&entrada[11]);


				//Separa-se a parte do J
				//E encontra-se o ponto da divisao pelo espaco
				for(w=0;w<11;w++){
					if(entrada[w]==' '){
						aux=w+1;
						w=11;
					}else{
						Jchar[w]=entrada[w];
					}
				}


				//Agora separamos o valor ao Z
				for(l=0; l<11 ; l++){
					Zchar[l]=entrada[aux+l];
				}


				//Transforma as partes das strings em int e faz o balanco
				J = atoi(Jchar);
				Z = atoi(Zchar);

				parcial += J-Z;
				printf("\n%d\n",parcial);

			}

			//Zerando o balanco p/ novos calculos
			parcial=0;
			printf("\n");
		}
	}

	return 0;
}







/*
*	Breno de Castro Pimenta
*	UFMG 04/12/17
*	Programa para encontrar o abacaxi com melhor custo beneficio
*/

#include <stdio.h>
#include <stdlib.h>

void funcaoAbacaxis(int N){
		
		int aux,i;
		float maior = 0;
		typedef struct tipoAbacaxi{int Ad; float Ap; float Vc; float Ag;}abacaxi;

		abacaxi abas[N];
                //Lendo Ad's
                for(i=0; i<N; i++){
                        scanf("%d", &abas[i].Ad);
                }
                //Lendo Ap's
                for(i=0; i<N; i++){
                        scanf("%f", &abas[i].Ap);
                }
                //Lendo Vc's
                for(i=0; i<N; i++){
                        scanf("%f", &abas[i].Vc);
                }
                //Calculando os Ag's
                for(i=0; i<N; i++){
                        abas[i].Ag=(float)((abas[i].Ad*abas[i].Vc)/abas[i].Ap);
                }
                //Encontrando o melhor abacaxi
                for(i=0;i<N;i++){
                        if(abas[i].Ag>maior){
                                maior=abas[i].Ag;
                                aux=i;
                        }
                }
                //Imprimindo o melhor abacaxi
                printf("%d %.2f %.5f %.5f\n", abas[aux].Ad, abas[aux].Ap, abas[aux].Vc, abas[aux].Ag);
}


int main(char argc, char* argv[]){

	int N;
	
	scanf("%d", &N);

	while(N!=0){
		funcaoAbacaxis(N);
		scanf("%d", &N);
	}
	return 0;
}

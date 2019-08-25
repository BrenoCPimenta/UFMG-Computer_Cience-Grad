/*
*	Breno de Castro Pimenta
*	UFMG 04/12/2017
*	Programa para processar ligacoes
*/

#include <stdio.h>
#include <stdlib.h>



int main(char argc, char* argv[]){

	int N;
	int L;
	int i;
	int bln = 1; //TRUE
	int bln2 = 1; //TRUE
	int cnt=-1;
	int conta0;
	int aux=0;
	int aux2=0;
	
	scanf("%d %d", &N, &L);
	int ligacoes[L];


	//Armazenando ligacoes
	for(i=0;i<L;i++){
		scanf("%d", &ligacoes[i]);
	}

	//Loop por minuto
	while(bln){
	
		//Condicao de parada
		for(i=0;i<L;i++){
			aux2+=ligacoes[i];
		}

		if(aux2==0){
			bln=0;
		}else{
			//Loop por atendente
			for(i=0;i<N;i++){
				bln2=1;
				while(bln2){
					//Caso nao haja mais ligacoes
					if(aux==L){
						bln2=0;
					}else{
						//Caso seja zero pular para a proxima ligacao
						if(ligacoes[aux]==0){
							aux++;
						}else{
							//Se nao for zero subtrair um minuto
							//e passar para o proximo atendente
							ligacoes[aux]=ligacoes[aux]-1;
							aux++;
							bln2=0;
						}
					}
				}
			}
		
		}
		
		aux=0;
		cnt++;
		aux2=0;
	}
	printf("%d",cnt);
	return 0;
}




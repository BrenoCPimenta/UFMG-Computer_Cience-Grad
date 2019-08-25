/*
*	Breno de Castro Pimenta
*	UFMG 04/12/17
*	Programa para calular maior numero possivel a ser processado
*/

#include <stdio.h>
#include <stdlib.h>


int calculadorBits(int Nb){

	if(Nb==1){
		return 2;
	}else{
		return (2 * calculadorBits(Nb-1));
	}
}

int main(char argc, char* argv[]){
	int N, B, limite;
	int i, aux1, aux3;
	char aux2;
	
	scanf("%d %d", &N, &B);
		
	limite=calculadorBits(B) -1;

	for(i=0;i<N;i++){
		scanf("%d %c %d", &aux1, &aux2, &aux3);
		
		if(aux2=='+'){
			aux1=aux1+aux3;
		}
		if(aux2=='*'){
			aux1=aux1*aux3;
		}

		if(aux1<=limite){
			printf("OK\n");
		}else{
			printf("OVERFLOW\n");
		}
	}


	return 0;
}	

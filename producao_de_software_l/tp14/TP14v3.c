/*
*	Simulador de jogo
*	Breno de Castro Pimenta
*	17-11-2017
*/

#include <stdio.h>
#include <stdlib.h>

int main(char argc, char* argv[]){
	
	int bln=1; //TRUE
	int T, P;
	int Tatual=0;
	int j, i, k, aux, aux1, aux2, aux3, aux4;
	int Ti, Tf, Xp, Yp;
	int posicao[2];
	struct Et{char str[2];} J, mov;

	J.str[0] = 'S';	
	posicao[0]=0;
	posicao[1]=0;

	//Lendo primeiros dados
	scanf("%d %d", &T, &P);
	
	//inicializando array dos portais em relacao ao tempo
	int tmpPos[T+1][16][2];

	//zerando o array (Utilizando 9's)
	for(i=0;i<(T+1);i++){
		for(j=0;j<16;j++){
			tmpPos[i][j][0]=9;	
			tmpPos[i][j][1]=9;
		}
	}

	//lendo e armazenando posicao dos portais em relacao ao tempo
	for(i=0;i<P;i++){
		scanf("%d %d %d %d", &Ti, &Tf, &Xp, &Yp);
		
		for(j=Ti;j<=Tf;j++){
			for(k=0;k<16;k++){
				aux=tmpPos[j][k][0];
				if(aux==9){
					tmpPos[j][k][0]=Xp;
					tmpPos[j][k][1]=Yp;
					k=16;
				}
			}
		}

	}

	//Primeira impressao do Tempo 0, fora do loop
	printf("TEMPO %d (%d, %d): %c\n", Tatual, posicao[0], posicao[1], J.str[0]);
	
	//Mudanca do tempo antes do loop
	Tatual=1;
	
	do{
		//Lendo e passando movimento		
		scanf("%s", &mov.str[0]);
		
		if(mov.str[0]=='B') posicao[1]-=1;

		if(mov.str[0]=='C') posicao[1]+=1;

		if(mov.str[0]=='E') posicao[0]-=1;

		if(mov.str[0]=='D') posicao[0]+=1;
		
		//Comparando para ver se a posicao equivale ao do portal
		for(k=0;k<16;k++){
			aux=tmpPos[Tatual][k][0];
			if(aux!=9){
				aux1=tmpPos[Tatual][k][0];
				aux2=posicao[0];
				aux3=tmpPos[Tatual][k][1];
				aux4=posicao[1];
				if((aux1==aux2)&&(aux3==aux4)){
					J.str[0]='N';
				}	
			}else{
				k=16;
			}
		}

		//Condicoes de termino
		if((Tatual==(T-1))||(J.str[0]=='N')){
			bln=0; //FALSE
		}

		//Impressoes e ajuste do tempo, dentro do loop
		printf("TEMPO %d (%d, %d): %c\n", Tatual, posicao[0], posicao[1], J.str[0]);
		Tatual+=1;

	}while(bln);

	return 0;
}


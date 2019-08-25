/*	Codigo para contagem de pontuacao
*	em um jogo de 4 jogadores
*	Breno de Castro Pimenta
*	UFMG - 24/10/2017
*/

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {
	int jogador, C, V;
	int bln=1; //TRUE
	int d[4]={0,0,0,0};
	//int *J=d[0], *Z=d[1], *P=d[2], *M=d[3];

	scanf("%d",&jogador);

	while(bln){
		scanf("%d %d",&C,&V);
		if(C==1){
			jogador=V;
		}if(C==2){
			d[jogador-1]+=V;
			if(d[jogador-1]<0)d[jogador-1]=0;
		}

		if(C==0&&V==0){
			bln=0;
		}else{
		
			switch(jogador){
				case 1:
					printf("Joaozinho ");
					break;
				case 2:
					printf("Zezinho ");
					break;
				case 3:
					printf("Pedro ");
					break;
				case 4:
				printf("Maria ");
				break;
			}
			printf("%d x %d x %d x %d\n", d[0], d[1], d[2], d[3]);
		}
	}





  return 0;
}


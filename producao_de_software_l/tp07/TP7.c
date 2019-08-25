/*	Programa que faz a media de valores dentro de Matrizes
*	Breno de Castro Pimenta
*	UFMG - 26/10/2017
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv){

	int  Nmatrizes, Linhas, Colunas;
	int somatorio, i, j, k;

	scanf("%d", &Nmatrizes);
	scanf("%d %d", &Linhas, &Colunas);

	int d[Nmatrizes][Linhas][Colunas];
	double media[Linhas][Colunas]; 

	for(i=0;i<Nmatrizes;i++){
		for(j=0;j<Linhas;j++){
			for(k=0;k<Colunas;k++){
				scanf("%d", &d[i][j][k]);

			}
		}
	}

	 for(i=0;i<Nmatrizes;i++){
                for(j=0;j<Linhas;j++){
                        for(k=0;k<Colunas;k++){
                                scanf("%d", &d[i][j][k]);
				media[j][k]+=d[i][j][k];

                        }
                }
        }

	for(j=0;j<Linhas;j++){
		for(k=0;k<Colunas;k++){
			media[j][k]/=Nmatrizes;
		}
	}

	for(j=0;j<Linhas;j++){
		for(k=0;k<Colunas;k++){
			printf("%.2f ", media[j][k]);
		}
		printf("\n");
	}

}

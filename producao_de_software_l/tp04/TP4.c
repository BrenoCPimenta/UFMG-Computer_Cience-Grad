/*	Codigo para impressao do programa Poodle
*	Breno de Castro Pimenta
*	UFMG - 20/10/2017
*/

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {
	int N, P, i, j;
	int bln = 1; //TRUE

	while(bln){

		scanf("%d %d", &N, &P);

		if((P==0)||(N==0)){
			bln=0;
		}else{
			j=N/P;
			if((N%P)!=0)j++;

			printf("P");

			for(i=0;i<j;i++)printf("o");

			printf("dle\n");
		}
	}
  return 0;
}


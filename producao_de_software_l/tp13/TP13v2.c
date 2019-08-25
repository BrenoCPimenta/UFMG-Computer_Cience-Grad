/*
*       Programa para encontrar range em posicoes
*       Breno de Castro Pimenta
*       16-11-17
*/

#include <stdio.h>
#include <stdlib.h>


int main(char argc, char* argv[]){

    int fim;
	int P, V, S;
	int bln = 1; //TRUE
	int vagasI, vagasF, rangeI, rangeF;
	int i, j, aux, cnt, cnt2;
	
	
	while(bln){
		//Lendo primeiras entradas
		scanf("%d %d %d", &P, &S, &V);
		
		//Zerando a distancia da praia e contadores
		int praia[P];
		for(i=0;i<P;i++) praia[i]=0;
		cnt=0;
		cnt2=0;

		if((P==0)&&(P==S)&&(P==V)){
			bln=0; //FALSE
		}else{
			//Lendo e passando area dos sorveteiros
			for(i=0;i<S;i++){
				scanf("%d %d", &rangeI, &rangeF);
				for(j=rangeI;j<=rangeF;j++){
					 praia[j]=1;
				}
			}
		
			//Lendo e retirando area sem vagas
			for(i=0;i<V;i++){
				scanf("%d %d",  &vagasI, &vagasF);
				for(j=vagasI;j<=vagasF;j++){
					 praia[j]=0;
				}
			}

			//Imprimindo area com sorvete e vagas
			for(i=0;i<P;i++){
				if(praia[i]==1){
				    if(i==(P-1)){
				        printf("%d\n", i);
				    }
					if(cnt==0){
						printf("%d ", i);
					}
					cnt+=1;
				}else{
					/*if((cnt!=0)&&(cnt!=1)){
						printf("%d\n", j);
					}
					if(cnt==1) printf("\n");*/
					if(cnt != 0){
						aux=i-1;
						printf("%d\n", aux);
					}						
					cnt=0;
					cnt2+=1;
				}					
			}
				
			//Condicao caso nao haja vagas
			if(cnt2==P) printf("Nao ha vagas\n");
		}
	}
	return 0;
}			






			











#include <stdio.h>
#include <stdlib.h>

int main(char argc, char* argv[]){

	char base[1000];
	int bln = 1; //TRUE
	int cnt = 0;
	int cnt2 =0;
	int i=0;
	

	//Inicializando arranjo 	
	for(i=0; i<1000 ; i++){
		base[i] = 'a';
	}
	base[1000]='\0';
	
	//Lendo arranjo
	scanf("%s", base);
	
	
	//Separando como string a entrada
	while(bln){
		
		if(base[cnt]=='a'){
			base[cnt]='\0';
			bln=0; //FALSE
		}
	 	cnt++;
	}
	
	//Imprimindo a primeira entrada
	printf("%s\n",base);
	
	//Imprimindo proximas linhas
	for(i=0; i<1000; i++){
		
		//Caso da parada
		if(base[i+1]=='\0'){
			if(cnt2==1){
				i=1000;
			}else{
				printf("\n");
				base[i]='\0';
				i=-1;
				cnt2=0;
			}
		}else{
			cnt2++;
			//Caso a atual e a proxima sejam iguais
			if(base[i]==base[i+1]){
				printf("x");
				base[i]='x';
			}else{
			//Caso a atual e a proxima sejam diferentes 
				printf("o");
				base[i]='o';
			}
		}
	}
	return 0;
}

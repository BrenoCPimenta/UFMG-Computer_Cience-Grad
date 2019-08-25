/*
*	Programa para contabilizar diferenca entre horas
*	Breno de Castro Pimenta
*	UFMG 14/11/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Funcao para transformar horas em segundos
int transformandoSeg(int hora, int minuto, int segundo){
	int minAux;
	minAux= (hora*60) + minuto;
	int segTotais= (minAux*60)+segundo;
	return segTotais;
}


int main(char argc, char* argv[]){
	int h1,m1,s1,h2,m2,s2;
	int hF,mF,sF;
	int horaI, horaF, diferenca, tempo;
	int bln = 1;

	/*int n = 60;
	int j = transformandoSeg(1,n,0);
	printf("%d\n",j);*/

	while(bln){
		//Lendo horas iniciais e finais
		scanf("%d %d %d %d %d %d", &h1,&m1,&s1,&h2,&m2,&s2);

		//Conferindo se eh a finalizacao do programa
		if((h1==-1)&&(m1==-1)&&(s1==-1)&&(h2==-1)&&(m2==-1)&&(s2==-1)){
			bln=0;
		}else{



			//Tranforma as horas em segundos
			horaI = transformandoSeg(h1,m1,s1);
			horaF = transformandoSeg(h2,m2,s2);

			//Regularizando 24 horas
                        if(horaF<horaI)horaF=horaF+(24*60*60);

			//Encontrando a diferenca
                        diferenca = horaF - horaI;
			hF= (diferenca/60)/60;
			mF= (diferenca/60)%60;
			sF= diferenca%60;

			printf("%02d:%02d:%02d\n",hF,mF,sF);
		}
	}
	return 0;
}

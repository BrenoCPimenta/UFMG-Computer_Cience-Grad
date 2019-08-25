/*
*	Calcular coordenadas em detrimento de um ponto
*	Breno de Castro Pimenta
*	UFMG 15-11-2017
*/

#include <stdio.h>
#include <stdlib.h>


int main(char argc, char* argv[]){
	

	int n, i;
	float  Cx, Cy, Px, Py;

	//Lendo quantidade de coordenadas e coordenadas do ponto referencia
	scanf("%d %g %g", &n, &Px, &Py);

	//Loop de impressao
	for(i=0;i<n;i++){
		//lendo coordenadas
		scanf("%g %g", &Cx, &Cy);
		
		//Comparacao para definir qual cidade
		if(Cy>Py)printf("S");
		if(Cy<Py||Cy==Py)printf("N");
		
		if(Cx>Px||Cx==Px)printf("E\n");
		if(Cx<Px)printf("O\n");
	}

	return 0;
}

#include "Hash.hpp"

using namespace std;

//Calcula um valor a partir de sua numeracao na tabela ASC para ser utilizado em uma tabela hash
int Hash::calculaHash(char* palavra){

	int posicao_tabela;
	int valor_da_palavra = 0;

	for(int i=0; i<63; i++){
		//Verificando final da palavra
		if(int(palavra[i]) < 97 || int(palavra[i]) > 122){
			break;
		}else{
			valor_da_palavra += int(palavra[i]) - 96;
		}
	}

	posicao_tabela = valor_da_palavra % 100000;
	return posicao_tabela;
}

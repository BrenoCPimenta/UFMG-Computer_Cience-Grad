
//#include "lista/Lista.hpp"
//#include "lista/CelulaEspecial.hpp"

#include <iostream>

using namespace std;

int main(){

	long int qtd_palavras;
	//Lista tabela_hash[100000];
	int valor_da_palavra = 0;
	int posicao_tabela;

	cin>>qtd_palavras;
	char palavras[qtd_palavras][63];


	for(int i=0; i<qtd_palavras; i++){
		cin>>palavras[i];
		posicao_tabela = 0;
		valor_da_palavra = 0;

		for(int j=0; j<63; j++){
			if(int(palavras[i][j]) < 97 || int(palavras[i][j]) > 122){
				break;
			}else{
				valor_da_palavra += int(palavras[i][j]) - 97;
			}
		}

		posicao_tabela = valor_da_palavra % 100000;
		/*if(tabela_hash[posicao_tabela].verificarVazia()){
			Lista listaObj = new Lista(palavras[i]);
			tabela_hash[posicao_tabela] = listaObj;
		}else{
			add ao final da fila
		}

		*/
	}


	for(int i=0; i<qtd_palavras; i++){
      cout<<palavras[i]<<endl;
	} 

  	//Loop de escrita
  	char char_I;
  	char palavra_msg[63];


	while(true){
		cin>>char_I;
		if(!cin.good()){
	  		break;
		}
		cin>>palavra_msg;

		if(char_I == 'q'){

		}else if(char_I == 'c'){

		}else{
			break;
		}
	}

	return 0;
}

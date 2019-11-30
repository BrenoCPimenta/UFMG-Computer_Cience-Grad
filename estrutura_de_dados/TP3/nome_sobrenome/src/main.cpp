#include "hash/Hash.hpp"
#include "lista/CelulaEspecial.hpp"
#include "lista/Lista.hpp"

#include <iostream>

using namespace std;

int main(){

	long int qtd_palavras;
	Hash hashObj;
	int posicao_tabela;
	Lista tabela_hash[100000];


	cin>>qtd_palavras;
	char palavras[qtd_palavras][63];

	
	for(int i=0; i<qtd_palavras; i++){
		cin>>palavras[i];
		posicao_tabela = hashObj.calculaHash(palavras[i]);
		
		 if( ! tabela_hash[posicao_tabela].verificarSePossuiPalavra(palavras[i])) {
			tabela_hash[posicao_tabela].addPalavra(palavras[i]);
		}else{
			tabela_hash[posicao_tabela].getPalavra(palavras[i])->somaUmRepeticao();
		}
	}


	char character;
	char palavra_leitura[63];
	while(true){
		cin>>character>>palavra_leitura;
		if(!cin.good()){
	  		break;
		}

		if((int)character == (int)'q'){
			posicao_tabela = hashObj.calculaHash(palavra_leitura);
			cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getRepeticao()<<endl;
		}

	}

  for(int i=0; i<10000; i++){
    tabela_hash[i].esvaziar();
  } 

	return 0;
}

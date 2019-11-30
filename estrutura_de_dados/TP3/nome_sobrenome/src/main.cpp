#include "hash/Hash.hpp"
#include "lista/CelulaEspecial.hpp"
#include "lista/Lista.hpp"
//#include "arvore/Arvore.hpp"
//#include "arvore/No.hpp"
//#include "arvore/ControleArvore.hpp"

#include <iostream>

using namespace std;

int main(){

	long int qtd_palavras;
	Hash hashObj;
	int posicao_tabela;
	Lista tabela_hash[100000];


	cin>>qtd_palavras;
	char palavras[qtd_palavras][63];


  int qtd_posicoes_tabela = 0;
  int posicoes[qtd_palavras];
  for(int i=0; i<qtd_palavras;i++){
    posicoes[i]=-1;
  }
	
	for(int i=0; i<qtd_palavras; i++){
		cin>>palavras[i];
		posicao_tabela = hashObj.calculaHash(palavras[i]);
		
    //Add palavra à tabela ou somando repeticao
		if( ! tabela_hash[posicao_tabela].verificarSePossuiPalavra(palavras[i])) {
			tabela_hash[posicao_tabela].addPalavra(palavras[i]);
		}else{
			tabela_hash[posicao_tabela].getPalavra(palavras[i])->somaUmRepeticao();
		}

    //Armazenando posicoes para a codificao de Huffman
    for(int j=0; j<i; j++){
      if(posicoes[j]==-1){
        posicoes[j]=posicao_tabela;
        qtd_posicoes_tabela++;
      }else if(posicoes[j]==posicao_tabela){
        break;
      }
    }
	}

  /*
  //Criando Arvores
  Arvore arvores[qtd_posicoes];
  Lista listaObj();
  char palavraDaVez[63];
  int repeticaoDaVez;
  int qtd_arvores = 0;

  for(int i=0;i<qtd_posicoes_tabela;i++){
    listaObj = tabela_hash[posicoes[i]];
    tamanho = listaObj.getTamanho();
    for(j=0; j<tamanho;j++){
      palavraDaVez = listaObj.getPalavra(j)->getNome(); 
      repeticaoDaVez = listaObj.getPalavra(j)->getRepeticao(); 
      arvores[i+j].addNo(palavraDaVez, repeticaoDaVez);
      qtd_arvores++;
    }
  }

  //Primeira ordenacao
  ControleArvore controle();
  controle.ordenar(arvores);
  controle.juntandoArvores(arvores);
  controle.construindoCodigo(arvores[0]);
  controle.passandoCodigo(tabela_hash, arvores[0]);
  */

  

	char character;
	char palavra_leitura[63];
	while(true){
		cin>>character>>palavra_leitura;
		if(!cin.good()){
	  		break;
		}

		posicao_tabela = hashObj.calculaHash(palavra_leitura);

		if((int)character == (int)'q'){
			cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getRepeticao()<<endl;
		}

    if((int)character == (int)'c'){
			//cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getCodigo()<<endl;
		}

	}


  for(int i=0; i<10000; i++){
    tabela_hash[i].esvaziar();
  } 

	return 0;
}

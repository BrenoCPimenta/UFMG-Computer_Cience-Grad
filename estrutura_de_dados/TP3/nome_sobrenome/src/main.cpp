
#include "hash/Hash.hpp"
#include "lista/CelulaEspecial.hpp"
#include "lista/Lista.hpp"

#include <typeinfo>
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


	for(int i=0; i<qtd_palavras; i++){
		posicao_tabela = hashObj.calculaHash(palavras[i]);
		cout<< tabela_hash[posicao_tabela].getPalavra(palavras[i])->getNome();
		cout<< tabela_hash[posicao_tabela].getPalavra(palavras[i])->getRepeticao()<<endl;
	}


	char character;
	char palavra_leitura[63];
	int cnt = 0;
	/*
	while(cnt < 5){
		cin>>character>>palavra_leitura;

		if((int)character == (int)'q'){
			posicao_tabela = hashObj.calculaHash(palavra_leitura);
			cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getNome();
			cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getRepeticao()<<endl;
		}

		cnt++;
	}*/
	while(true){
		cin>>character>>palavra_leitura;
		if(!cin.good()){
	  		break;
		}

		if((int)character == (int)'q'){
			posicao_tabela = hashObj.calculaHash(palavra_leitura);
			cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getNome();
			cout<< tabela_hash[posicao_tabela].getPalavra(palavra_leitura)->getRepeticao()<<endl;
		}

	}

	return 0;
}
/*
	posicao_tabela = hashObj.calculaHash(palavras[0]);
	cout<<tabela_hash[posicao_tabela].getPalavra(palavras[0])->getRepeticao()<<endl;
*/


/*
  	//Loop de escrita
  	char char_I;
  	char palavra_msg[63];

  	int posicao_final;

  	

	while(true){
		cin>>char_I>>palavra_msg;
		if(!cin.good()){
	  		break;
		}
		

		if(char_I == 'q'){
			cout<<"ENTROU"<<endl;

			posicao_final = hashObj.calculaHash(palavra_msg);
			CelulaEspecial* cel = tabela_hash[posicao_final].getPalavra(palavra_msg);
			cout<<  cel->getRepeticao() << endl;
		}else if(char_I == 'c'){

		}else{
			break;
		}
		cout<<"SAIU"<<endl;
		break;
	}

	return 0;

}


/*
if(tabela_hash[posicao_tabela].verificarVazia()){
			Lista listaObj;
			listaObj.addPalavra(palavras[i]);
			tabela_hash[posicao_tabela] = listaObj;
		}else

		*/






/*
		TESTE
----------------------------------------------------------------------------------------------------------------------------------

	cin>>palavras[0];
	posicao_tabela = hashObj.calculaHash(palavras[0]);

	

	cout<<"\nTESTE VAZIA1"<<endl;
	Lista listaObj;
	if(listaObj.verificarVazia()){
		cout<<"esvaziou"<<endl;
	}

	cout<<"\nTESTE VAZIA2"<<endl;
	if(tabela_hash[38].verificarVazia()){
		cout<<"esvaziou"<<endl;
	}
	

	cout<<"\nTESTE CRIANDO CelulaEspecial"<<endl;
	CelulaEspecial* cel = new CelulaEspecial(palavras[0]);

	cout<<"\nTESTE pegando nome CelulaEspecial"<<endl;
	cout<<cel->getNome()<<endl;

	cout<<"\nTESTE pegando REPETICAO INICIAL CelulaEspecial"<<endl;
	cout<<cel->getRepeticao()<<endl;

	cout<<"\nTESTE SOMANDO REPETICAO CelulaEspecial"<<endl;
	cout<<cel->somaUmRepeticao()<<endl;

	cout<<"\nTESTE pegando REPETICAO final CelulaEspecial"<<endl;
	cout<<cel->getRepeticao()<<endl;


	cout<<"\nTESTE SALVANDO PALAVRA EM SUA POSICAO NA TABELA"<<endl;
	
	
	if(!tabela_hash[posicao_tabela].verificarSePossuiPalavra(palavras[0])){
		cout<<"Verificou que nao tem"<<endl;
	}

	if(tabela_hash[posicao_tabela].addPalavra(palavras[0])){
		cout<<"adicionou"<<endl;
	}
	if(tabela_hash[posicao_tabela].verificarSePossuiPalavra(palavras[0])){
		cout<<"Verificou que tem"<<endl;
	}

	cout<<"\nTESTE BUSCANDO O NOME PELA TABELA"<<endl;
	delete cel;
	cel = tabela_hash[posicao_tabela].getPalavra(palavras[0]);
	cout<<cel->getNome()<<endl;


	cout<<"\nTESTE BUSCANDO REPETICAO"<<endl;
	cout<<cel->getRepeticao()<<endl;

	cel->somaUmRepeticao();

	cout<<cel->getRepeticao()<<endl;

	return 0;
------------------------------------------------------------------------------------------------------------------------------------







//cin>>palavra_msg;
		/*
		cout<<"I: "<<char_I<<endl;
		cout<<"Palavra "<<palavra_msg<<endl;
		cout<<"TIPO I:  "<< typeid(char_I).name() << endl;
		*/





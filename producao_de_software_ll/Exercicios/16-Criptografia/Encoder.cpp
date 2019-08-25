 #include "Encoder.hpp"
 #include <iostream>
 #include <string>

namespace Encoder
{
	Enc::Enc(std::string cifra) : _cifra(cifra) {}

	short int indice_substiuto(char a);

	void Enc::EncodeMessage(std::string mensagem)
	{
		short int indice;
		for(unsigned i = 0; i < mensagem.size(); i++)
		{
			indice = indice_substiuto( mensagem[i]);
			if( indice != -1 )
			 	_cifrada.push_back( _cifra[indice] );
			else
				_cifrada.push_back( mensagem[i] );
		}
		mensagemCifrada = _cifrada;
	}

	std::string Enc::obter_cifra()
	{
		return this->_cifra;
	}

	/* func avulsa */
	short int indice_substiuto(char a)
	{
		/* ref = {a,b,c,...,x,y,z,0,1,2,...,7,8,9} */
		if(a >= 97 && a <= 122) /* checa se esta no conjunto ref   				 */
			return a - 97;	    /* retorna o indice para usar no conjunto _cifra */

		if(a >= 48 && a <= 57)
			return a - 48 + 26;

		return -1;
	}

	/* funcoes definidas no hpp dentro do namespace Encoder */
	void print()
	{
		std::cout<<"Encoded message: "<< mensagemCifrada <<std::endl;
	}

	std::string getMessage() /* retornar desse namespace para a main */
	{
		return mensagemCifrada;
	}


	std::string mensagemCifrada = "";
}


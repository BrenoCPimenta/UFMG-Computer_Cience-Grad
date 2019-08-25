#include "Decoder.hpp"

using namespace Decoder; /* obs: mah pratica, usar apenas em programas simples */

Dec::Dec(Encoder::Enc* encPtr) : _encPtr(encPtr) {}

void  Dec::DecodeMessage(std::string mensCifrada)
{
	short int indice;
	std::string cifraAux;

    cifraAux = _encPtr->obter_cifra();
	for(unsigned i = 0; i < mensCifrada.size(); i++)
	{
		indice = cifraAux.find( mensCifrada[i]); /* obs: decifrar eh mais custos que cifrar */

		if( indice != -1 )
		 	_mensagemNormal.push_back(_ref[indice]);
		else
			_mensagemNormal.push_back(mensCifrada[i]);
	}

	mensagemNormal = _mensagemNormal; /* exportar para a variavel visivel no namespace Decoder */
}

std::string Decoder::mensagemNormal = ""; /* obs: obrigatoriedade de declaracao explicita */
                                          /* para variaveis e funcoes pertencentes a um   */
void Decoder::print()                     /* determinado namespace                        */
{
	std::cout<<"Decoded message: "<< mensagemNormal<<std::endl;
}


#ifndef ENC_H
#define ENC_H

#include <string>

namespace Encoder
{
	class Enc
	{
		std::string _cifra;
		std::string _cifrada;

	public:
		Enc(std::string cifra);

		void EncodeMessage(std::string mensagemNormal); /* codificar mensagem */

		std::string obter_cifra();
	};

	extern std::string mensagemCifrada; /* definida no cpp */

	void print(); /* imprimir mens cifrada */

	std::string getMessage(); /* /retornar valor mens cifrada */
}
#endif


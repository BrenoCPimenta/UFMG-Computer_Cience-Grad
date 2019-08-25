#ifndef DEC_H
#define DEC_H

#include <string>
#include <iostream>
#include "Encoder.hpp"

namespace Decoder
{
	class Dec
	{
		Encoder::Enc* _encPtr;
		std::string _mensagemNormal;
		std::string _ref = "abcdefghijklmnopqrstuvwxyz0123456789" ;

	public:
		Dec(Encoder::Enc* encPtr);

		void DecodeMessage(std::string mensCifrada); /* decodificar mensagem cifrada */
	};

	extern std::string mensagemNormal;

	void print();
}

#endif

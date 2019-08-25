#ifndef JOGOS_H
#define JOGOS_H

#include <string>
#include <iostream>
#include <map>
using namespace std;

class jogo{
	private:
		string _nome;
	public:
		map<string, string> generos;
	//	static int numGeneros = 7;

		jogo(string nome);
		string getNome();
		void imprimeNome();
		void imprimeCaracteristicas();

};

class AFP : public jogo{
	public:
		AFP(string nome);
};

		
class jogoAction : public AFP{
	public:
		jogoAction(string nome);
};

class jogoFPS : public AFP{
	public:
		jogoFPS(string nome);
};

class jogoPlatform : public AFP{
	public:
		jogoPlatform(string nome);
};




class RMR : public jogo{
	public:
		RMR(string nome);
};

class jogoRPG : public RMR{
	public:
		jogoRPG(string nome);
};

class jogoMMORPG : public RMR{
	public:
		jogoMMORPG(string nome);
};

class jogoRoguelike : public RMR{
	public:
		jogoRoguelike(string nome);
};

class jogoRTS : public jogo{
	public:
		jogoRTS(string nome);
};

class jogoSports : public jogo{
	public:
		jogoSports(string nome);
};

#endif

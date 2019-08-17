#include "jogos.hpp"
using namespace std;

//-----------------JOGOS--------------------
jogo::jogo(string nome):_nome(nome){}

string jogo::getNome(){
	return this->_nome;
}

void jogo::imprimeNome(){
	cout<< this->getNome()<<endl;
}

void jogo::imprimeCaracteristicas(){
	for(auto& it : this->generos){
		if(it.second != ""){
			cout<<it.second<<endl;
		}
	}
}


//-----------------AFP
     
AFP::AFP(string nome):jogo(nome){
	this->generos["habilidade"]="Habilidade HabilidadeMotora";
	this->generos["tempo"]="TempoReal Sim";
}
	
		
//---------------ACTION------------------
jogoAction::jogoAction(string nome):AFP(nome){}


//---------------FPS--------------------
jogoFPS::jogoFPS(string nome):AFP(nome){
	this->generos["perspectiva"]="Perspectiva Primeira";
}

//---------------PLATFORM--------------------
jogoPlatform::jogoPlatform(string nome):AFP(nome){
	this->generos["perspectiva"]="Perspectiva Terceira";
}





//---------------RMR
RMR::RMR(string nome):jogo(nome){
	this->generos["roleplay"]="RolePlay Sim";
}


//-------------------RPG----------------
jogoRPG::jogoRPG(string nome):RMR(nome){}


//-------------------MMORPG------------
jogoMMORPG::jogoMMORPG(string nome):RMR(nome){
	this->generos["online"]="Online Sim";
	this->generos["tempo"]="TempoReal Sim";
}

//------------------ROGUELIKE-----------
jogoRoguelike::jogoRoguelike(string nome):RMR(nome){

	this->generos["geracao"]="GeracaoProcedural Sim";
	this->generos["tempo"]="TempoReal Nao";
}

//----------------------RTS-------------
jogoRTS::jogoRTS(string nome):jogo(nome){
	this->generos["habilidade"]="Habilidade RaciocinioLogico";
	this->generos["tempo"]="TempoReal Sim";
}

//--------------------SPORTS-------------
jogoSports::jogoSports(string nome):jogo(nome){
	this->generos["habilidade"]="Habilidade HabilidadeMotora";
	this->generos["simulcao"]="Simulacao Sim";
}




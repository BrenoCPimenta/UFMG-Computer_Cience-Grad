#include "SistemaSolar.hpp"
#include <iostream>

void SistemaSolar::fill(string filename)
{	
	ifstream inp(filename.c_str());

    if (!inp.is_open())
        cout << "Error opening file";
	
    string word;

	while (inp >> word)
	{	if(word == "defastro")
		{	string tipo,nome, gas, orbita, lixo;
			inp >> tipo;
			inp >> nome;
			
			int temp,raio;
			float g;
						
			switch(tipo[0]){
				case 'L': //Lua
					inp >> lixo;
					inp >> orbita;
				case 'E': //Estrela
				case 'P': //Planeta
					inp >> lixo;
					inp >> temp;
					inp >> lixo;
					inp >> raio;
					inp >> lixo;
					inp >> g;
					inp >> lixo;
					inp >> gas;
					break;
			}
			
			if (tipo=="Estrela")
			{	Astro a;
				a.fill(nome,temp,raio,g,gas);			
				estrelas[nome] = a;
			}
			if (tipo=="Planeta")
			{	Planeta a;
				a.fill(nome,temp,raio,g,gas);			
				planetas[nome] = a;
			}
			if (tipo=="Lua")
			{	Astro a;
				a.fill(nome,temp,raio,g,gas);			
				planetas[orbita].luas.push_back(a);
			}
		}
	}
	inp.close();
}


string SistemaSolar::getLargestStar(){
	int size = -1;
	string largest = "";
	
	for (std::map<string,Astro>::iterator it=estrelas.begin(); it!=estrelas.end(); ++it)
    {	int r = it->second.raio;
    	if (r > size)
    	{	size = r;
    		largest = it->first;
		}
	}
	
	return largest;	
}


int SistemaSolar::getTempStar(string star)
{	return estrelas[star].temp;
}


int SistemaSolar::getNumAstros()
{	int luas = 0;	

	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	luas += it->second.luas.size();
	}
	
	return luas + planetas.size() + estrelas.size();
}


int SistemaSolar::getNumPlanetas()
{	return planetas.size();
}

int SistemaSolar::getNumPlanetasSold()
{	int sold = 0;

	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	sold+=bool(it->second.gas=="False");
	}
	return sold;
}

		
float SistemaSolar::getMedLuas()
{	float luas = 0.0;	

	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	luas += it->second.luas.size();
	}
	
	return luas/planetas.size();
}

		
string SistemaSolar::getPlanetaLuas()
{	string pl = "";
	int num = -1;
	
	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	if (num < int(it->second.luas.size()))
    	{	num = int(it->second.luas.size());
    		pl = it->first;
		}
	}
	return pl;
}


string SistemaSolar::getPlanetaQuente()
{	string pl = "";
	int num = -1;
	
	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	if (num < it->second.temp)
    	{	num = it->second.temp;
    		pl = it->first;
		}
	}
	return pl;
}


string SistemaSolar::getPlanetaFrio()
{	string pl = "";
	int num = 999999999;
	
	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	if (num > it->second.temp)
    	{	num = it->second.temp;
    		pl = it->first;
		}
	}
	return pl;
}


string SistemaSolar::getPlanetaMaior()
{	string pl = "";
	int num = -1;
	
	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	if (num < it->second.raio)
    	{	num = it->second.raio;
    		pl = it->first;
		}
	}
	return pl;
}


string SistemaSolar::getPlanetaMenor()
{	string pl = "";
	int num = 999999999;
	
	for (std::map<string,Planeta>::iterator it=planetas.begin(); it!=planetas.end(); ++it)
    {	if (num > it->second.raio)
    	{	num = it->second.raio;
    		pl = it->first;
		}
	}
	return pl;
}
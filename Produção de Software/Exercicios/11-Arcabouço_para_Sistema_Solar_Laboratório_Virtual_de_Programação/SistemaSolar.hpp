#include "Planeta.hpp"
#include "Astro.hpp"
#include <map>
#include <string>
#include <fstream>

using namespace std;

class SistemaSolar{	
    public:
    	void fill(string filename);
    	
		map<string,Planeta> planetas;
		map<string,Astro> estrelas;

		string getLargestStar();
		int getTempStar(string star);
		
		int getNumAstros();
		int getNumPlanetas();
		int getNumPlanetasSold();
		
		float getMedLuas();
		
		string getPlanetaLuas();
		string getPlanetaQuente();
		string getPlanetaFrio();
		string getPlanetaMaior();
		string getPlanetaMenor();

};
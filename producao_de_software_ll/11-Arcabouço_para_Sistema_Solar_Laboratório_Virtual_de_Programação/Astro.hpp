#ifndef ASTRO_H
#define ASTRO_H

#include <string>

using namespace std;

class Astro{
    public:
    	int raio;
    	float gravidade;
    	int temp;
    	string nome;
    	string gas;
			        
        void fill(string nome,int temp,int raio,float g,string gas);
};

#endif

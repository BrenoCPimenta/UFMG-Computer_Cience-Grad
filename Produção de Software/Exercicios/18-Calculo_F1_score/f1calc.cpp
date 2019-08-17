#include "f1calc.hpp"

std::tuple<int,int,int,int,int> F1CALC::processaEntradas(string sTP,string sTN,string sFP,string sFN,string sTotal)
{
	int num;
	std::vector<string> palavras;
	std::vector<int> numeros;

	
	palavras.push_back(sTP);
	palavras.push_back(sTN);
	palavras.push_back(sFP);	
	palavras.push_back(sFN);
	palavras.push_back(sTotal);

    //Assercao para conferencia dos valores de entradas
	for(unsigned i =0; i<palavras.size(); i++){
		for(unsigned j=0; j<palavras[i].size(); j++){
			ASSERT(palavras[i].at(j) >= '0' && palavras[i].at(j) <= '9', "Input validation failed");
		}
	}	
	//Transformando string em int
	for (unsigned i=0; i< palavras.size(); i++){
		istringstream iss(palavras[i]);
		iss>>num;
		numeros.push_back(num);
	}
	
	return make_tuple(numeros[0],numeros[1],numeros[2],numeros[3],numeros[4]);	
}

std::tuple<float,float> F1CALC::calculaPresRecall(int TP,int TN,int FP,int FN,int Total)
{
    //Assercao para pre conferencia das entradas para os calculos da precisao e revocacao 
	ASSERT( (TP+FP)!=0, "Pre-condition failed");
	ASSERT( (TP+FN)!=0, "Pre-condition failed");
	ASSERT(Total == (TP+TN+FP+FN), "Pre-condition failed");

	float fTP = float(TP);
	float precision = fTP/(TP+FP);
	float recall = fTP/(TP+FN);
	
	//Assercao para conferencia das entradas para calculo de f1
	ASSERT(precision!=0 || recall!=0, "Post-condition failed");
	return make_tuple(precision, recall);
}


float F1CALC::calculaF1(float p, float r)
{
	float f1 = (p*r/(p+r))*2;
	return f1;
}


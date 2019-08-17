#include "Circunferencia.hpp"

Circunferencia::Circunferencia(double _x, double _y, double _raio){
	xc = _x;
	yc = _y;
	raio = _raio;
}

double Circunferencia::calcularArea(){
	return k_PI * pow(raio, 2);
}


bool Circunferencia::possuiIntersecao(Circunferencia* c){
	
	double outroX = c->xc;
	double outroY = c->yc;
	double outroRaio = c->raio;

	double xDiferencaPotencias = pow(xc-outroX,2);
	double yDiferencaPotencias = pow(yc-outroY,2);
	double distanciaCentros = sqrt(xDiferencaPotencias + yDiferencaPotencias);
	double somaRaios = raio + outroRaio;

	if(distanciaCentros <= somaRaios){
		return true;
	}
	else{
		return false;
	}
}

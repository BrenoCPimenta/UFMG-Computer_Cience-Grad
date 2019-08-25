#ifndef k_PI
#define k_PI 3.14
#endif

#ifndef CIRCUNFERENCIA
#define CIRCUNFERENCIA

#include <cmath>

struct Circunferencia {
	double xc;
	double yc;
	double raio;

	Circunferencia(double, double, double);
	
	double calcularArea();
	
	bool possuiIntersecao(Circunferencia*);
};

#endif

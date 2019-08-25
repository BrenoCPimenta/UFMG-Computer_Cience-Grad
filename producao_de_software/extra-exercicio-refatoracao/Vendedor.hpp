#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include "Empregado.hpp"

class Vendedor : public Empregado {
    private:
        double _quotaMensalVendas;
    public:
        Vendedor(std::string nome, double salarioHora, double quotaMensalVendas);
	
        void printInfo(double horasTrabalhadas) override;
};

#endif

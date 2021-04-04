#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <iostream>
#include <string>

class Empregado {
    private:
        std::string _nome;
        double _salarioHora;  

    public:
        Empregado(std::string nome, double salarioHora);

        double pagamentoMes(double horasTrabalhadas);
        std::string getNome();
        virtual void printInfo(double horasTrabalhadas)=0;
};

#endif

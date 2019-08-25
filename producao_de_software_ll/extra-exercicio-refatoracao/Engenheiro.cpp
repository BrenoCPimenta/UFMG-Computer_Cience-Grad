#include "Engenheiro.hpp"

Engenheiro::Engenheiro(std::string nome, double salarioHora, int projetos): Empregado(nome, salarioHora), _projetos(projetos){}

void Engenheiro::printInfo(double horasTrabalhadas){
    double pagamento = this->pagamentoMes(horasTrabalhadas);
    std::cout<<"Nome: "<<this->getNome()<<std::endl;
    std::cout<<"Salario Mes: "<<pagamento<<std::endl;
    std::cout<<"Projetos: "<<this->_projetos<<std::endl;
}



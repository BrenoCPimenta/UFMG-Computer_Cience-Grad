#include "Vendedor.hpp"

static int MESES = 12;

Vendedor::Vendedor(std::string nome, double salarioHora, double quotaMensalVendas): Empregado(nome, salarioHora), _quotaMensalVendas(quotaMensalVendas){}

void Vendedor::printInfo(double horasTrabalhadas){
    double pagamento = this->pagamentoMes(horasTrabalhadas);
    double quotaTotalAnual = this->_quotaMensalVendas * MESES;
    std::cout<<"Nome: "<<this->getNome()<<std::endl;
    std::cout<<"Salario Mes: "<<pagamento<<std::endl;
    std::cout<<"Quota vendas: "<<quotaTotalAnual<<std::endl;
}



#include "Empregado.hpp"

static int maximoDeHorasSemExtra = 8;
static double porcentagemAdicionalHoraExtra = 0.5; 

Empregado::Empregado(std::string nome, double salarioHora):_nome(nome), _salarioHora(salarioHora){}


//Calculo de hora extra +50% se horasTrabalhadas >8
double Empregado::pagamentoMes(double horasTrabalhadas){
    if(horasTrabalhadas > maximoDeHorasSemExtra){
        double x = horasTrabalhadas - 8;
        double adicionalHorasExtras = x * porcentagemAdicionalHoraExtra;
        horasTrabalhadas += adicionalHorasExtras;
    }
    return horasTrabalhadas * this->_salarioHora;
}
		
std::string Empregado::getNome(){
    return this->_nome;
}

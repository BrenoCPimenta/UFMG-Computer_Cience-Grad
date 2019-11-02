#ifndef AGENDA_H
#define AGENDA_H


#include "../mes/Mes.hpp"
#include "../planeta/Planeta.hpp"

class Agenda{

  private:
    int _tempo_visita_mes;
    int _quantidade_total_planetas;
    int _quantidade_meses_agenda;
    Planeta* _inicio_meses[];
    int _tamanho_meses[];
     

  public:
    Agenda(Planeta*, int, int);
    int getQuantidadeMeses();
    Planeta* getInicioMes(int);
    int getTamanhoMes(int);

};

#endif

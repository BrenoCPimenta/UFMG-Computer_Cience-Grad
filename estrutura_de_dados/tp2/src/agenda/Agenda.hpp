#ifndef AGENDA_H
#define AGENDA_H

#include "../planeta/Planeta.hpp"

class Agenda{

  private:
    int _tempo_visita_mes;
    int _quantidade_total_planetas;
    int _quantidade_meses_agenda;
    Planeta** _inicio_meses = new Planeta*[150000];
    int _tamanho_meses[150000];
     

  public:
    Agenda(Planeta*, int, int);
    ~Agenda();
    int getQuantidadeMeses();
    Planeta* getInicioMes(int);
    int getTamanhoMes(int);

};

#endif

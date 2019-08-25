#include "Estudante.hpp"


float Estudante::calcularRSG(){
    float rsg=0;
    float sum = 0;
    int i;
    for(i=0; i<5; i++){
        sum+= notas[i];
    }
    rsg = sum / 5;
    return rsg;
}

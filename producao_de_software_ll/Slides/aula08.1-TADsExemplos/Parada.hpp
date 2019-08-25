#ifndef PARADA_H
#define PARADA_H

#include <iostream>

struct Parada{
    int id;
    float latitude;
    float longitude;
    bool visitada;
    Parada(int, float, float);
    void show();
    /*
    Outos atributos
    */
};

#endif
#include "Parada.hpp"

Parada::Parada(int id, float latitude, float longitude){
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
}

void Parada::show(){
	std::cout<<"Latitude: "<<this->longitude<<" Longitude:"<<this->longitude<<std::endl;
}
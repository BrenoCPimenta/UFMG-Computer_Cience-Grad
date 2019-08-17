#include "Solid.hpp"


//------------------SOLID--------------------------

Solid::Solid(double raio, double altura, double base, std::string tipo):_raio(raio), _altura(altura), _base(base),_tipo(tipo) {}

std::string Solid::getType(){
       return this->_tipo;
}

double Solid::getVolume(){
	return 0.0;
}

double Solid::getArea(){
	return 0.0;
}



//------------------Cylinder--------------------------

Cylinder::Cylinder(double raio, double altura, double base, std::string tipo):Solid(raio, altura, base, tipo) {}

std::string Cylinder::getType(){
	return this->_tipo;
}

double Cylinder::getVolume(){
	double areaBase = this->_raio * this->_raio * this->pi;
	double volume = this->_altura * areaBase;
	return volume;
}

double Cylinder::getArea(){
	double areaBase = this->_raio * this->_raio * this->pi;
	double circunf = 2*this->_raio*this->pi;
	double areaCilindro = (2*areaBase)+(circunf*this->_altura);
	return areaCilindro;
}

//------------------Sphere--------------------------

Sphere::Sphere(double raio, double altura, double base, std::string tipo):Solid(raio, altura, base, tipo) {}

std::string Sphere::getType(){
	return this->_tipo;
}

double Sphere::getVolume(){
	double r3 = this->_raio* this->_raio* this->_raio;
	double volume = (4*this->pi*r3)/3;
	return volume;
}

double Sphere::getArea(){
	double area = 4*this->pi*this->_raio*this->_raio;
	return area;
}

//------------------Cube--------------------------


Cube::Cube(double raio, double altura, double base, std::string tipo):Solid(raio, altura, base, tipo) {}

std::string Cube::getType(){
	return this->_tipo;
}

double Cube::getVolume(){
	double volume = this->_base*this->_base*this->_base;
	return volume;
}

double Cube::getArea(){
	double areaFace = this->_base * this->_base;
	return 6*areaFace;
}


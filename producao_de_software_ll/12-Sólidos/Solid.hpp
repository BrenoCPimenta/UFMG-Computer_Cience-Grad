#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Solid{
	public:
		const double pi = 3.14; //Nao modifique este valor.
		double _raio;
		double _altura;
		double _base;
		std::string _tipo;


		virtual std::string  getType();
		virtual double getVolume();
		virtual double getArea();

		Solid(double, double, double, std::string);

};

class Cylinder : public Solid{
	public:
		std::string  getType()override;
		double getVolume()override;
		double getArea() override;

		Cylinder(double, double, double, std::string);

};

class Sphere : public Solid{
	public:
		std::string  getType()override;
		double getVolume()override;
		double getArea() override;

		Sphere(double, double, double, std::string);

};

class Cube : public Solid{
	public:
		std::string  getType()override;
		double getVolume()override;
		double getArea() override;

		Cube(double, double, double, std::string);

};

#endif

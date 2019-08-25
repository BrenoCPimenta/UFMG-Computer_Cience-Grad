#ifndef HOUSES_H
#define HOUSES_H

#include<iostream>
#include<string>

using namespace std;

class greatHouse {
  protected:
    string name;

  public:
	void Words();
	void Allegiance();
	void setName(string n);
};

class houseLannister : virtual public greatHouse {
  public:  	
	void Words(bool common);
	void Common();	
};

class houseBaratheon : virtual public greatHouse{
  public:  	
	void Words();	
};


class houseBaratheonofKingsLanding : public houseBaratheon, public houseLannister{
    public:
    using houseBaratheon :: Words;
    using houseLannister :: Common;
};

#endif
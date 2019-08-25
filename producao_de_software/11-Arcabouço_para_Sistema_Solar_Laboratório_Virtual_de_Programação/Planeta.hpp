#ifndef PLANETA_H
#define PLANETA_H

#include "Astro.hpp"
#include <vector>

using namespace std;

class Planeta : public Astro{
    public:
    	vector<Astro> luas;
};

#endif
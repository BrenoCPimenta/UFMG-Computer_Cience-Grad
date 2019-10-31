#ifndef MERGE_H
#define MERGE_H

#include "../planeta/Planeta.hpp"

class Merge{
  private:
    int _quantidade_planetas;

  public:
    Merge(int);

    Planeta* separando(Planeta*, Planeta*);
    void unindo(Planeta*, Planeta*, Planeta*, Planeta*);

};
#endif

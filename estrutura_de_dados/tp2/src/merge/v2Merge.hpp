#ifndef MERGE_H
#define MERGE_H

#include "../planeta/Planeta.hpp"

class Merge{
  private:
    void unindo(Planeta*, int);
    int cnt =0;

  public:
    Planeta* separando(Planeta*, int);

};
#endif

#ifndef MERGE_H
#define MERGE_H

#include "../arvore/Arvore.hpp"
#include "../arvore/No.hpp"

class Merge{
  private:
    void unindo(Arvore*, int);

  public:
    Planeta* separando(Arvore*, int);

};
#endif

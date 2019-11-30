#ifndef CONTROLE_ARVORE_H
#define CONTROLE_ARVORE_H

#include "Arvore.hpp"
#include "No.hpp"
#include "../lista/Lista.hpp"
#include "../lista/CelulaEspecial.hpp"
#include "../ordenacao/CountSort.hpp"
#include "../ordenacao/Insercao.hpp"


class ControleArvore{

  public:
    void ordenarArvore(Arvore*);
    void juntandoArvores(Arvore*);
    void construindoCodigo(Arvore*);
    void passandoCodigo(Lista*, Arvore*); 

};

#endif

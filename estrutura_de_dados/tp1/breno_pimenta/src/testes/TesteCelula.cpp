#include "doctest.h"
#include "../lista/CelulaLista.hpp"


TEST_CASE("Teste Celula- Casos Base")
{
 CelulaLista* cel = new Celula(35,1 ,1);
 CHECK(cel->getValor() == 35);
}
/*
    Pessoa* p= new Usuario("59902427600");
    CHECK(p->buscarDados());
    CHECK(p->getNome() == "Rosalina Soares Coelho");
    CHECK(p->getCpf() == "59902427600");
    CHECK(p->getEndereco() == "Rua Rio de Janeiro 990, Centro");
    CHECK(p->getContato() == "3123954837");
    delete p;
}

TEST_CASE("Teste Pessoa - Casos de Excecoes")
{
    Pessoa* p1 = new Usuario("111111111");
    CHECK_THROWS_AS(p1->buscarDados(), ExcecaoAberturaDeArquivo);
    delete p1;

    Pessoa* p2 = new Usuario("111");
    CHECK_THROWS_AS(p2->buscarDados(), ExcecaoEntradaDeArquivo);
    delete p2;
}
*/

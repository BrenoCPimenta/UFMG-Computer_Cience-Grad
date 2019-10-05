#include "doctest.h"
#include "../lista/CelulaEspecial.hpp"
#include "../lista/Lista.hpp"
#include "../camadas/ControleCamadas.hpp"


TEST_CASE("Teste Celula- Casos Base")
{
 CelulaEspecial* cel = new CelulaEspecial(35);
 CHECK(cel->getValor() == 35);

 CelulaEspecial* cel2 = new CelulaEspecial(20);
 cel->setProximo(cel2);
 CHECK(cel->getProximo()->getValor() == 20);
 delete cel;
 delete cel2;
}

TEST_CASE("Teste Lista- Casos Base")
{
  Lista* lista = new Lista();
  CHECK(lista->verificarVazia());

  CHECK(lista->getTamanho() == 0);
  lista->addValor(1);
  CHECK(lista->getTamanho() == 1);
  lista->addValor(2);
  lista->addValor(3);
  lista->addValor(35);
  lista->addValor(22);
  CHECK(lista->getTamanho() == 5);

  int* p = lista->getValores();
  CHECK(p[0] == 22);
  CHECK(p[1] == 35);
  CHECK(p[4] == 1);
 
  CHECK(lista->removerValor(2));
  CHECK(lista->getTamanho() == 4);

  lista->esvaziar();
  CHECK(lista->verificarVazia());
  
  delete lista;
  delete p;
}
 
TEST_CASE("Teste ControleCamadas - Caso 0")
{
  Lista* lista = new Lista();
  lista->addValor(1);
  lista->addValor(2);
  lista->addValor(3);
  lista->addValor(35);
  lista->addValor(22);
  
  ControleCamadas* ctl = new ControleCamadas(lista);
  
  CHECK(ctl->calcularMovimentos(0) == 0);
  
  delete lista;
  delete ctl;
}

TEST_CASE("Teste ControleCamadas - Caso 1 ")
{
  Lista* lista = new Lista();
  lista->addValor(1);
  lista->addValor(2);
  lista->addValor(3);
  lista->addValor(35);
  lista->addValor(22);
  
  ControleCamadas* ctl = new ControleCamadas(lista);
  
  CHECK(ctl->calcularMovimentos(2) == 1);
  
  delete lista;
  delete ctl;
}



TEST_CASE("Teste ControleCamadas - Caso 2")
{
  Lista* lista = new Lista();
  lista->addValor(1);
  lista->addValor(2);
  lista->addValor(3);
  lista->addValor(35);
  lista->addValor(22);
  
  ControleCamadas* ctl = new ControleCamadas(lista);
  
  CHECK(ctl->calcularMovimentos(5) == 2);
  
  delete lista;
  delete ctl;
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

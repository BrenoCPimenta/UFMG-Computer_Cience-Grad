#include "Engenheiro.hpp"
#include "Vendedor.hpp"

int main() {

    Engenheiro* eng1 = new Engenheiro("Joao Snow", 35, 3);
    eng1->printInfo(9.5);
    delete eng1;
    std::cout << std::endl;
  
    Engenheiro* eng2 = new Engenheiro("Daniela Targaryen", 30, 1);
    eng2->printInfo(8);
    delete eng2;
    std::cout << std::endl;

    Engenheiro* eng3 = new Engenheiro("Bruno Stark", 30, 2);
    eng3->printInfo(8);
    delete eng3;
    std::cout << std::endl;
  
    Vendedor* vend1 = new Vendedor("Tonho Lannister", 20, 5000);
    vend1->printInfo(6);
    delete vend1;
    std::cout << std::endl;
  
    Vendedor* vend2 = new Vendedor("Jose Mormont", 25, 3000);
    vend2->printInfo(8);
    delete vend2;
    std::cout << std::endl;  
	
    Vendedor* vend3 = new Vendedor("Sonia Stark", 30, 4000);
    vend3->printInfo(8);
    delete vend3;
  
    return 0;	
}

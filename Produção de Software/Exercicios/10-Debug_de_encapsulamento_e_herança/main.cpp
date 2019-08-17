/*
O código fornecido apresenta vários erros de implementação relacionados com herança e encapsulamento. Sua tarefa é corrigi-lo, criando (quando necessário) os métodos set() e get() para cada variável problemática e modificando as respectivas chamadas no arquivo main.cpp.

Em alguns casos um método ou variável se torna inacessível após herança, como é o caso de métodos privados após herança privada. Tentar acessa-los levanta um erro de compilação afirmando que a variável ou método é inacessível. Nesse caso, ao invés do método get() retornar o valor da variável seu programa deve imprimir a mensagem "Inacessivel". Todas as classes devem possuir um método get/set para cada uma de suas variáveis acessíveis. Isso inclui variáveis herdadas de outras classes. Não se deve utilizar os métodos das classes herdadas para acessar variáveis herdadas.

Para os membros apenas da ClasseBase, uma possível implementação seria:

base.set_public(1);
base.set_private(2);
base.set_protected(3);
cout << base.get_public() << endl;
cout << base.get_private() << endl;
cout << base.get_protected() << endl;

Considerando o cenário hipotético em que a variável pública é inacessível (Ela não é, este é apenas um exemplo.  Somos capazes de acessar todas estas variáveis da classe base implementando os métodos set/get apropriados como visto durante as aulas) a saída seria:

Inacessivel
2
3

O método set_public() não faria nada visto que a variável é inacessível nesse exemplo.
*/

#include <iostream>
#include "Classes.hpp"

using namespace std;

int main()
{
    ClasseBase base;
    base.set1(1); 
    base.set2(2); 
    base.set3(3); 
 
    ClassePublica pub;
    pub.set1(1); 
    pub.set2(2); 
    pub.set3(3); 
    
    ClassePrivada pri;
    pri.set1(1); 
    pri.set2_a(2); 
    pri.set3(3); 
    
    OverloadPrivada over;
    over.set1(1); 
    over.set2(2); 
    over.set3(3);
    
    A2 a2;
    a2.set1(1);
    a2.set2_a(2); 
    a2.set3(3);
    a2.set1_2(1);
    a2.set2_2(2);
    a2.set3_2(3);
    
    A3 a3;
    a3.set1(1);
    a3.set2_a(2); 
    a3.set3(3);
    a3.set1_2(1);
    a3.set2_2(2);
    a3.set3_2(3);
    a3.set1_3(1);
    a3.set2_3(2);
    a3.set3_3(3);
    
    cout << base.get1() << endl; 
    cout << base.get2() << endl; 
    cout << base.get3() << endl; 
 
    cout << pub.get1_a() << endl; 
    cout << pub.get2_a() << endl; 
    cout << pub.get3_a() << endl;

    cout << pri.get1_a() << endl; 
    cout << pri.get2_a() << endl; 
    cout << pri.get3_a() << endl; 
    
    cout << over.get1() << endl; 
    cout << over.get2() << endl; 
    cout << over.get3() << endl; 

    cout << a2.get1_a() << endl;
    cout << a2.get2_a() << endl; 
    cout << a2.get3_a() << endl; 
    cout << a2.get1_2() << endl;
    cout << a2.get2_2() << endl;
    cout << a2.get3_2() << endl;

    cout << a3.get1_a2() << endl;
    cout << a3.get2_a() << endl; 
    cout << a3.get3_a2() << endl;
    cout << a3.get1_2a2() << endl;
    cout << a3.get2_2a2() << endl;
    cout << a3.get3_2a2() << endl;
    cout << a3.get1_3() << endl;
    cout << a3.get2_3() << endl;
    cout << a3.get3_3() << endl;
    
}
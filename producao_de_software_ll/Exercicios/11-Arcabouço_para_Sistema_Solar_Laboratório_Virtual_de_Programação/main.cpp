/*
Nessa tarefa você deve implementar um arcabouço genérico para definir um sistema solar. As classes e os cadastros a serem implementados são apenas vagamente descritos. O objetivo desta tarefa é começar a praticar a resolução de tarefas reais em que talvez não exista uma descrição formal do problema ou como este deve ser resolvido.

Um sistema solar é constituído de uma lista de planetas e uma lista de estrelas. 
Um planeta é um tipo de um astro e possui uma lista de luas. 
Luas e Estrelas são astros.
Astros, por sua vez, são definidos pelo seu raio, temperatura média, gravidade, nome e uma flag indicando é gasoso.
Sua tarefa constitui em implementar as classes SistemaSolar, Planeta e Astro. Seu programa deverá ler de um arquivo de texto (o nome do arquivo será passado para o programa) as definições dos diferentes astros presentes no sistema solar descrito e realizar as devidas atribuições. 

O arquivo de entrada apresenta diversas tags seguidas de um valor (ilustrado abaixo entre <>). São elas:

defastro: Indica o início da descrição de um astro.
Estrela/Planeta/Lua <nome>: tipo de astro seguido do seu nome.
Orbita <nome do planeta>: no caso específico das Luas, indica em qual planeta ela orbita.
Temperatura <valor>: inteiro indicando a temperatura média do astro 
Raio <valor>: inteiro indicando o raio do astro.
Gravidade <valor>: ponto flutuante indicando a gravidade do astro.
Gasoso <True/False>: booleano indicando se o astro é gasoso ou sólido.
Um exemplo da definição de uma das Luas de Marte:

defastro
Lua Fobos
Orbita Marte
Temperatura -40
Raio 11
Gravidade 0.001
Gasoso False

Ao final, seu programa deverá imprimir por linha:

Nome da maior (raio) estrela.
Temperatura da maior (raio) estrela.
Número de astros presentes.
Número de planetas presentes.
Número de planetas sólidos.
Número médio de luas por planeta (duas casas decimais, truncado).
Nome do planeta com mais luas.
Nome do planeta mais quente.
Nome do planeta mais frio.
Nome do planeta de maior raio.
Nome do planeta de menor raio.
*/

#include <iostream>
#include <vector>

#include "Astro.hpp"
#include "Planeta.hpp"
#include "SistemaSolar.hpp"

using namespace std;

int main() {
	
	SistemaSolar sistema; 
	string filename;
	cin >> filename; 
	
 	sistema.fill(filename);
 	
 	string a = sistema.getLargestStar();
	int b = sistema.getTempStar(a);
		
	int c = sistema.getNumAstros();
	int d = sistema.getNumPlanetas();
	int e = sistema.getNumPlanetasSold();
	
	float f = sistema.getMedLuas();
	f = float(int(f*100))/100; // Truncar para 2 casas decimais
	
	string g = sistema.getPlanetaLuas();
	string h = sistema.getPlanetaQuente();
	string i = sistema.getPlanetaFrio();
	string j = sistema.getPlanetaMaior();
	string k = sistema.getPlanetaMenor();
    
    cout << a << endl << b << endl << c << endl << d << endl << e << endl;
    printf( "%.2lf\n", f );
    cout << g << endl << h << endl << i << endl << j << endl << k;
    
}

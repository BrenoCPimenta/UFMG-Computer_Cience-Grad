# Estrutura de Dados - Filas 

#### Sumário:
1. [Filas](#Filas)
2. [Implementação de Filas com Alocação Sequencial](#implementação-de-filas-com-alocação-sequencial)
3. [Implementação de Filas com Ponteiros](#implemetação-de-filas-por-meio-de-ponteiros)
4. [Problema comumnete cobrado](#problema)
<br>

## Filas 
Os usos mais comuns para filas é em sistemas operacionais para fila de impressão e processamento.

#### Aspectos:

#### Principais operações:
* Esvaziar(Fila)
* Vazia(Fila) // Retorna true se a pilha esta vazia
* Enfileira(x, Fila)
* Desenfileira(Fila)


## Implementação de Filas com Alocação Sequencial
* Os itens da fila são armazenados em posições contíguas de memória.
* Enfileirar faz a parte de trás da fila expandir-se.
* Desenfileirar faz a parte da frente da fila contrair-se.
* A fila tende a se movimentar pela memória do computador, ocupando espaço na parte de trás e descartando espaço na parte da frente.
* Problema:
  * Com poucas inseções e retiradas, a fila vai ao encontro do limite do espaço da memória alocada para ela.
  * **Solução**: imaginar o vetor como um círculo. A primeira posicao segue a última. Dessa forma manten-se a fila dentro do tamanho esperado dela.
* **Construção**:
  * Utiliza-se dois ponteiros, _Tras_ e _Frente_.
  * Caso da pilha vazia, _Tras_ e _Frente_ apontam para o mesmo lugar.
  * Existe uma posicao marcada na memoria, que é o maxTamanho, e sabemos que o tamanho é X, logo a primeira posição de memória é maxTamanho - X.
  * Caso tras esteja no maxTamanho e empilhamos, empilharemos na posicao maxTamanho - X. (Lembrando que há que verificar sempre se nova posição do ponteiro _Tras_é igual ao do _Frente_, pois nao pode enfileirar, pois a fila esta cheia.)


## Implemetação de Filas por meio de ponteiros
Vide Pilha e Lista, muito parecido e intuitivo.


## Problema
Possui-se apenas estruturas em pilha e busca-se implementar uma fila apenas usando os métodos das pilhas.
O que deve-se entender é que existem dois métodos para essa implementação:
  1. Quando empilhar possui custo barato, dessa forma a pilha possui a mesma ordem da fila, todas as vezes que enfileirar, basta realizar um empilhar, mas o desenfileirar, ha que mover todos os elementos da pilha e estoca-los em outra pilha para poder retirar o primeiro elemento.
  2. Quando desempilhar possui custo barato, a pilha fica na ordem contrária da fila e é o oposto da regra a cima.
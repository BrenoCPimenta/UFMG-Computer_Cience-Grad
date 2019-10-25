# Estrutura de Dados - Pilhas 

#### Sumário:
1. [Pilhas](#pilhas)
2. [Implementação de Pilhas com Alocação Sequencial](#implementação-de-pilhas-com-alocação-sequencial)
3. [Implementação de Pilhas com Ponteiros](#implementação-de-pilhas-com-ponteiros)
4. [Notação Infixada e Pós-Fixada](#utilização-de-pilha-para-conversão-de-notação-infixada-a-pós-fixada.)

<br>

## Pilhas 

#### Aspectos:

#### Principais operações:
* Esvaziar(Pilha)
* Vazia(Pilha) // Retorna true se a pilha esta vazia
* Empilha(x, Pilha)
* Desempilha(Pilha)
* Tamanho(Pila)


## Implementação de Pilhas com Alocação Sequencial
* Os itens da pilha são armazenados em posições contíguas de memória.
    * Ou seja quando se empilha algo, apenas busca-se _endereço_topo++_.
* Inserções e retiradas: **apenas no topo**.
* Variável **Topo** controla posição no topo da lista.
* Obs: Possui tamanho pré-definido.


## Implementação de Pilhas com Ponteiros
* A pilha é composta por células, onde cada célula possui um 'item' que é referente ao valor que ela armazena e um ponteiro que aponta para a célula abaixo da mesma.
* Utiliza-se dois ponteiros auxiliáres para facilitar a execução das funções, _Topo_ e _Fundo_.
* A primeira célula da pilha (que está no fundo), tem seu ponteiro apontado para nulo. E lembrando que o ponteiro auxiliar _Fundo_ aponta para essa célula.




## Utilização de Pilha para Conversão de notação infixada a pós-fixada.
* **Infixada:** (5 * (((9+8) * (4*6)) + 7))
* **Pós-Fixada** 5 9 8 + 4 6 * * 7 + *<br><br> 
Funciona da seguinte forma, utilizando-se de duas pilhas lê-se a notação infixada da esquerda para a direita. <br>
Ignora-se a abertura de parenteses.<br>
Quando se lê um número ele é armazenado na Pilha1.<br>
Quando se lê um operador ele é armazenado na Pilha2.<br>
E finalmente quando se lê um fechamento de parenteses, desempilha-se os dois números no topo da Pilha1 e desempilha-se o operador no topo da Pilha2, usando-o para operar os dois números, o resultado é empilhado novamente na Pilha1.
No final deve sobrar apenas um número que é o resultado da equação, caso sobre mais de um número a notação infixada está errada.



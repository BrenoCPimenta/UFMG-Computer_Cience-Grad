# Estrutura de Dados - Listas Lineares

#### Sumário:
1. [Listas lineares](#listas-lineares)
2. [Alocação sequencial](#alocação-sequencial)
3. [Alocação encadeada](#alocação-encadeada)

<br>

## Listas lineares

#### Aspectos:
* Podem crescer/diminuir de tamanho durante a execução.
* Adequadas quando não é possível prever a demanda por memória.
* As duas representações mais utilizadas são as implementações:
  * Alocação sequencial
  * Alocação encadeada


#### Principais operações:
* CriarListaVazia(Lista, Tam)
* EsvaziarLista(Lista)
* Inserir(Pos, Elemento,Lista) //Insere elemento na posição Pos da Lista.
* Retirar(Pos, Lista, Elemento) //Retorna elemento da posição Pos e o remove da Lista.
* Vazia(Lista) //Verifica se a lista está vazia.
* Imprime(Lista) //Imprime os itens da lista em ordem.


## Alocação sequencial
* Os itens são posicionados sequencialmente na memória
  * Pró:
    * Permite acesso aleatório ou seja complexidade de acesso a qualquer item é **constante**.
    * Pode ser percorrida em ambas as direções.
    * Economia de memória, pois cada elemento armazena apenas os dados.
    * A estrutura da lista é definida implicitament.
  * Desv.:
    * Inserção no início ou no meio da lista exige deslocamento de itens na memória com custo dependendo do tamanho da lista.
        * No pior caso o custo é igual ao tamanho do vetor: **Custo Linear**.
* Os itens são armazenados em um vetor.
* Possui ponteiros _Primeiro_ e _Ultimo_, mesmo tendo tamanho fixo.

## Alocação encadenada
* Permite utilizar posições não contíguas de memória.
  * Pró:
    * É possível inserir e retirar elementos sem necessidade de deslocar os itens seguintes da lista. Possui custo **constante**. (Importante quando a lista tem de ser mantida em ordem).
    * O tamanho da lista não precisa se difinida a priori. (Importante para aplicações onde não existe previsão para o tamanho da lista).
  * Desv.:
    * Utilização de memória extra para armazenar os ponteiros.
    * **Custo linear** para acessar um item no pior caso.
 
* A lista é constituída de células. Cada célula contém:
    * Item da lista 
    * Ponteiro para a célula seguinte.
* Novas células são criadas sob demanda em posições não contíguas de memória (**HEAP**) e encadeadas na lista.


<br><br><br>

> DUVIDA SOBRE A LOGICA ABAIXO:
* Uma variável/objeto do tipo Lista é um registro com um ponteiro para a célula _Topo_ e _Ultimo_.
* Formas de contrução:
  * Sem célula _Topo_. Ou seja há apenas um ponto de partida para a lista.
  * Com célula _Topo_. Essa célula marca apenas o começo da lista. (listas com 

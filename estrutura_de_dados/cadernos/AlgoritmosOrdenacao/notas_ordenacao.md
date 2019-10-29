# Algortimos de ordenação

* [Introdução](#introdução)
* [Critérios de Classificação](#critérios-de-classificação)
    * [Localização dos dados](#localização-dos-dados)
    * [Estabilidade](#estabilidade:)
    * [Uso de memória](#uso-de-memória)
    * [Movimentação dos dados](#movimentação-dos-dados)
    * [Adaptabilidade](#adaptabilidade)
    * [Complexidades](#complexidades)



# Introdução

Algoritmos com o objetivo de organizar alguma entrada a partir de um regra especifica.

# Critérios de Classificação

### Localização dos dados:
 * **Ordenação Interna:** todas as chaves estão na memória principal.
 * **Ordenação Externa:** chaves na memória principal e na memória secundária.
 
### Estabilidade:
 A estabilidade está relacionada com a manutenção relativa entre chaves do mesmo valor.<br>
Ou seja o método é estável caso dados com mesmo valores não sejam trocados de ordem.

### Uso de memória:
**IN PLACE:** transforma os dados de entrada utilizando apenas o espaço já disposto pelos dados de entrada (utiliza um espaço extra de tamanho constante).

### Movimentação dos dados:
* **Direta:** registro todo é acessado e deve ser movido.
* **Indireta:** apenas as chaves são acessadas e ponteiros são rearranjados e não o registro todo.

### Adaptabilidade:
A adaptabilidade é relacionada ao comportamento do algoritmo dependendo da entrada.<br>
O algoritmo **não é adaptável** quando o mesmo número de operações é executado independente da entrada.

## Complexidades:
* **Comparações:** número de comparações C(n) entre as chaves.
* **Trocas:**: número de trocas ou movimentações M(n) de itens.


---
# Algoritmos Simples:

## Método Bolha

IMG-BOLHA

* **Funcionamento:** Ele pega o primeiro elemento e compara com o segundo, se ele é menor que o segundo, ele troca os dois de lugar e assim sucessivamente até o final do vetor.<br> 
É conhecido como bolha pois, de um em um, os maiores elementos vão subindo para o final do vetor.<br> 
Então na próxima vez que se percorrer o vetor não será necessário comparar com o último elemento, pois ele já estará posicionado corretamente.

* **Complexidades:**
  * **Comparações:** (n-1 + n-2 + ... + 1), ou seja é uma somatória de 1 a n-1, sendo então uma complexidade de O(n²).
  * **Movimentações:** 
    * Melhor Caso: M(n) = 0 ou seja não é necessário nenhuma troca pois o vetor já está ordenado.
    * Pior Caso: M(n) = 3xC(n) ou seja o vetor está inversamente ordenado, então para cada troca é preciso passar o valor para uma variável auxiliar, depois colocar o valor maior na posição mais a frente e depois copiar da variável auxiliar para a posição mais atrás.

* **IN PLACE**
* Estável
* Não adaptável em termos de comparação.
* INEFICIENTE para pior e médios casos: O(n).

* **OBSs**:
  * Pode ser melhorado: O algoritmo para quando não foi realizado nenhuma troca em uma iteração.
  * Tem uma variação chamado _OrdenaçãoPar-Ímpar_

---

## Método de Seleção

* **Funcionamento:** Percorre o vetor, cria uma variavel 'min' e seleciona o menor valor e trás ele para a primeira posição e assim sucessivamente.<br>Ele é muito parecido com o bolha, a diferença é que ele 'padroniza' o número de movimentções.
* **Complexidades:**
  * **Comparações:** (n-1 + n-2 + ... + 1), ou seja é uma somatória de 1 a n-1, sendo então uma complexidade de O(n²). Igual o do bolha a diferença é que o Bolha pode ser otimizado para parar quando não houver trocas em uma iteração pelo vetor, enquanto o de seleção vai sempre comparar O(n²) independente do formato da entrada.
  * **Movimentações:** 
    * Melhor, pior e caso médio: M(n) = 3(n-1) = O(n) ou seja sempre realizará o mesmo número de movimentos.
* Não é Estável
* Não adaptável, pois não importa se o arquivo está parcialmente ordenado.

---

## Método de Inserção

* **Funcionamento:** Começa no segundo elemento e se compara com o anterior, se posiciona em primeiro se menor, se nao mantem.<br>
Na próxima iteração, o próximo valor vai se comparando com os anteriores:<br>
Se ele é maior que o anterior direto ele mantém a posição, do contrário ele vai comparando com os anteriores até encontrar um valor menor e trocar de posição para a seguinte do mesmo. Se não encontrar nenhum valor menor ele se torna o primeiro do vetor.<br>
Esse método é conhecido como o método que é usado para ordenar mão de baralho.
* **Complexidades:**:
  * **Comparações:** 
    * Melhor caso: Já está ordenado só se compara uma vez para cada valor da entrada, O(n).
    * Pior caso: Está inversamente ordenado, compara-se o valor da rodada com todos os anteriores, O(n²).
  * **Movimentações:**
    * Melhor caso: O(1), não se movimenta nenhum valor.
    * Pior caso: O(n²) se movimenta todos os valores anteriores menos o da rodada.
* Estável
* Adaptável

* **OBS:** Ineficiente para entradas grandes, pois possui alto custo em alguns casos.


---
# Algoritmos mais complexos:

## Quicksort

* **Funcionamento:** Utiliza o paradigma de dividir para conquistar.<br>
A ideia é, escolhe-se um pivô aleatório no vetor.<br>
Depois pega-se dois ponteiros, um que começa no começo do vetor e o percorre em direção ao final e outro que começa no final e percorre em direção ao começo.<br>
O ponteiro da esquerda vai verificando se algum número é maior que o pivô, caso encontre, ele para e espera o outro ponteiro verificar se algum número à direita do pivô é menor que ele.<br>
Quando ambos os ponteiros encontram, eles trocam esses valores de lugares e continuam percorrerndo o vetor... até que um ponteiro cruze com o outro.<br>
Quando isso acontece, o ponto de cruzamento se torna o ponto de divisão para a chamada de dois outros quicksort menores, um para a direita desse ponto e outro para a esquerda... e assim sucessivamente até ordenar o vetor.

* **Complexidade:** 
  * **Comparações:**
    * Pior caso: quando o pivô é as beradas de um vetor semi-ordenado. O(n²).
    A chamada recursiva T(n) = n + T(n-1)
    * Melhor caso: Quando cada partição divide o arquivo em tamanhos iguais. O(n log n).
    A chamada recursiva T(n) = 2T(n/2) + n
    * Caso médio: O(n log n).

* Não é Estável
* De certa forma adaptável.
* IN PLACE ? (requer apenas uma pequena pilha como memoria auxiliar).

* **OBS:** Muito útil, pois raramente cai no pior caso.


---
## MergeSort


* **Funcionamento:** Vai dividindo o vetor em vetores menores até cada valor ficar separado individualmente.<br>
Em seguida junta os valores individuais em duplas e compara eles, e subsequentemente os ordena.<br>
Agora teremos vários vetores com dois valores, cada vetor desses está ordenado.<br>
Agrupamos esses vetores em pares, para cada vetor do par é designado um ponteiro, cada ponteiro começa à esquerda no vetor. Então os ponteiros vão comparando os valores, caso um ponteiro esteja apontando para o menor valor, esse valor é copiado para um terceiro vetor e esse ponteiro que apontava para o menor passa para o próximo em seu vetor.<br>
Caso um dos ponteiros chegue ao final de seu vetor, os restantes dos elementos do outro vetor são copiados em ordem para o vetor final.<br>
E assim sucessivamente até encontrarmos um vetor final ordenado

* **COMPLEXIDADE** ANALISE CABULOSA COM TEOREMA MESTRE O(n log n)
* Estável
* Não é adaptável, ele irá ordenar em O(n log n) independente da entrada.
* Não é IN PLACE

* **OBS**: Deve ser considerado quando alto custo de pior caso não pode ser tolerado. Requer espaço extra proporcional a n. Comumente adaptado para ordenação em momória secundária.


---

## HeapSort

* **Funcionamento:** Constrói uma árvore binária usando o vetor. Depois torna essa árvore em uma árvore onde os pais sao maiores ou iguais aos filhos (max heap) ou seja o maior elemento da árvore vai ser a raiz. Quando terminar de ordenar, o algoritmo pega a raiz e troca de posição com o último elemento do vetor. O último elemento do vetor é então considerado ordenado. A árvore é reajustada para que o maior elemento seja a raiz e assim sucessivamente.

* **Complexidade:** Ele se comporta sempre como O(n log n) qualquer que seja a entrada

* Não Estável
* Não é Adaptável




---
## ShellSort

* **Funcionamento:** Escolhe um gap (espaço entre valores). Ou seja pega os valores em pares. 3,4,5,6,7,8: o gap é 2, então vai ser comparado 3 com 6, 4 com 7 e 5 com 8.<br>
Compara-se normal e troca caso o elemento da esquerda seja maior. <br>
Na próxima iteração diminui-se o gap e continua o processo assim sucessivamente.<br>
Quando o gap é igual a 1, executa-se o algoritmo de **Inserção**. Por isso que é dito que o ShellSort é uma otimização do método de inserção.

* Escolha do Gap: Sendo 'h' o gap e 's' a iteração, uma forma otimizada de calcular o gap ideal é: h(s) = 3h(s-1)+1
* **Complexidade:** A complexidade do ShellSort é uma das perguntas em aberto em Ciência da Computação. 
* Não é estável
* É adaptável de certa forma
* IN PLACE
* **OBS** a eficiência do algoritmo depende muito da escolha do gap.

   





---
# Ordenação sem comparação

## CountingSort
* **Funcionamento:** É necessário um vetor com o número de chaves até o maior número da entrada. Então percorre-se a entrada e a cada valor encontrado, usa-se esse valor como chave para o vetor e soma-se um ao valor dessa chave. Ao terminar de percorrer a entrada, percorre-se o vetor e cria-se um terceiro vetor correspondente à entrada ordenada.
* **Complexidade:** Sendo n o numero de valores da entrada e K o maior valor da entrada, a complexidade é O(n+k). E complexidade de espaço é O(k).
É muito rápido mas utiliza muita memória extra e é quase impossível saber qual o maior número da entrada a priori.


## BucketSort
* **Funcionamento:** Separa os valores em baldes menores com tamanhos pré-definidos e ordena esses baldes com algortimos tradicionais.
* **Complexidade:** Temporal O(n²) e Espacial O(n+k).

## RadixSort
* **Funcionamento:** É um tipo de quicksort, mas que compara por bits. Ele seleciona um bit específico e separa em partições onde os valores que possui esse bit zero e onde possui 1... e nas partições sucessivas escolhe-se outro bit e assim sucessivamente até ordenar o vetor.



# Ordenação externa

## MapReduce
Divide em fitas e cada fita em blocos. Ordena esses blocos e cria novas fitas com os blocos mais ordenados das primeiras fitas e assim sucessivamente.

##QuickSort Externo
Mesma lógica só que as partições são processadas uma por vez

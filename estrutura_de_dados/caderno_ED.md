# Caderno Estrutura de Dados
## Professora Olga DCC/UFMG


## Aula02 08/08/2019
## Analise de complexidade de algoritmo
* ALgoritmo deve ser funcional (saidas corretas para determinadas entradas)
* Algoritmo deve ser eficiente, deve retornar em tempo habil


### Eficiencia

Podemos medir com tempo de execucao e espaço ocupado, esse estudo é chamado de *Analise se Algoritmo*.

A análise é dividida em:
* análise padiiticular (um algoritmo particular) 
* ou uma classe de algoritmos (analiza-se o problema propriamente dito)

#### Algoritmo Particular

#### Classe de Algoritmos
* Qual é o menor custo para resolver um problema em particular.
* Coloca-se limites.

### Medida do custo pela execucao do programa
#### Medida do custo por tempo de execução
Nao é a melhor forma medir igual mediamos, com o tempo de execucao do programa, pois a maquina que esta rodando pode variar esse tempo... assim como o sistema operacional e como ele executa o programa pode fazer com que o resultado varie.

<br>Apesar disso, a medida de tempo por execução ainda é válido.

#### Medida do custo por meio de modelo matemático
* É baseado em um modelo de computador ideal, onde se executa um comando de cada vez e utilizando memória RAM.
* Costuma-se desconsiderar algumas operações não essenciais, como atribuição de variável. E foca-se na execução do processo a analizar.


**Algoritmo Ótimo**: quando o custo de um algoritmo é igual ao menor possível.

Funcao de complexidade é F, podemos usa-la para tempo como espaço, mas vamos focar em tempo. E n é a entrada da funcao. E o resultado que retorna nao será em em tempo.

#### Exemplo 01
> Pesquisar cálculo de complexidade

(n+3)\dot sizeof(int)  -> resultado do cálculo de complexidade do exemplo 01

Cálculo de tempo: n-1 operacoes é o minimo necessário necessário


**OBS**: O mesmo algoritmo pode ter complexidade diferente dependendo da entrada.

* Dependen principalmente do tamanho da entrada
* Depende tamanho da organização dos dados de entrada. (por isso é muito importante o formato de armazenagem.

#### Exemplo 02
* Complexidade esmpacial: n*numero de registros+2int
* Complexidade temporal:
  * Melhor caso: custo=1
  * Pior caso: custo=n
  * Caos médio: deve-se primeiro conhecer a distribuição de probabilidade. Normalmente o caso médio é mais difícil de obter que os outros dois. Podemos fazer uma suposição **explicita** para poder cálcular, mas sempre lembrando que isso não é sempre verdade.
 
> Pesquisar o que é valor esperado em probabilidade.

**OBS**: Normalmente em analise de algoritmos, foca-se no pior caso!

Assumimos que p= 1/n , portanto 1/n(1+2+3...+n) ou seja 1/n((n(n+1))/2)

#### Exemplo 03
Todos os casos serão 2*(n-1)
* Melhor caso: os elemento estao em ordem crescente. n-1
* Pior caso: os elementos estao decrescentes. 2*(n-1)
* Caso médio: (n-1) +((n-1)/2)


#### Exemplo aprimorando exemplo 03
Pode-se primeiro fazer uma análize em pares, ou seja aumentando o uso de memória (muito pouco). 
<br>Ou seja, dividimos em dois arrays por pares, onde o maior valor do par fica

>Pesquisar tempo para alocação em memória vs tempo de comparação de valores

**OBS**: Será mais trabalhado na próxima aula, mas é importante ressaltar como que constantes não são muito relevantes.


## Algoritmo de Limite Inferior
<br> Esses exemplos se encontram englobados em problemas de lowerboundary (Limites inferiores).
<br> Será usado um oráculo (modelo adversarial), onde será usado a pior entrada possível.

**OBS**: A Professora não é fã de análise médio, pois é muito relativo à estrutura de dados





<br><br><br><br>
# Aula03 13/08/2019
## Complexidade Assintótica
Geralmente em pesquisa não costuma-se colocar a complexidade, não coloca-se como na última aula Exemplo: O(n2-3), e sim complexidade assintótica.

O que nos interessa é o termo que dominará os outros quando a função tender ao infinito. E nesse termo, ignora-se a constante e utilizamos apenas o exeponencial do mesmo.

Ou seja: Teóricos não se interessam muito por constantes.

Na análize assintótica construimos primeiro a função e depois a reduzimos.

### Dominío assintótico
(Assumimos que as funções são positivas, até pq estamos calculando complexidade)<br>
Uma função domina a outra quando a partir de um momento 'm' se uma função f(n), for multiplicada por c, sempre será maior que g(n). Lembrando que domínio é maior ou igual.

1. Exemplo
~~~
f=n² e g=(n+1)²
~~~
É um caso no qual, se considerarmos c=4 e n'>'=1, f domina assintoticamente g, e g também domina f. Esse é um dos motivos por desconsiderarmos as constantes.

Esse tipo de questão pode cair na prova, para isso temos que provar quem domina quem, para isso devemos encontrar qual a constante c e qual o valor m que dá princípio ao espaço de dominação. 

* Big O
Quando falamos g(n)=O(f(n)), quer dizer que fn domina asssintoticamente gn. Ou seja fn é uma limite suṕerior para gn.

* Notação Omega:
g(n) = Omega(f(n)), aqui quer dizer que gn domina assintoticamente fn. Ou seja fn é um limite inferior para gn.

* Notação Teta:
Quando g(n)=Teta(f(n)), quer dizer que fn é um limite inferior e superior para gn. Quando conseguimos demonstrar isso, dizemos que temos um lmite firme.

**Importante**: essas notações fazem com que g=O(f) e f=O(h), não implica em g=O(h)

2. Notação O, Exemplo1

>ACHO: Monta-se uma desigualdade, isola-se 'c' e encontramos o menor valor que atenda. Lembrando que a constante isolada na desigualdade é 'm'. 

3. Notação O, Exemplo3
Apesar de conseguimos provar O(n⁴) e O(n³), optamos mostrar O(n³), pois é a que cresce mais lentamente.

Apesar de conseguimos provar O(n⁴) e O(n³), optamos mostrar O(n³), pois é a que cresce mais lentamente.

Apesar de conseguimos provar O(n⁴) e O(n³), optamos mostrar O(n³), pois é a que cresce mais lentamente.



OBS: Na prova a Olga disse que normalmente não será preciso achar os 'm' e 'c's ideais, e sim valores que atendem e provem o que foi dito.


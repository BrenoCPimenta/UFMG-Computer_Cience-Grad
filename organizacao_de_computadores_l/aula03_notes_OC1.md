
# Aula03 dia 12/08/19

Entendimento de registradores. 
Maquinas modernas que sao mais cisc que risk, possuem menos de 32 registradores.
Cada registrador possui 64 bits.


Enquanto na memória, é uma matriz de uma coluna e muitas linhas.
Mas cada linha possui 8 bits, logo para alcançar os 64bits, podemos acessar de 8 em 8 linhas.


Lembrando que os pcs usam comprimento de 2 para lidar com leitura de bits.

## Aritmetica usando Assembler
Cada instrução opera com 3 registrasdores sendo 1 o destino.
Há que entender que no RISC-V existe um cóodigo específico, mas muito parecido com o assembler, porém usando os registradores específicos dele e (acredito que haja outras diferenças).
Importante pesquisar as definições dos registradores nos slides.

_Opcao de solução para um dos exemplos dos slides em ordem de execução:_
1. add f,g,h
2. sub f,f,i
3. add f,f,j 

<br>
* Um dos operandos pode ser um valor direto. Mas para isso há um comando específico para não confundir com valor de memória.
    * addi x5, x6, 21
    * só há o **addi**, pois caso quisermos uma subtração é só colocar o valor em negativo.


>DUV: o que pulso de próton tem a ver com isso tudo.
>DUV: o que é uma máscara.

>DUV: Pesquisar o que é o ALU dentro do processador


## Uso de muitas variáveis

Nao é permitido no risk usar operando na memoria, só no processador, ou seja nos registradores.
Portanto há que utilizar a memória, quando houver o uso de muitas variáveis, para isso usaremos os seguintes comandos:

Comandos **Load**-> carrega conteúdo da memória para o registrador:

* Id x5, 8(x6) 
    x5: será guardado o dado
    x6: endereço da memória
    8(): tem o +8, que será o valor do registrador mais qual parte da memória será pega, caso fosse 16, pegaria uma memória a frente.
Obs: Esse valor não pode ser usado, sendo passado como um registrador.
Obs: Existe o Load Unsigned.


Comando **Store**-> copia contepudo do registrador na memória
* sd x5, 8(x6)



>DUV: Pq na memoria o endereço 20 nao pode? No exemplo dele, ele só usa a partir da posição 24.










<br><br><br><br><br><br><br><br>
# Exemplo de Tabelas:

| header1 | header2 |
| ------- | ------- |
| cell1 | cell2 |
| cell3 | cell4 |



| Application - Markdown Support | Active | Preview | Price     | Non-app store version | Writing Experience | Footnotes | Strikethrough |
| ------------------------------ | :----: | :-----: | --------: | :-------------------: | :----------------: | --------- | ------------- |
| Typora                         | Superb |   Yes   | Free Beta |          Yes          |        ++++        | Weak      | Two Tildes    |
| TableIt                        |Yes   |   Yes   |       $19 |          Yes          |        N/A         | N/A       | N/A           |
| Marked 2                       |   No   |   Yes   |       $10 |          Yes          |        N/A         | Yes       | Yes, GFM      |
| BBEdit/TextWrangler            |  Yes   |   No    |  $50/free |          Yes          |         ++         | No        | No            |

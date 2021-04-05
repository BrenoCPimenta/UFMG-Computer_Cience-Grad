Trabalho Prático 2 -- Máquinas de Turing
Breno de Castro Pimenta
RA: 2017114809


# Funcionamento:
## Arquivo de entrada:
Os exemplos para execução estão dispostos no arquivo examples.txt. 
Cada linha do arquivo representa um exemplo e eles estão no seguinte formato:
    <Nome e numéro do exemplo> : R<M,w>
Para adicionar/testar outros exemplos basta inserir mais uma linha no mesmo formato ao final do arquivo.
Para entender os testes adicionais por favor veja o último item deste arquivo.

## Executando:
Basta ir até a raiz do projeto e executar o seguinte comando:
    python3 turing_machine.py

## Saída:
Ao executar o programa será criado um arquivo chamado results.txt, onde estará os exemplos e seus resultados listados na mesma ordem que do arquivo examples.txt.


# Código:
A lógica do algoritmo seguiu a risca os detalhes expostos na seção 5.3 do livro  texto Linguagens e Máquinas: Uma Introdução aos Fundamentos da Computação escrito por Newton José Vieira.
Para a modelagem foram utilizadas estruturas de dados de variáveis, listas e diciconários para representar as três fitas da máquina.
O código é dividido em:
    * Função readData - que lê e separa os elementos.
    * Função treatData - que recebe R<M,w> e separa cada parte em listas independentes.
    * Classe State - que representa um estado e armazena suas possíveis transições.
    * Função executeCycles -  que é responsável por dividir as fitas e executar o processo (processo esse descrito no livro)
    * Função main responsável por gerenciar a execução de cada exemplo e retornar os resultados.
Qualquer dúvida durante a leitura do código, por favor veja os comentários.

# Exemplos alternativos:
* Example Alternative 5: representa a máquina 1, porém a plavra nova é <b>.
* Example Alternative 6: representa a máquina 1, porém a plavra nova é <⊔>.
* Example Alternative 7: representa a máquina 1, porém a plavra nova é <c>.
* Example Alternative 8: representa a máquina 1, porém a plavra nova é <aa>.
* Example Alternative 9: representa a máquina 1, porém a plavra nova é <d> onde não há transição para ela.
* Example Alternative 10: representa a máquina 3, porém a plavra nova é <111000110>.

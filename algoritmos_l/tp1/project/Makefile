#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra 
EXEC=./tp1 
TMPOUT=tp1.testresult


#Transformando o comando main no padrao
all: $(EXEC)


#Caminhos reutilizaveis
SRC=./src
GRP=./graph
HEP=./heap


#Tipos abstratos de dados
TAD1=NodeGraph
TAD2=Graph
TAD3=NodeHeap
TAD4=HEAP

#Pre-Compilando codigo
$(TAD1).o: $(SRC)/$(GRP)/$(TAD1).cpp $(SRC)/$(GRP)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(GRP)/$(TAD1).cpp -o NodeGraph.o

$(TAD2).o: $(SRC)/$(GRP)/$(TAD2).cpp $(SRC)/$(GRP)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(GRP)/$(TAD2).cpp -o Graph.o

#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o

#Gerando executavel
$(EXEC): main
	$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: $(EXEC)
	$(EXEC)


#Teste com entradas e saidas. E teste de vazamento de memoria
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)


#Limpando codigo pre-compilado e executáveis criados
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o main_test $(EXEC) main_test test.result


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
PLY=./player
HEP=./heap


#Tipos abstratos de dados
TAD1=NodeGraph
TAD2=Graph
TAD3=Player
TAD4=NodeHeap
TAD5=HEAP


#Pre-Compilando codigo
$(TAD1).o: $(SRC)/$(GRP)/$(TAD1).cpp $(SRC)/$(GRP)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(GRP)/$(TAD1).cpp -o NodeGraph.o

$(TAD2).o: $(SRC)/$(GRP)/$(TAD2).cpp $(SRC)/$(GRP)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(GRP)/$(TAD2).cpp -o Graph.o

$(TAD3).o: $(SRC)/$(PLY)/$(TAD3).cpp $(SRC)/$(PLY)/$(TAD3).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(PLY)/$(TAD3).cpp -o Player.o

$(TAD4).o: $(SRC)/$(HEP)/$(TAD4).cpp $(SRC)/$(HEP)/$(TAD4).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(HEP)/$(TAD4).cpp -o NodeHeap.o



#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o $(TAD3).o $(TAD4).o

#Gerando executavel
$(EXEC): main
	$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(TAD3).o  $(TAD4).o $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: $(EXEC)
	$(EXEC)

#Teste com entradas e saidas. E teste de vazamento de memoria
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

valgrind_test:  ${EXEC}
	tests/01.in | valgrind --leak-check=yes ${EXEC}


#Limpando codigo pre-compilado e executáveis criados
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o main_test $(EXEC) main_test test.result


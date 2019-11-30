

#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp3 
TMPOUT=tp3.testresult


#Transformando o comando exec no padrao
all: $(EXEC)

#Caminhos reutilizaveis
SRC=./src
LIT=./lista
HSH=./hash

#Tipos abstratos de dados
TAD1=CelulaEspecial
TAD2=Lista
TAD3=Hash

#Pre-Compilando codigo
$(TAD1).o: $(SRC)/$(LIT)/$(TAD1).cpp $(SRC)/$(LIT)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD1).cpp -o CelulaEspecial.o

$(TAD2).o: $(SRC)/$(LIT)/$(TAD2).cpp $(SRC)/$(LIT)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD2).cpp -o Lista.o

$(TAD3).o: $(SRC)/$(HSH)/$(TAD3).cpp $(SRC)/$(HSH)/$(TAD3).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(HSH)/$(TAD3).cpp -o Hash.o


#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o $(TAD3).o

$(EXEC): main
	$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(TAD3).o $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: main $(EXEC)
	$(EXEC)

#Teste com entradas e saidas. E teste de vazamento de memoria
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

rand_input: rand_gen/rand_gen.cc
	${CC} ${CFLAGS} rand_gen/rand_gen.cc -o rand_input

valgrind_test: rand_input ${EXEC}
	@./rand_input 32 | valgrind ${EXEC}

#Limpando codigo pre-compilado, executavel e arquivo de entradas aleatorias
clean: 
	rm -rf *.o ${EXEC} rand_input
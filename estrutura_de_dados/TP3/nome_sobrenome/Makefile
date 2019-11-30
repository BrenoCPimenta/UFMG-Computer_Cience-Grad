

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
ARV=./arvore
ORD=./ordenacao

#Tipos abstratos de dados
TAD1=CelulaEspecial
TAD2=Lista
TAD3=Hash
TAD4=No
TAD5=Arvore
TAD6=ControleArvore
TAD7=CountSort
TAD8=Insercao
TAD9=Merge

#Pre-Compilando codigo
$(TAD1).o: $(SRC)/$(LIT)/$(TAD1).cpp $(SRC)/$(LIT)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD1).cpp -o CelulaEspecial.o

$(TAD2).o: $(SRC)/$(LIT)/$(TAD2).cpp $(SRC)/$(LIT)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD2).cpp -o Lista.o

$(TAD3).o: $(SRC)/$(HSH)/$(TAD3).cpp $(SRC)/$(HSH)/$(TAD3).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(HSH)/$(TAD3).cpp -o Hash.o

#$(TAD4).o: $(SRC)/$(ARV)/$(TAD4).cpp $(SRC)/$(ARV)/$(TAD4).hpp
#	@$(CC) $(CFLAGS) -c  $(SRC)/$(ARV)/$(TAD4).cpp -o No.o
#
#$(TAD5).o: $(SRC)/$(ARV)/$(TAD5).cpp $(SRC)/$(ARV)/$(TAD5).hpp
#	@$(CC) $(CFLAGS) -c  $(SRC)/$(ARV)/$(TAD5).cpp -o Arvore.o
#
#$(TAD6).o: $(SRC)/$(ARV)/$(TAD6).cpp $(SRC)/$(ARV)/$(TAD6).hpp
#	@$(CC) $(CFLAGS) -c  $(SRC)/$(ARV)/$(TAD6).cpp -o ControleArvore.o
#
#$(TAD7).o: $(SRC)/$(ORD)/$(TAD7).cpp $(SRC)/$(ORD)/$(TAD7).hpp
#	@$(CC) $(CFLAGS) -c  $(SRC)/$(ORD)/$(TAD7).cpp -o CountSort.o
#
#$(TAD8).o: $(SRC)/$(ORD)/$(TAD8).cpp $(SRC)/$(ORD)/$(TAD8).hpp
#	@$(CC) $(CFLAGS) -c  $(SRC)/$(ORD)/$(TAD8).cpp -o Insercao.o
#
#$(TAD9).o: $(SRC)/$(ORD)/$(TAD9).cpp $(SRC)/$(ORD)/$(TAD9).hpp
#	@$(CC) $(CFLAGS) -c  $(SRC)/$(ORD)/$(TAD9).cpp -o Insercao.o




#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o $(TAD3).o 
#$(TAD4).o $(TAD5).o $(TAD6).o $(TAD7).o $(TAD8).o $(TAD9).o 

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

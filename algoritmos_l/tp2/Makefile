#Comandos basicos para a execucao
CC=g++
CFLAGS=-std=c++11 -Wall -Wextra 
EXEC=./tp2 
TMPOUT=tp1.testresult

#Transformando o comando main no padrao
all: main

#Caminhos reutilizaveis
SRC=./src
#Gerando executavel
main: 
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: $(EXEC)
	$(EXEC)

#Limpando codigo pre-compilado e executáveis criados
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf  $(EXEC) 

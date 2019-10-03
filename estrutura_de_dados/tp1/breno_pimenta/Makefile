


#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra 
EXEC=./tp1 
TMPOUT=tp1.testresult


#Transformando o comando main no padrao
all: main

#Caminhos reutilizaveis
SRC=./src
TST=./teste
LIT=./lista

#Tipos abstratos de dados
TAD1=CelulaLista
TAD2=Lista

#Pre-Compilando codigo
$(TAD1).o: $(SRC)/$(LIT)/$(TAD1).cpp $(SRC)/$(LIT)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD1).cpp -o CelulaLista.o

$(TAD2).o: $(SRC)/$(LIT)/$(TAD2).cpp $(SRC)/$(LIT)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD2).cpp -o Lista.o

#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o

#Teste com entradas e saidas
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

#Limpando codigo pre-compilado
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o






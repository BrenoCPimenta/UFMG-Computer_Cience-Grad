#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra 
EXEC=./tp1 
TMPOUT=tp1.testresult


#Transformando o comando main no padrao
all: $(EXEC)


#Caminhos reutilizaveis
SRC=./src


#Tipos abstratos de dados
#...

#Pre-Compilando codigo
#...


#Executando pre-compilacoes nas dependencias e gerando executavel
#...

#Gerando executavel
$(EXEC): 
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: $(EXEC)
	$(EXEC)


#Teste com entradas e saidas. E teste de vazamento de memoria
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)


#Limpando codigo pre-compilado e executáveis criados
clean_all: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o main_test $(EXEC) main_test test.result


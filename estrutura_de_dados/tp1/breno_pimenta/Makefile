

#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra 
EXEC=./tp1 
TMPOUT=tp1.testresult


#Transformando o comando main no padrao
all: $(EXEC)

#Caminhos reutilizaveis
SRC=./src
LIT=./lista
CMDS=./camadas

#Tipos abstratos de dados
TAD1=CelulaEspecial
TAD2=Lista
TAD3=ControleCamadas

#Pre-Compilando codigo
$(TAD1).o: $(SRC)/$(LIT)/$(TAD1).cpp $(SRC)/$(LIT)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD1).cpp -o CelulaEspecial.o

$(TAD2).o: $(SRC)/$(LIT)/$(TAD2).cpp $(SRC)/$(LIT)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(LIT)/$(TAD2).cpp -o Lista.o

$(TAD3).o: $(SRC)/$(CMDS)/$(TAD3).cpp $(SRC)/$(CMDS)/$(TAD3).hpp
	@$(CC) $(CFLAGS) -c  $(SRC)/$(CMDS)/$(TAD3).cpp -o ControleCamadas.o


#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o $(TAD3).o


$(EXEC): main
	$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(TAD3).o $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: main $(EXEC)
	$(EXEC)

#Teste com entradas e saidas
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

#Limpando codigo pre-compilado
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o
	
#Limpando codigo pre-compilado e executáveis criados
clean_all: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o main_test $(EXEC) main_test test.result



#------------------------------------------------------------------------------
TST=./src/testes/

comp_test_code: main 
	@$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(TAD3).o $(TST)Teste.cpp $(TST)main_test.cpp -o main_test

#Teste do codigo
test_code: comp_test_code
	./main_test

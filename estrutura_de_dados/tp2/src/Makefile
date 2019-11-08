

#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra 
EXEC=./tp2 
TMPOUT=tp2.testresult


#Transformando o comando main no padrao
all: $(EXEC)

#Caminhos reutilizaveis
SRC=./src
PLT=./planeta
MRG=./merge
MES=./mes
AGD=./agenda
COT=./count
#RDX=./radix

#Tipos abstratos de dados
TAD1=Planeta
TAD2=Merge
TAD3=Mes
TAD4=Agenda
TAD5=CountSort
#TAD6=RADIX


#Pre-Compilando codigo
$(TAD1).o: $(PLT)/$(TAD1).cpp $(PLT)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(PLT)/$(TAD1).cpp -o Planeta.o
	
$(TAD2).o: $(MRG)/$(TAD2).cpp $(MRG)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(MRG)/$(TAD2).cpp -o Merge.o

$(TAD3).o: $(MES)/$(TAD3).cpp $(MES)/$(TAD3).hpp
	@$(CC) $(CFLAGS) -c  $(MES)/$(TAD3).cpp -o Mes.o

$(TAD4).o: $(AGD)/$(TAD4).cpp $(AGD)/$(TAD4).hpp
	@$(CC) $(CFLAGS) -c  $(AGD)/$(TAD4).cpp -o Agenda.o

$(TAD5).o: $(COT)/$(TAD5).cpp $(COT)/$(TAD5).hpp
	@$(CC) $(CFLAGS) -c  $(COT)/$(TAD5).cpp -o CountSort.o

#$(TAD6).o: $(RDX)/$(TAD6).cpp $(RDX)/$(TAD6).hpp
#	@$(CC) $(CFLAGS) -c  $(RDX)/$(TAD6).cpp -o Radix.o




#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o $(TAD3).o $(TAD4).o $(TAD5).o

$(EXEC): main
	$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(TAD3).o $(TAD4).o $(TAD5).o main.cpp -o $(EXEC)

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

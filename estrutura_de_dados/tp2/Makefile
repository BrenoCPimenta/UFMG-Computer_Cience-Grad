

#Comandos basicos para a execucao
CC=g++
CFLAGS=-Wall -Wextra 
EXEC=./tp2 
TMPOUT=tp2.testresult


#Transformando o comando main no padrao
all: $(EXEC)

#Caminhos reutilizaveis
SRC=./src
PLT=./src/planeta
MRG=./src/merge
AGD=./src/agenda
COT=./src/count
RDX=./src/radix

#Tipos abstratos de dados
TAD1=Planeta
TAD2=Merge
TAD3=Radix
TAD4=Agenda
TAD5=CountSort


#Pre-Compilando codigo
$(TAD1).o: $(PLT)/$(TAD1).cpp $(PLT)/$(TAD1).hpp
	@$(CC) $(CFLAGS) -c  $(PLT)/$(TAD1).cpp -o Planeta.o
	
$(TAD2).o: $(MRG)/$(TAD2).cpp $(MRG)/$(TAD2).hpp
	@$(CC) $(CFLAGS) -c  $(MRG)/$(TAD2).cpp -o Merge.o
	
$(TAD3).o: $(RDX)/$(TAD3).cpp $(RDX)/$(TAD3).hpp
	@$(CC) $(CFLAGS) -c  $(RDX)/$(TAD3).cpp -o Radix.o

$(TAD4).o: $(AGD)/$(TAD4).cpp $(AGD)/$(TAD4).hpp
	@$(CC) $(CFLAGS) -c  $(AGD)/$(TAD4).cpp -o Agenda.o

$(TAD5).o: $(COT)/$(TAD5).cpp $(COT)/$(TAD5).hpp
	@$(CC) $(CFLAGS) -c  $(COT)/$(TAD5).cpp -o CountSort.o




#Executando pre-compilacoes nas dependencias e gerando executavel
main: $(TAD1).o $(TAD2).o $(TAD3).o $(TAD4).o $(TAD5).o 

$(EXEC): main
	$(CC) $(CFLAGS) $(TAD1).o $(TAD2).o $(TAD3).o $(TAD4).o $(TAD5).o  $(SRC)/main.cpp -o $(EXEC)

#Executando a main
run: main $(EXEC)
	$(EXEC)

#Teste com entradas e saidas
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

time_sem_nome: $(EXEC)
	@bash run_time_sem_nome_tests.sh $(EXEC) $(TMPOUT)

time_com_nome: $(EXEC)
	@bash run_time_com_nome_tests.sh $(EXEC) $(TMPOUT)

#Limpando codigo pre-compilado
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o
	
#Limpando codigo pre-compilado e executáveis criados
clean_all: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o main_test $(EXEC) main_test test.result


#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ifstream arquivo;
    string nome_arquivo;
    
    string numeros_da_linha;
    string linha_de_numeros;
    
    int numeros[100];
    int cnt = 0; 

    cin >> nome_arquivo;
    arquivo.open(nome_arquivo.c_str());
    
    if(!arquivo.is_open()){
        cout << "Houve um problema com a leitura do arquivo" << endl;
        return 0;
    }
    
    //Loop nas linhas do arq enquanto passa elas como string
    while(getline(arquivo, linha_de_numeros)){
	   //Usando um buffer de stings com seus chars
	   istringstream iss(linha_de_numeros);
	   
	   //loop dentro do buffer separando os numeros por espaco
	   while(getline(iss, numeros_da_linha,' ')){
		//Transformando as strings em ints
	   	numeros[cnt] = stoi(numeros_da_linha);
		cnt++;
	   }
    }


    int i;
    for(i=0;i<cnt; i++){
	    if(numeros[i]%2 == 0){
		  cout<<numeros[i]<<" ";
	    }
    }
    cout << endl;

    for(i=0;i<cnt; i++){
	    if(numeros[i]%2 != 0){
		  cout<<numeros[i]<<" ";
	    }
    }
    
    arquivo.close();
    return 0;
}

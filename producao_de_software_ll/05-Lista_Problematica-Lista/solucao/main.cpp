#include <iostream>
#include "List.hpp"

int main(){
    List *L = new List();

    int n, k;

    // 1. Recebendo valores
    std::cout << "Por favor entre com os valores de N e K: " << std::endl;
    std::cin >> n >> k;
	
    // 2. Inserindo valores [0...N]
    if(n>=0){
	    for(int i=0; i<=n; i++){
        	L->insert(i);
    	    }
    }

    // 3. Imprimindo lista
    L->print();

    // 4. Imprimindo tamanho da lista
    std::cout << L->size << std::endl;

    // 5. Remova os k primeiros valores
    
    if(n>0){
    	for(int i=0; i<k; i++){
	    L->removeFirst();
        }
    }

    // 6. Imprima a lista
    L->print();

    // 7. Imprima tamanho da lista
    std::cout << L->size << std::endl;

    // 8. Remova os valores pares da lista
    int aux = L->size;
    for(int i=0; i<aux; i++){
	if(i%2 == 0){
		L->remove(i);
	}
    } 
    // 9. Imprima a lista
    L->print();

    // 10. Imprima tamanho da lista
    std::cout << L->size << std::endl;

    L->clearList();
    delete L;
    return 0;
}

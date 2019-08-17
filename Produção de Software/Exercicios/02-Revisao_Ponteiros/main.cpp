#include <iostream>

#define SIZE 5

using namespace std;

int main(){
    long value1=200000;
    long value2;
    
    // 1
    long *long_ptr;
    
    // 2
    long_ptr = &value1;
    
    // 3 imprima o valor do objeto apontado por long_ptr
    cout << *long_ptr << ' ';
    
    // 4
    value2 = *long_ptr;
    
    // 5 Imprima o valor de value2
    cout << value2 << ' ';
    
    // 6 Imprima o endereço de value1
    cout << &value1 << ' ';
    
    // 7.1 Imprima o endereço armazenado em long_ptr
    cout << long_ptr << ' ';
    
    // 7.2 Imprima a comparação entre o endereço de value1 com o endereço armazenado em long_ptr
    cout << (long_ptr == &value1) << ' ';
    
    // 8 
    unsigned int values[5] = {2,4,6,8,10};
    
    // 9 
    unsigned int *v_ptr;
        
    // 10 imprimir os elementos do array values usando notação de array subscrito.
    for(int i=0; i<5; i++) cout<< values[i] << ' ';
    
    // 11 
    v_ptr = &values[0];
    v_ptr = values;
    
    // 12 imprimir os elementos do array values usando notação de array ponteiro/deslocamento.
    for(int i=0; i<5; i++) cout<< *(v_ptr + i) <<' ';
    
    // 13 imprimir os elementos do array values usando notação de array ponteiro/deslocamento com o nome de array como o ponteiro.
    for(int i=0; i<5; i++) cout<< *(values + i) << ' ';
    
    // 14 imprimir os elementos do array values utilizando subscritos no ponteiro para o array.
    for(int i=0; i<5; i++) cout<< v_ptr[i] << ' ';
    
    
    //     15
    //  imprimir o quinto elemento de values utilizando a notação de subscrito de array,
    cout << values[4] << ' ';  
    //a notação de ponteiro/deslocamento com o nome de array como o ponteiro, 
    cout << *(values + 4) << ' ';
    //a notação de subscrito de ponteiro,
    cout << v_ptr[4] << ' ';
    //a notação de ponteiro/deslocamento.
    cout << *(v_ptr + 4) << ' ';
    
    // 16
    cout << (v_ptr + 3) << ' '; //Endereço
    cout << *(v_ptr + 3) << ' '; // Valor
    
    // 17
    //imprimir a comparação entre o valor armazenado em (v_ptr-4) e values[0]
    // Se v_ptr=values[4]... se -4, entao v_ptr=values[0]
    cout << &(v_ptr) << ' '; //Endereço
    cout << *(v_ptr); //Valor
    
    return 0;
}
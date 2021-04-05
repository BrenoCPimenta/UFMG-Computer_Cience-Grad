#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


int main(void){
    int numero_pedras;
    std::vector<int> pesos;
    int input;
    cin >> numero_pedras;
    if (numero_pedras <= 0){
        cout << 0 <<endl;
        return 1;
    }

    for(int i = 0; i < numero_pedras; ++i) {
        cin >> input;
        if(input < 0){
            cout << 0 <<endl;
            return 1;     
        }
        pesos.push_back(input);
    }

    if (numero_pedras == 1){
        cout << pesos[0] << endl;
        return 0;
    }

    if(numero_pedras == 2) {
        int resultado = pesos[0] - pesos[1];
        if(resultado < 0){
            resultado *= -1;
        }
        cout << resultado << endl;
        return 0;
    }

    int soma_total = 0;
    for (auto& valor : pesos)
        soma_total += valor;
    
    int metade_soma = soma_total/2;

    //-----------------------Verifica grandes numeros
    //Caso tenha numero >= metade da soma:
    int diferenca_grandes_numeros = 0;
    bool possui_grande_numero = false;
    for(int i = 0; i < numero_pedras; i++) {
        if (pesos[i] < metade_soma) {
            diferenca_grandes_numeros -= pesos[i];
        } else {
            possui_grande_numero = true;
            diferenca_grandes_numeros += pesos[i];
        }
    }
    if(possui_grande_numero){
        cout << diferenca_grandes_numeros << endl;
        return 0;
    }


    //-----------------------Caso nao possua numero >= metade da soma:
    bool tabela_dp[numero_pedras][metade_soma + 1];

    //Todos sao possiveis com a soma zero 
    for(int i = 0; i < numero_pedras; i++)
        tabela_dp[i][0] = true;

    //Todas as colunas da primeira linha sao falsas, menos a primeira
    for(int j = 1; j <= metade_soma; j++){
        tabela_dp[0][j] = false;
    }

    //A Primeira linha tambem vai ter o valor inicial dos pesos como true
    tabela_dp[0][pesos[0]] = true;

    for(int i = 1; i < numero_pedras; i++) {
        for(int j = 1; j <= metade_soma; j++) {
            if(tabela_dp[i - 1][j]) {
                tabela_dp[i][j] = true;
            } else {
                if(j >= pesos[i]) {
                    tabela_dp[i][j] = tabela_dp[i - 1][j - pesos[i]];  
                } else {
                    tabela_dp[i][j] = false;
                }
            }
        }
    }

    int ultima_linha = numero_pedras - 1;
    int soma_primeiro_subset = -1;

    for(int j = metade_soma; j >= 0; j--) {
      if(tabela_dp[ultima_linha][j]) {
        soma_primeiro_subset = j;
        break;
      }
    }

    int soma_segundo_subset = soma_total - soma_primeiro_subset;
    int diferenca_minima = soma_segundo_subset - soma_primeiro_subset;

    //Buscando valor absoluto
    if (diferenca_minima < 0){
        diferenca_minima *= -1;
    }

    cout << diferenca_minima << endl;
    return 0;
}

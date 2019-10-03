#include <cstdio> // em C substituir por #include <stdio.h>
#include "foo.h"

int main() {
  int q;
  char e;
  while(scanf("%d %c", &q, &e) != EOF) {
    if (e == 'p')
      // veja que a funcao bar() sempre retorna 1, entao o programa sempre
      // vai imprimir 1.
      // Troque essa funcao (inclusive o nome dela) caso queira tirar uma nota
      // melhor no TP!
      printf("%d\n", bar());
  }
  return 0;
}



#ifndef NO_H
#define NO_H


class No{
  private:
    No* filho_direita;
    No* filho_esquerda;
    No* pai;
    char _nome[63];
    int _repeticao;
    int _folhas;
    
  public:
    No(char*, int, int);
    char* getNome();
    int getRepeticao();
    int getFolhas();
    void setFilhos();
  
  
};

#endif
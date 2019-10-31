#ifndef PLANETA_H 
#define PLANETA_H 

using namespace std;

class Planeta{

  private:
    int _t;
    char* _ponteiro_inicio_nome;
    int _tamanho_nome;
  

  public:
    Planeta(int, char*, int);
    Planeta();
    ~Planeta();
    
    int getTempoVisita();
    char* getPrimeiraLetraNome();
    bool limparNome();
};

#endif

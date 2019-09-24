


using namespace std;

class Celula{
  private:
    int valor = NULL;
    int endereco_proxima_celula = NULL;

  public:
    Celula(int valor, int proxima_celula){
      this->valor = valor;
      this->endereco_proxima_celula = proxima_celula;
    }
    
    int getProximaCelula(){
      return endereco_proxima_celula;
    }

    int getValor(){
      return valor;
    }
}

/*	Codigo para calculo de digitos verificadores
*	Breno de Castro Pimenta
*	UFMG - 19/10/2017
*/

#include <stdlib.h>
#include <stdio.h>

// funcao : calcula o digito verificador de isbn13 dados seus digitos
// recebe : arranjo de numeros contendo os digitos do isbn13
// retorna: valor do digito verificador do isbn13

int digito_isbn13 (int d[12]) {
  // soma das posicoes pares
  int pares   = d[0] + d[2] + d[4] + d[6] + d[8] + d[10];
  // soma das posicoes impares
  int impares = d[1] + d[3] + d[5] + d[7] + d[9] + d[11];

  // soma final
  int soma = pares + (impares * 3);

  // calcula digito verificador
  int dv = 10 - (soma % 10);

  // corrige digito verificador caso ele seja igual a 10
  if (dv == 10) {
    dv = 0;
  }

  // retorna digito verificador
  return dv;
}

// funcao : calcula o digito verificador de cpf dados seus digitos
// recebe : arranjo de numeros contendo os digitos do cp// retorna: valor do digito verificador do cpf

int digito_cpf (int d[9]) {
  // primeira soma de produtos
  int soma = d[8] * 2 + d[7] * 3 + d[6] * 4 + d[5] * 5 +
             d[4] * 6 + d[3] * 7 + d[2] * 8 + d[1] * 9 + d[0] * 10;

  // resto da soma
  int resto = soma % 11;
  // variaveis auxiliares
  int dezena, unidade;

  // define valor da dezena
  if (resto == 0 || resto == 1) {
    dezena = 0;	
  } else {
    dezena = 11 - resto;
  }

  // segunda soma de produtos
  soma = dezena * 2 + d[8] * 3 + d[7] * 4 + d[6] *  5 + d[5] *  6 +
         d[4]   * 7 + d[3] * 8 + d[2] * 9 + d[1] * 10 + d[0] * 11;

  // resto da soma
  resto = soma % 11;

  // define valor da unidade
  if (resto == 0 || resto == 1) {
    unidade = 0;
  } else {
    unidade = 11 - resto;
  }

  // retorna digito verificador
  return dezena * 10 + unidade;
}

// funcao : calcula o digito verificador de cnpj dados seus digitos
// recebe : arranjo de numeros contendo os digitos do cnpj
// retorna: valor do digito verificador do cnpj

int digito_cnpj (int d[12]) {
  // primeira soma de produtos
  int soma = d[11] * 2 + d[10] * 3 + d[9] * 4 + d[8] * 5 + d[7] * 6 + d[6] * 7 +
             d[ 5] * 8 + d[ 4] * 9 + d[3] * 2 + d[2] * 3 + d[1] * 4 + d[0] * 5;

  // resto da soma
  int resto = soma % 11;
  // variaveis auxiliares
  int dezena, unidade;

  // define valor da dezena
  if (resto == 0 || resto == 1) {
    dezena = 0;
  } else {
    dezena = 11 - resto;
  }

  // segunda soma de produtos
  soma = dezena * 2 + d[11] * 3 + d[10] * 4 + d[9] * 5 + d[8] * 6 + d[7] * 7 +
         d[6]   * 8 + d[ 5] * 9 + d[ 4] * 2 + d[3] * 3 + d[2] * 4 + d[1] * 5 +
         d[0]   * 6;

  // resto da soma
  resto = soma % 11;

  // define valor da unidade
  if (resto == 0 || resto == 1) {
    unidade = 0;
  } else {
    unidade = 11 - resto;
  }

  // retorna digito verificador
  return dezena * 10 + unidade;
}

int main (int argc, char **argv) {

	int cadastro, i;
	int bln = 1; //TRUE
	int verificador, veriCalc;
	int isbn[12];
	int cpf[9];
	int cnpj[12];
	while(bln){
		scanf("%d",&cadastro);

		switch(cadastro){
			case 0 :
				bln = 0;
				break;
			case 1 :
				for(i=0;i<12;i++){
					if(i==11){
						scanf("%d", &isbn[11]);
						printf("\n");
					}else{
						scanf("%d", &isbn[i]);
					}
				}
				scanf("%d",&veriCalc);
				printf("\n");
				verificador = digito_isbn13(isbn);
				if(verificador==veriCalc){
					printf("valido\n");
				}else{
					printf("invalido\n");
				}

				break;

                	case 2 :
				for(i=0;i<9;i++){
                                        if(i==8){
                                                scanf("%d", &cpf[8]);
                                                printf("\n");
                                        }else{
                                                scanf("%d", &cpf[i]);
                                        }
                                }
                                scanf("%d",&veriCalc);
                                printf("\n");
                                verificador = digito_cpf(cpf);
                                if(verificador==veriCalc){
                                        printf("valido\n");
                                }else{
                                        printf("invalido\n");
                                }
                        	break;

                	case 3 :
				for(i=0;i<12;i++){
                                        if(i==11){
                                                scanf("%d", &cnpj[11]);
                                                printf("\n");
                                        }else{
                                                scanf("%d", &cnpj[i]);
                                        }
                                }
                                scanf("%d",&veriCalc);
                                printf("\n");
                                verificador = digito_cnpj(cnpj);
                                if(verificador==veriCalc){
                                        printf("valido\n");
                                }else{
                                        printf("invalido\n");
                                }
                        	break;

			default :
				printf("invalido\n");
				break;
		}
	}


  return 0;
}


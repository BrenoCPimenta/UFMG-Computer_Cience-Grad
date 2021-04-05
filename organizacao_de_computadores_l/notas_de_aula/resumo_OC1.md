# RISC-5

## Registradores

>> Operandos de instruções Aritméticas devem   ser registradores,  — Compilador associa variáveis com registradores.
### Só 32 registradores existem:
* nx0: the constant value 0 
* nx1: return address 
* nx2: stack pointer 
* nx3: global pointer 
* nx4: thread pointer 
* nx5 – x7, x28 – x31: temporaries 
* nx8: frame pointer 
* nx9, x18 – x27: saved registers 
* nx10 – x11: function arguments/results 
* nx12 – x17: function arguments

## Intruções Aritméticas:

O primeiro registrador é o destino, os outros dois são os que serão operados.
* add x6, x22, x23 
* sub x19, x5, x6
* addi x6, x22, 15 

## Instruções Acesso à Memória

>Load – Carrega conteúdo da memória para o registrador 
* ld x5, 8(x6)
>Store – Copia conteúdo do registrador na memória 
* sd x5, 8(x6)

x6 contém um endereço de memória, no caso de arquiteturas 64bits andamos de 8 em 8 bytes <8(x6) 16(x6)...>, já em arquiteturas 32 bits, andamos de 4 em 4 bytes <4(x6) 8(x6)>.

O registrador x5 no caso do load recebe o valor da posição da memória e no caso do store o seu valor é copiado na memória.

## Instruções Condicionais
Desvia para a instrução marcada se a condição for verdadeira.
Caso contrário, continua sequencialmente 
* beq rs1, rs2, L1 
> se (rs1 == rs2) desvia para a instrução marcada L1 
* bne rs1, rs2, L1 
> se (rs1 != rs2) desvia para a instrução marcada L1 
* blt rs1, rs2, L1 
>Se (rs1 < rs2) desvia para a instrução marcada L1 
* bge rs1, rs2, L1 
> se (rs1 >= rs2) desvia para a instrução marcada L1 

## Instruções Lógicas
Instruções para manipulação de bits

* slli -> ShiftLeft
* srli -> ShiftRight
* and ou andi -> Bit-by-bit AND
* or ou ori -> Bit-by-bit OR
* xor ou xori -> Bit-by-bit XOR ou Bit-by-bit NOT
>Exemplo: or x9,x10,x11


## Exemplos:

1. IF:
~~~
      bne x22, x23, Else
      add x19, x20, x21 
      beq x0,x0,Exit // incondicional
Else: sub x19, x20, x21 
Exit: ...
~~~
*Obs:* O Else e o Exit são chamados de Label

2. FOR:
~~~
Loop: slli x10, x22, 3
      add  x10, x10, x25 
      ld   x9, 0(x10) 
      bne  x9, x24, Exit
      addi x22, x22, 1 
      beq  x0, x0, Loop 
Exit: ...
~~~

## Instruções de procedimento
Procedimentos são o equivalente a funções.
* jal x1
>Pula para o procedimento e coloca o endereço de retorno em x1
>> x1 = PC + 4
* jalr x0, 0(x1)
> Volta para endereço armazenado em x1


## STACK POINTER
Ponteiro para a pilha:
* Alocando a memória: 
  * addi sp, sp, -24
* Usando:
  * Copiando valores para a pilha:
    * sd x5, 16(sp)
    * sd x6, 8(sp)
    * sd x20, 0(sp)
  * Voltando com os valores:
    * ld x20, 0(sp)
    * ld x6, 8(sp)
    * ld x5, 16(sp)
* Desalocando: 
    * addi sp, sp, 24

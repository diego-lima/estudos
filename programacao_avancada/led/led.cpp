#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int NC = 8; // numero de colunas

int comparativa(char a, char b){
  int pot;
  for(int i=0; i<8; i++){
    pot = (int) pow(2,i);
    if( (pot & a) != (pot & b) ){
      return 0;
    }
  }
  return 1;
}

unsigned char prepara(char* coluna){

    int acumulador = 0; // vamos acumular aqui as somas das potencias de 2 para no final ter um numero decimal
    unsigned char bits; // o retorno, que sera resultado da conversao do acumulador
    

    for(int i=0; i<NC; i++){
        if(comparativa(coluna[i],'1')){
            acumulador = acumulador + pow(2,i); // se, naquela coluna tem 1, entao o bit daquela potencia eh 1
        }
    }

    printf("acumulador: %d\n", acumulador);

    bits = acumulador;
    return bits;
}

int main(){
    char coluna[] = {'0','0','0','0','0','0','1','0'};
    unsigned char bits;
    // Printando alguns testes
    printf("----ASSERTS----\n");
    printf("'1' comparativa '1': %d\n", comparativa('1', '1'));
    printf("coluna[0] comparativa '1': %d\n", comparativa(coluna[0], '1'));
    printf("----ASSERTS----\n\n");

    // Executando o programa realmente
    bits = prepara(coluna);
    printf("bits: %c\n", bits);
    
    return 0;
}
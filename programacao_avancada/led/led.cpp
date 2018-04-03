#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int NC = 8; // numero de colunas

unsigned char prepara(char* coluna){

    int acumulador = 0; // vamos acumular aqui as somas das potencias de 2 para no final ter um numero decimal
    unsigned char bits; // o retorno, que sera resultado da conversao do acumulador
    

    for(int i=0; i<NC; i++){
        if(comparativa(coluna[i],'0')) acumulador = acumulador + pow(2,i); // se, naquela coluna tem 1, entao o bit daquela potencia eh 1
    }
    return bits;
}

int comparativa(char a, char b){
  int pot;
  for(int i=0; i<8; i++){
    pot = (int) pow(2,i);
    if(pot & a != pot & b){
      return 0;
    }
  }
  return 1;
}

int main(){

  char a = '0', b = '0';

  int r = comparativa(a,b);

  printf("%d\n", r);

  return 0;
}
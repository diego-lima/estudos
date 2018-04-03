#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned char prepara(char* coluna){

  char ret[8];

  x[1] x[]

  for(int i=0; i<8; i++){
    if(comparativa(coluna[i],'0')){
      ret [i]='0';
    }else if(comparativa(coluna[i],'1')){
      ret[i]='1';
    }
  }
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
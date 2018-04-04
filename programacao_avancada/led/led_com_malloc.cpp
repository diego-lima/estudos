#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "snippets.cpp"

const int NL = 8; // numero de linhas constante
const int NC = 3; // numero de colunas constante
const int N_BITS=8; // bits em um byte

int comparativa(char a, char b){
    /*
    Essa funcao recebe dois chars, e verifica se seus bits sao todos iguais.
    Se sim, retorna 1
    Se nao, retorna 0
    */
  int pot; // potencias
  for(int i=0; i<N_BITS; i++){
    pot = (int) pow(2,i);
    if( (pot & a) != (pot & b) ){
      return 0;
    }
  }
  return 1;
}

unsigned char prepara(char **m, int c){
    /*
    Recebe uma matriz de char, preeenchida com '0' e '1'
    Recebe uma coluna, indicando qual deverá ser codificada
    O retorno é a sequencia correspondente de bits convertida para char.
    A leitura do vetor é no sentido do LSB na primeira posicao para o MSB na ultima.
    */

    int acumulador = 0; // vamos acumular aqui as somas das potencias de 2 para no final ter um numero decimal
    unsigned char bits; // o retorno, que sera resultado da conversao do acumulador
    

    for(int i=0; i<NL; i++){
        if(comparativa(m[i][c],'1')){
            acumulador = acumulador + pow(2,i); // se, naquela coluna tem 1, entao o bit daquela potencia eh 1
        }
    }

    printf("acumulador: %d\n", acumulador);

    bits = acumulador;
    return bits;
}

char *reconstroi(char **m, int c, char bits){
    /*
    Recebe uma matriz, onde sera feita a reconstrucao
    Recebe a coluna desejada
    Recebe um char, de onde serao extraidos os bits
    O primeiro elemento do vetor correspondera ao LSB do char
    O ultimo elemento do vetor correspondera ao MSB do char
    */
    int extrator_bits; // faremos 'e lógico' com potencias de 2 para extrair bit de cada 'casa'
    for (int i = 0; i < N_BITS; i++){
        extrator_bits = pow(2,i); // potencia de 2
        
        if ( (bits & extrator_bits) != 0) //as potencias de 2 tem um '1' em apenas uma 'casa'
            m[i][c] = '1';
        else
            m[i][c] = '0';
    }
}

int main(){
    char **matriz;
    char **matriz_reconstruida;
    unsigned char bits;
    int coluna = 0, i, j;

    // 
    // Alocando as matrizes
    // 

    // original
    matriz = (char**) malloc(NL*sizeof(char*));
    matriz[0] = (char*) malloc(NL*NC*sizeof(char));
    for (i = 1; i < NL; i++){
        matriz[i] = matriz[i-1] + NC;
    }
    // Inicializando somente a original
    for(i=0; i<NL; i++){
        for(j=0; j<NC; j++){
            matriz[i][j] = '1';
        }
    }

    // reconstruida
    matriz_reconstruida = (char**) malloc(NL*sizeof(char*));
    matriz_reconstruida[0] = (char*) malloc(NL*NC*sizeof(char));
    for (i = 1; i < NL; i++){
        matriz_reconstruida[i] = matriz_reconstruida[i-1] + NC;
    }

    // 
    // TRANSMISSOR
    // 

    printf("matriz:\n");
    printar_matriz(matriz, NL, NC);
    bits = prepara(matriz, coluna);                        //comprimindo e guardando num char apenas
    printf("bits: %c\n", bits);
    // bits seria enviado de alguma forma
    
    // 
    // RECEPTOR
    // 

    // bits é recebido de algum lugar
    reconstroi(matriz_reconstruida, coluna, bits);
    printf("matriz reconstruida:\n");
    printar_matriz(matriz_reconstruida, NL, NC);
    
    return 0;
}
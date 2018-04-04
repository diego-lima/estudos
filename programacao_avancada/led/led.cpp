#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int NC = 8; // numero de colunas
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

unsigned char prepara(char* coluna){
    /*
    Recebe um vetor de char, preeenchido com '0' e '1'
    O retorno é a sequencia correspondente de bits convertida para char.
    A leitura do vetor é no sentido do LSB na primeira posicao para o MSB na ultima.
    */

    int acumulador = 0; // vamos acumular aqui as somas das potencias de 2 para no final ter um numero decimal
    unsigned char bits; // o retorno, que sera resultado da conversao do acumulador
    

    for(int i=0; i<NC; i++){
        if(comparativa(coluna[i],'1')){
            acumulador = acumulador + pow(2,i); // se, naquela coluna tem 1, entao o bit daquela potencia eh 1
        }
    }

    bits = acumulador;
    return bits;
}

char *reconstroi(char *vetor, char bits){
    /*
    Recebe um vetor, onde sera feita a reconstrucao
    Recebe um char, de onde serao extraidos os bits
    O primeiro elemento do vetor correspondera ao LSB do char
    O ultimo elemento do vetor correspondera ao MSB do char
    */
    int extrator_bits; // faremos 'e lógico' com potencias de 2 para extrair bit de cada 'casa'
    for (int i = 0; i < N_BITS; i++){
        extrator_bits = pow(2,i); // potencia de 2
        
        if ( (bits & extrator_bits) != 0) //as potencias de 2 tem um '1' em apenas uma 'casa'
            vetor[i] = '1';
        else
            vetor[i] = '0';
    }
}

int main(){
    char coluna[] = {'0','0','0','0','0','0','1','0'};
    char coluna_recebida[8];
    unsigned char bits;
    // Printando alguns testes
    printf("----ASSERTS----\n");
    printf("'1' comparativa '1': %d\n", comparativa('1', '1'));
    printf("coluna[0] comparativa '1': %d\n", comparativa(coluna[0], '1'));
    printf("----ASSERTS----\n\n");

    // Executando o programa realmente

    // 
    // TRANSMISSOR
    // 

    printf("coluna:              %.8s\n", coluna); // printando o vetor de char, somente 8 caracteres
    bits = prepara(coluna);                        //comprimindo e guardando num char apenas
    printf("bits: %c\n", bits);
    // bits seria enviado de alguma forma
    
    // 
    // RECEPTOR
    // 

    // bits é recebido de algum lugar
    reconstroi(coluna_recebida, bits);
    printf("coluna recebida:     %.8s\n", coluna_recebida);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "gc.h"
#include "time.h"

int main(){
	float *v;
	int tam, i, iter;
	clock_t tempoInicial, tempoFinal;
	double tempoGasto;

    GC_INIT();

	printf("Criando vetores (alocando) de 20000 elementos e desalocando em seguida\n");
	printf("\n");
	tam = 5000;

	// Vamos usar o conjunto GC_MALLOC e GC_FREE varias vezes e medir o tempo
	for (iter=1; iter<=4; iter++){
		tempoInicial = clock();
		printf("LIBC: Vetores de %d elementos: ",iter * tam);
		for (i = 0; i<1000000; i++){
			v = (float *) GC_MALLOC(iter*tam*sizeof(float));
			GC_FREE(v);
		}
		tempoFinal = clock();
		tempoGasto = (float)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
		printf("%f\n", tempoGasto);
	}
	

	printf("\n");

	// Vamos usar o conjunto malloc e free varias vezes e medir o tempo
	for (iter=1; iter<=4; iter++){
		tempoInicial = clock();
		printf("STDLIB: Vetores de %d elementos: ",iter * tam);
		for (i = 0; i<1000000; i++){
			v = (float *) malloc(iter*tam*sizeof(float));
			free(v);
		}
		tempoFinal = clock();
		tempoGasto = (float)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
		printf("%f\n", tempoGasto);
	}
	

	printf("\n");

}
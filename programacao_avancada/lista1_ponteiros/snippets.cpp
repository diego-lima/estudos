#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    float *v;

    // Printar vetor
    for (i=0; i<tam; i++){
		printf("%f\n", v[i]);
	}

    // Ler vetor
    for (i=0; i<tam; i++){
		scanf("%f", v+i);
	}

    // Printar matriz
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++){
        printf("%.2f ", x[i][j]);
        }
        printf("\n");
    }

    // Ler matriz
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++){
        x[i][j] = i*(nl+1) + j+1;
        }
    }



    return 0;
}


// Bloco main limpo
int main(){

    return 0;
}
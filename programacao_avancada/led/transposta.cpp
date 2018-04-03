#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float* transposta(float* x, int nl, int nc){
    float *y;
    int i,j;
    y = (float*) malloc(nl*nc*sizeof(float));

    memcpy(y, x, nl*nc*sizeof(float));

    for(i = 0; i < nl; i++){
        for(j = 0; j < nc; j++){
            x[j*nl + i] = y[i*nc + j];
        }
    }

}

int main(){
    float *A;
    int nl=2, nc=3, i;

    // 
    // MATRIZ A
    // 
    // Alocar
    A = (float*) malloc(nl*nc*sizeof(float));

    // Preencher
    for(i=0; i<nl*nc; i++){
        A[i] = i;
    }


    // Printar
    printf("A: \n");
    for(i=0; i<nl*nc; i++){
        printf("%.0f ", A[i]);
        if ( (i+1) % nc == 0){
            printf("\n");
        }
    }
    printf("\n");

    transposta(A, nl, nc);

    // Printar
    for(i=0; i<nl*nc; i++){
        printf("%.0f ", A[i]);
        if ( (i+1) % nl == 0){
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
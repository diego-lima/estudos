#include <stdio.h>
#include <stdlib.h>

int ao_quadrado (const int x){
    // Uma funcao qualquer que define um certo comportamento
    return x*x;
}

float dividir(float x){
    return ((float) x)/2;
}

template <class T>
void map(T (*op)(T), T *l, int tam){
    // (*op) = um ponteiro de funcao
    // *l = alguma lista
    // tam = quantidade de elementos
    // --------
    // vamos aplicar a funcao op na lista l
    // seja la qual for a funcao op,
    // seja la qual for a lista l.
    int i;

    for (i=0; i<tam; i++){
        l[i] = op( l[i] );
    }

}


int main(){
    // int v[] = {1,2,3,4};
    float v[] = {1.0,2.0,3.0,4.0};
    int i, tam=4;

    // map(ao_quadrado, v, tam);
    map(dividir, v, tam);

    // Printar vetor
    for (i=0; i<tam; i++){
        // printf("%d\n", v[i]);
		printf("%.2f\n", v[i]);
	}    
    
	
}
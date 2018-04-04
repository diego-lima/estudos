#include <stdio.h>
#include <stdlib.h>

using namespace std;


void printar_matriz(char m[][3], int nl, int nc){
    int i, j;
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++){
        printf("%c ", m[i][j]);
        }
        printf("\n");
    }
    
}

void hi(void){
    printf("hi\n");
}

// int main(){
//     float **v;
//     int i, j, nc, nl;
//     // Printar matriz
//     for(i=0; i<nl; i++){
//         for(j=0; j<nc; j++){
//         printf("%.2f ", v[i][j]);
//         }
//         printf("\n");
//     }

//     // Ler matriz
//     for(i=0; i<nl; i++){
//         for(j=0; j<nc; j++){
//         v[i][j] = i*(nl+1) + j+1;
//         }
//     }



//     return 0;
// }
#include <iostream>
#include "headers/poligono.h"
#include "headers/ponto.h"

#ifndef QTD_PADRAO_PONTOS_100
#define QTD_PADRAO_PONTOS_100 100
#endif

Poligono::Poligono(){
    pontos = new Ponto[QTD_PADRAO_PONTOS_100];
    qtd_pontos_maxima = QTD_PADRAO_PONTOS_100;
    qtd_pontos = 0;
}

Poligono::Poligono(int n){
    pontos = new Ponto[n];
    qtd_pontos_maxima = n;
    qtd_pontos = 0;
}

Poligono::~Poligono(){
    delete [] pontos;
}

int Poligono::quantidade_pontos(void){
    return qtd_pontos;
}

bool Poligono::adicionar_ponto(Ponto p){

    if (qtd_pontos >= qtd_pontos_maxima)
        return false;

    pontos[qtd_pontos] = p;
    qtd_pontos = qtd_pontos + 1;
    return true;

}

void Poligono::print(void){
    int i;

    if (qtd_pontos == 0){
        printf("Vazio\n");
        return;
    }

    for (i = 0; i < qtd_pontos; i++){
        pontos[i].print();

        if (i < qtd_pontos - 1)
            printf("->");
    }
    printf("\n");


}

void Poligono::transladar(float a, float b){
    int i;
    for (i = 0; i < qtd_pontos; i++)
        pontos[i].transladar(a, b);
}

float Poligono::area(void){
    int i;
    float left=0, right=0;

    if (qtd_pontos < 3){
        printf("Area nula\n");
        return 0;
    }

    for (i = 0; i < qtd_pontos - 1; i++){
        left = left + ( pontos[i].x() * pontos[i+1].y() );
    }

    for (i = 1; i < qtd_pontos; i++){
        right = right + ( pontos[i].x() * pontos[i-1].y() );
    }

    // Area = (1/2) * |left - right|
    return 0.5 * abs(left - right);
}

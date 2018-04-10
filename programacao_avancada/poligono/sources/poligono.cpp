#include <iostream>
#include "headers/poligono.h"
#include "headers/ponto.h"
#include "headers/linha.h"

#ifndef QTD_PADRAO_PONTOS_100
#define QTD_PADRAO_PONTOS_100 100
#endif

#ifndef NENHUMA
#define NENHUMA -1
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

    printf("Poligono ");

    if (qtd_pontos == 0){
        printf("Vazio\n");
        return;
    }

    for (i = 0; i < qtd_pontos; i++){
        pontos[i].print();
        printf("->");
    }
    pontos[0].print();
    printf("\n");


}

void Poligono::transladar(float a, float b){
    int i;
    for (i = 0; i < qtd_pontos; i++)
        pontos[i].transladar(a, b);
}

float Poligono::area(void){
    int i, indice_intersecao;
    float left=0, right=0;
    Ponto p;

    if (qtd_pontos < 3){
        printf("Area nula\n");
        return 0;
    }

    // indice_intersecao será o índice da primeira linha em que foi detectada
    // interseção.
    // p será o ponto onde acontece essa interseção.
    indice_intersecao = self_intersect(&p);
    if (indice_intersecao  == NENHUMA){
        //
        // POLIGONO É SIMPLES: APLICA SHOELACE NORMALMENTE
        //

        // Do primeiro ate o penultimo
        for (i = 0; i < qtd_pontos - 1; i++){
            left = left + ( pontos[i].x() * pontos[i+1].y() );
        }

        // Do segundo ate o ultimo
        for (i = 1; i < qtd_pontos; i++){
            right = right + ( pontos[i].x() * pontos[i-1].y() );
        }

        // Area = (1/2) * |left - right|
        return 0.5 * abs(left - right);
    }
    else{
        //
        // POLIGONO NÃO É SIMPLES: SUBDIVIDE EM POLIGONOS SIMPLES
        //
        Poligono subpoligono1, subpoligono2;

        // Adicionar os pontos do primeiro subpoligono:
        // começando do primeiro ponto do poligono original, até
        // o ponto de interseção
        for (i=0; i <= indice_intersecao; i++)
            subpoligono1.adicionar_ponto(pontos[i]);

        subpoligono1.adicionar_ponto(p); // Adicionando o ponto de interseção

        // Adicionar os pontos do segundo subpoligono:
        // começando do ponto de interseção e retornando a ele novamente
        subpoligono2.adicionar_ponto(p); // Adicionando o ponto de interseção
        for (i=indice_intersecao + 1; i < qtd_pontos; i++)
            subpoligono2.adicionar_ponto(pontos[i]);

        // Recursivamente iremos subdividir os poligonos
        // até que só existam polígonos simples. A área total será
        // a soma da área de todos os subpolígonos.
        return ( subpoligono1.area() + subpoligono2.area() );

    }
}

bool Poligono::contem_ponto(Ponto p){
    int i;
    for (i = 0; i < qtd_pontos; i++){
        if ( pontos[i].igual(p) )
            return true;
    }
    return false;

}

int Poligono::self_intersect(Ponto *p){
    int i, j;
    Linha *l = new Linha[qtd_pontos];

    if (qtd_pontos < 3)
        return NENHUMA; // Nao é poligono ainda

    // Criar todas as linhas ligando os pontos
    for(i = 0; i < qtd_pontos - 1; i++){
        l[i] = Linha(pontos[i], pontos[i+1]);
    }

    // Criar a linha que liga o final e o inicial
    l[qtd_pontos-1] = Linha(pontos[qtd_pontos-1], pontos[0]);

    // Checar se algum par de linhas se intercepta
    for (i = 0; i < qtd_pontos; i++){
        for (j = i+1; j < qtd_pontos; j++){ // So verifica uma linha com as seguintes
            if ( intersecao(l[i], l[j], p) && !contem_ponto(*p) )
                return i;
        }
    }

    delete [] l;
    return NENHUMA;

}




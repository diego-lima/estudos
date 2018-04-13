#include <iostream>
#include <math.h>

#include "headers/ponto.h"
#include "headers/linha.h"
#include "headers/poligono.h"
#include "headers/retangulo.h"
#include "headers/mostrador.h"

#define NENHUMA -1

int main(int argc, char *argv[]){
    Poligono retangulo, triangulo, retriangulo, self_intersect;
    Ponto p, p2, p_intersecao;
    char ret;
    Linha *linhas = new Linha[2];

    //
    // LINHA 1
    //
    p.xy(0, 0);
    p2.xy(2,0);
    linhas[0] = Linha(p, p2);
    printf("Linha 0: ");
    linhas[0].print();

    //
    // LINHA 2
    //
    p.xy(2, 0);
    p2.xy(2,1);
    linhas[1] = Linha(p, p2);
    printf("Linha 1: ");
    linhas[1].print();

    //
    // INTERSECAO ENTRE LINHAS
    //
    printf("Intersecao entre linhas: ");
    ret = intersecao(linhas[0] ,linhas[1], &p_intersecao);
    if (ret && !linhas[0].limitada_por(p_intersecao))
        p_intersecao.print();

    //
    // IGUALDADE ENTRE PONTOS
    //
    p.xy(2,0);
    p2.xy(2,0.1);
    printf("\nP_INTERSECAO|P IGUAIS: %d", p_intersecao.igual(p));

    //
    // Operators de pontos
    //
    printf("\nOperators de pontos\n");
    Ponto p3;
    p3.print();
    p3 = p2 - p2 - p2 + p2 + p;
    p3.print();

    //
    // RETANGULO
    //
    printf("\n\nRETANGULO\n");
    retangulo << Ponto(0,0) << Ponto(2,0) << Ponto(2,1) << Ponto(0,1);
    retangulo.print();
    printf("Area retangulo: %.2f\n", retangulo.area());
    printf(">>>>>Rotaciona:\n");
    retangulo.rotacionar(60);
    retangulo.print();
    printf("\n");

    //
    // TRIANGULO
    //
    printf("TRIANGULO\n");
    triangulo << Ponto(1,0) << Ponto(1,1) << Ponto(0,0);
    triangulo.print();
    printf("Area triangulo: %.2f\n\n", triangulo.area());

    //
    // RETRIANGULO
    //
    printf("RETANGULO + 2 TRIANGULOS\n");
    retriangulo << Ponto(0,0) << Ponto(2,0) << Ponto(2,2) << Ponto(1,1) << Ponto(0,2);
    retriangulo.print();
    printf("Area retriangulo: %.2f\n\n", retriangulo.area());


    //
    // SELF-INTERSECT
    //
    printf("\nFIGURA QUE SE CRUZA CONSIGO MESMA\n");
    self_intersect << Ponto(0,0) << Ponto(2,0) << Ponto(0,2) << Ponto(2,2);
    self_intersect.print();
    printf("Area self_intersect: %.2f", self_intersect.area());

    //
    // CLASSE RETANGULO
    //
    Retangulo rett(5,6,3,5);
    printf("\nClasse retangulo\n");
    rett.print();


    // Mostrando na tela um dos poligonos
     Mostrador(argc, argv, rett);

    return 0;
}

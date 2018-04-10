#include <iostream>
#include "headers/ponto.h"
#include "headers/linha.h"
#include "headers/poligono.h"

using namespace std;

int main(){
    Poligono retangulo, triangulo, retriangulo, self_intersect;
    Ponto p, p2, p_intersecao;
    char ret;
    p2.xy(0.5, 0.5);

    Linha l(p, p2);
    printf("Linha l: ");
    l.print();

    p2.xy(0.5,0);
    p.xy(0, 0.5);
    Linha l2(p, p2);
    printf("Linha l2: ");
    l2.print();

    p_intersecao.print();
    ret = intersecao(l ,l2, &p_intersecao);
    if (ret)
        p_intersecao.print();

    printf("\n\n");
    retangulo.adicionar_ponto(p);
    p.xy(2,0);
    retangulo.adicionar_ponto(p);
    p.xy(2,1);
    retangulo.adicionar_ponto(p);
    p.xy(0,1);
    retangulo.adicionar_ponto(p);
    retangulo.print();
    printf("Area retangulo: %.2f\n", retangulo.area());

    p.xy(1,0);
    triangulo.adicionar_ponto(p);
    p.xy(1,1);
    triangulo.adicionar_ponto(p);
    p.xy(0,0);
    triangulo.adicionar_ponto(p);
    triangulo.print();
    printf("Area triangulo: %.2f\n", triangulo.area());

    p.xy(0,0);
    retriangulo.adicionar_ponto(p);
    p.xy(2,0);
    retriangulo.adicionar_ponto(p);
    p.xy(2,2);
    retriangulo.adicionar_ponto(p);
    p.xy(1,1);
    retriangulo.adicionar_ponto(p);
    p.xy(0,2);
    retriangulo.adicionar_ponto(p);
    retriangulo.print();
    printf("Area retriangulo: %.2f\n", retriangulo.area());


    p.xy(0,0);
    self_intersect.adicionar_ponto(p);
    p.xy(0,2);
    self_intersect.adicionar_ponto(p);
    p.xy(2,0);
    self_intersect.adicionar_ponto(p);
    p.xy(2,2);
    self_intersect.adicionar_ponto(p);
    self_intersect.print();
    printf("Area self_intersect: %.2f\n", self_intersect.area());
    return 0;
}

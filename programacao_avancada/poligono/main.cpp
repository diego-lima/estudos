#include <iostream>
#include "headers/ponto.h"
#include "headers/poligono.h"

using namespace std;

int main(){
    Poligono poli;
    Ponto p;
    poli.adicionar_ponto(p);
    p.xy(1,0);
    poli.adicionar_ponto(p);
    p.xy(1,2);
    poli.adicionar_ponto(p);
    p.xy(0,2);
    poli.adicionar_ponto(p);
    poli.print();
    printf("Pontos: %d\n", poli.quantidade_pontos());
    printf("Area: %.2f\n", poli.area());
    return 0;
}

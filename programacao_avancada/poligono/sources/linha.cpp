#include <iostream>
#include "headers/linha.h"

using namespace std;

Linha::Linha(){

}

Linha::Linha(Ponto p1, Ponto p2){
    pontos[0] = p1;
    pontos[1] = p2;
}

bool Linha::limitada_por(Ponto p){
    if (pontos[0].igual(p) || pontos[1].igual(p))
            return true;
    return false;
}

void Linha::print(void){
    pontos[0].print();
    printf("->");
    pontos[1].print();
    printf("\n");
}

char intersecao(Linha l1, Linha l2, Ponto *ponto){
    // IMPLEMENTAÇÃO ENCONTRADA EM
    // http://flassari.is/2008/11/line-line-intersection-in-cplusplus/

    // Store the values for fast access and easy
    // equations-to-code conversion
    float x1 = l1.pontos[0].x(), x2 = l1.pontos[1].x();
    float x3 = l2.pontos[0].x(), x4 = l2.pontos[1].x();

    float y1 = l1.pontos[0].y(), y2 = l1.pontos[1].y();
    float y3 = l2.pontos[0].y(), y4 = l2.pontos[1].y();

    float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    // If d is zero, there is no intersection
    if (d == 0) return 0;

    // Get the x and y
    float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
    float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
    float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

    // Check if the x and y coordinates are within both lines
    if ( x < min(x1, x2) || x > max(x1, x2) ||
    x < min(x3, x4) || x > max(x3, x4) ) return 0;
    if ( y < min(y1, y2) || y > max(y1, y2) ||
    y < min(y3, y4) || y > max(y3, y4) ) return 0;

    // Return the point of intersection
    Ponto ret(x,y);
    *ponto = ret;
    return 1;

}

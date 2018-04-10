#include <iostream>
#include <math.h>
#include "headers/ponto.h"

using namespace std;


Ponto::Ponto(){
    _x = 0;
    _y = 0;
}

Ponto::Ponto(float a, float b){
    _x = a;
    _y = b;
}

float Ponto::x(){
    return _x;
}

float Ponto::x(float a){
    _x = a;
    return _x;
}

float Ponto::y(){
    return _y;
}

float Ponto::y(float a){
    _y = a;
    return _y;
}

float Ponto::xy(float a, float b){
    _x = a;
    _y = b;
}

void Ponto::combinar(Ponto p){
    _x = _x + p.x();
    _y = _y + p.y();
}

float Ponto::norma(void){
    return sqrt(pow(_x,2) + pow(_y,2));
}

void Ponto::transladar(float a, float b){
    Ponto p(a,b);
    combinar(p); // Usando a própria função da classe
}

void Ponto::print(void){
    printf("(%.1f,%.1f)", _x, _y);
}

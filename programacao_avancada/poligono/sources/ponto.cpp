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

Ponto Ponto::add(Ponto p){
    p.transladar(_x, _y);
    return p;
}

Ponto Ponto::sub(Ponto p){
    Ponto p_aux(_x, _y);
    p_aux.transladar(-1 * p.x(), -1 * p.y());
    return p_aux;
}

float Ponto::norma(void){
    return sqrt(pow(_x,2) + pow(_y,2));
}

void Ponto::transladar(float a, float b){
    _x = _x + a;
    _y = _y + b;
}

void Ponto::print(void){
    printf("(%.2f,%.2f)", _x, _y);
}

bool Ponto::igual(Ponto p){
    if (_x == p.x() && _y == p.y())
        return true;
    return false;
}

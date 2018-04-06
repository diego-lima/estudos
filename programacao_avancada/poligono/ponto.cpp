#include <iostream>
#include "ponto.h"

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

void Ponto::print(void){
    printf("(%.1f,%.1f)\n", _x, _y);
}

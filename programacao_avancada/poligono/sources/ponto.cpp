#include <iostream>
#include <math.h>
#include "headers/ponto.h"

using namespace std;

float grau(float radianos){
    // Converte de radianos pra graus
    return radianos * M_PI / 180;
}

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

void Ponto::x(float a){
    _x = a;
}

float Ponto::y(){
    return _y;
}

void Ponto::y(float a){
    _y = a;
}

void Ponto::xy(float a, float b){
    _x = a;
    _y = b;
}

Ponto Ponto::add(Ponto p){
    Ponto ret(_x, _y);
    ret.transladar(p.x(), p.y());
    return ret;
}

Ponto Ponto::operator + (Ponto v){
  Ponto ret(_x, _y);
  ret = ret.add(v);
  return(ret);
}

Ponto Ponto::sub(Ponto p){
    Ponto p_aux(_x, _y);
    p_aux.transladar(-1 * p.x(), -1 * p.y());
    return p_aux;
}

Ponto Ponto::operator - (Ponto v){
  Ponto ret(_x, _y);
  ret = ret.sub(v);
  return(ret);
}

float Ponto::norma(void){
    return sqrt(pow(_x,2) + pow(_y,2));
}

void Ponto::transladar(float a, float b){
    _x = _x + a;
    _y = _y + b;
}

void Ponto::rotacionar(float teta){
    float novo_x, novo_y;
    novo_x = cos(grau(teta)) * _x - sin(grau(teta)) * _y;
    novo_y = sin(grau(teta)) * _x + cos(grau(teta)) * _y;
    xy(novo_x, novo_y);

}

void Ponto::print(void){
    printf("(%.1f,%.1f)", _x, _y);
}

bool Ponto::igual(Ponto p){
    if (_x == p.x() && _y == p.y())
        return true;
    return false;
}

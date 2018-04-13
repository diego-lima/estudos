#ifndef RETANGULO_H
#define RETANGULO_H

#include "headers/poligono.h"

class Retangulo : public Poligono{

    public:
        // Construtor padrão: cria retangulo 1x1 na origem
        Retangulo();

        // Construtor preferido
        Retangulo(float x, float y, float largura, float altura);
};

#endif // RETANGULO_H

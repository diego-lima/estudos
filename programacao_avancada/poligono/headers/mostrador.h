#ifndef MOSTRADOR_H
#define MOSTRADOR_H

#include "headers/poligono.h"

class Mostrador{
    public:
        Mostrador();

        // Recebe o poligono a ser mostrado através de um Area Chart do QT.
        Mostrador(int argc, char *argv[], Poligono poligono);

        // Enquadra o poligono perto da origem e ajusta o alcance do gráfico
        // para o desenho do polígono ficar grande
        void setar_limites (Poligono* poligono, float * a, float* b);
};

#endif // MOSTRADOR_H

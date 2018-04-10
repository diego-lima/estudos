#ifndef LINHA_H
#define LINHA_H

#include "headers/ponto.h"

class Linha{
    private:
        Ponto pontos[2];

    public:
        Linha();

        Linha(Ponto p1, Ponto p2);

        // Determina se a linha é limitada pelo ponto
        bool limitada_por(Ponto p);

        // Printa as coordenadas da linha
        void print(void);

        friend bool intersecao(Linha l1, Linha l2, Ponto *ponto);
};

// Determina o ponto de interseção entre duas linhas (segmentos de reta).
// Retorna 0 se não houver interseção.
bool intersecao(Linha l1, Linha l2, Ponto *ponto);

#endif // LINHA_H

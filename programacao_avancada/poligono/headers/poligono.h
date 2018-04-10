#include "headers/ponto.h"

#ifndef POLIGONO_H
#define POLIGONO_H

class Poligono{
    private:
        int qtd_pontos; // Indica ate onde percorrer array de pontos (similar ao '\0' da string)
        int qtd_pontos_maxima; // Indica limite superior a partir do qual rejeita-se pontos

    public:
        Ponto *pontos; // Array de pontos
        // Construtor padrão, que aloca 100 pontos
        Poligono();

        // Construtor que recebe quantidade de pontos do polígono para alocar
        Poligono(int n);

        // Destrutor da classe, que deleta [] os pontos
        ~Poligono();

        // Resgata a quantidade de pontos
        int quantidade_pontos(void);

        // Recebe um ponto para ser adicionado à lista de pontos.
        // Retorna true em caso de sucesso.
        bool adicionar_ponto(Ponto p);

        // Printa a sequência anti-horária de pontos
        void print(void);

        // Translada todos os pontos do poligono
        void transladar(float a, float b);

        // Retorna a area do poligono
        float area(void);




};

#endif // POLIGONO_H

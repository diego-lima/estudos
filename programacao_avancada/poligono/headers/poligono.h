#ifndef POLIGONO_H
#define POLIGONO_H

#include "headers/ponto.h"
#include "headers/linha.h"

class Poligono{
    private:
        int qtd_pontos; // Indica ate onde percorrer array de pontos (similar ao '\0' da string)
        int qtd_pontos_maxima; // Indica limite superior a partir do qual rejeita-se pontos
        Ponto *pontos; // Array de pontos

    public:
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

        // Printa a sequência de pontos
        void print(void);

        // Translada todos os pontos do polígono
        void transladar(float a, float b);

        // Rotaciona todos os pontos do polígono em relação à origem (sentido anti-horário)
        void rotacionar(float teta);

        // Extra: Em caso de polígonos que se cruzam em si mesmos, a função recursivamente
        // calcula as áreas de cada subpolígono.
        // Retorna a área do poligono total.
        // Polígonos com menos de 3 pontos não têm área.
        float area(void);

        // Extra: determina se um ponto é um dos que formam o poligono
        bool contem_ponto(Ponto p);

        // Extra: determina se o poligono se intercepta consigo mesmo
        // Retorna o indice da primeira linha a se interceptar com outra
        // Retorna também o primeiro ponto de interseção encontrado
        // Retorna -1 caso nao exista interseção entre linhas
        int self_intersect(Ponto *p);

        // Extra: liberar acesso para classe que mostra polígono na tela
        friend class Mostrador;

};

#endif // POLIGONO_H

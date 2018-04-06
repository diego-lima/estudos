#ifndef PONTO_H
#define PONTO_H


class Ponto{
    private:
        float _x;
        float _y;

    public:
        // Construtor padrão
        Ponto();

        // Construtor com coordenadas
        Ponto(float a, float b);

        // Getter da propriedade _x
        float x();

        // Setter da propriedade _x
        float x(float a);

        // Getter da propriedade _y
        float y();

        // Setter da propriedade _y
        float y(float a);

        //Printa as coordenadas do ponto e quebra linha
        void print(void);

};

#endif // PONTO_H

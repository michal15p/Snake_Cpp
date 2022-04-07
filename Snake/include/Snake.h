#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
    public:
        Snake();
        void stworzMape();
        int los();
        void gra();
        virtual ~Snake();

    protected:

    private:
        char **mapa;
};

#endif // SNAKE_H

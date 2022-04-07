#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "Snake.h"

struct wsp
{
    int x;
    int y;
};

Snake::Snake()
{
    mapa = new char *[20];
    for(int i=0;i<20;i++)
    {
        mapa[i]=new char[20];
    }
}

void Snake::stworzMape()
{
    srand( time( NULL ) );
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            mapa[i][j]='.';
        }
    }
    mapa[0][0] = 'O';
}
int Snake::los()
{
    int los =( std::rand() % 20 );
    return los;
}
void Snake::gra()
{
    int wynik = 0;
    wsp w;
    w.x = 0;
    w.y = 0;
    std::vector <wsp> wezyk;
    bool trwa = true;
    char wybor=68;
    int los1 = los();
    int los2 = los();
    mapa[los1][los2] = 'O';
    wezyk.push_back(w);
    wezyk.push_back(w);
    while(trwa)
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                std::cout << mapa[i][j];
            }
            std::cout << std::endl;
        }
        if(kbhit())
        {
            wybor = getch();
        }
        _sleep(100);

        if(wybor==83 || wybor==115)// 83 - S
        {
            if(wynik>0)
            {
                //mapa[w.x][w.y] = '|';
                w.x++;
                if(w.x>19) w.x=0;
                for(int i=0; i<wezyk.size();i++)
                {
                    if(mapa[wezyk[i].x][wezyk[i].y] != 'O') mapa[wezyk[i].x][wezyk[i].y] = 'O';

                }
                mapa[wezyk[0].x][wezyk[0].y] = '.';
            }
            else
            {
                mapa[w.x][w.y] = '.';
                w.x++;
                if(w.x>19) w.x=0;
                mapa[w.x][w.y] = 'O';
            }
            system("cls");
            //wybor = 0;

        }
        else if(wybor==87 || wybor==119)//87 - W
        {
            if(wynik>0)
            {
                //mapa[w.x][w.y] = '|';
                w.x--;
                if(w.x<0) w.x=19;
                for(int i=0; i<wezyk.size();i++)
                {
                    if(mapa[wezyk[i].x][wezyk[i].y] != 'O') mapa[wezyk[i].x][wezyk[i].y] = 'O';
                }
                mapa[wezyk[0].x][wezyk[0].y] = '.';
            }
            else
            {
                mapa[w.x][w.y] = '.';
                w.x--;
                if(w.x<0) w.x=19;
                mapa[w.x][w.y] = 'O';
            }
            system("cls");
            //wybor = 0;
        }
        else if(wybor==65 || wybor==97)//A
        {
            if(wynik>0)
            {
                //mapa[w.x][w.y] = '|';
                w.y--;
                if(w.y<0) w.y=19;
                for(int i=0; i<wezyk.size();i++)
                {
                    if(mapa[wezyk[i].x][wezyk[i].y] != 'O') mapa[wezyk[i].x][wezyk[i].y] = 'O';
                }
                mapa[wezyk[0].x][wezyk[0].y] = '.';
            }
            else
            {
                mapa[w.x][w.y] = '.';
                w.y--;
                if(w.y<0) w.y=19;
                mapa[w.x][w.y] = 'O';
            }
            system("cls");
            //wybor = 0;
        }
        else if(wybor==68 || wybor==100)//D
        {
            if(wynik>0)
            {
                //mapa[w.x][w.y] = '|';
                w.y++;
                if(w.y>19) w.y=0;
                for(int i=0; i<wezyk.size();i++)
                {
                    if(mapa[wezyk[i].x][wezyk[i].y] != 'O') mapa[wezyk[i].x][wezyk[i].y] = 'O';
                }
                mapa[wezyk[0].x][wezyk[0].y] = '.';
            }
            else
            {
                mapa[w.x][w.y] = '.';
                w.y++;
                if(w.y>19) w.y=0;
                mapa[w.x][w.y] = 'O';
            }

            system("cls");
            //wybor = 0;
        }
        if(w.x==los1 && w.y==los2)
        {
            wynik++;
            wezyk.push_back(w);
            los1 = los();
            los2 = los();
            mapa[los1][los2] = 'O';
        }
        wezyk.erase(wezyk.begin());
        wezyk.push_back(w);
        for(int i=2; i<wezyk.size();i++)
        {
            //std::cout << wezyk[i].x << "|" << wezyk[i].y << std::endl;
            if(wezyk[0].x==wezyk[i].x && wezyk[0].y==wezyk[i].y)
            {
                trwa = false;
            }
        }

    }
    std::cout << std::endl << "Koniec gry z wynikiem: " << wynik << std::endl;

}


Snake::~Snake()
{
    //dtor
}

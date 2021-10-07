//
// Created by luax2 on 05/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "Gato.h"

struct GameState
{
    char currentPlayer;
    char board[3][3];
    char tableroLeno;
};

void displayBoard(struct GameState *g)
{
    printf("---- Gato de Val ----\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("[%c]",g->board[i][j]);
        printf("\n");
    }
}

Game* newGame()
{
    Game *g = malloc(sizeof(Game));
    g->currentPlayer='o';
    g->tableroLeno='F';
    int counter=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            g->board[i][j]='0'+counter++;

    return g;

}

char getWinner(struct GameState *g)
{
    //revisamos filas
    for(int i=0;i<3;i++)
    {
        if(g->board[i][0]==g->currentPlayer &&
           g->board[i][1]==g->currentPlayer &&
           g->board[i][2]==g->currentPlayer)
        return g->currentPlayer;
    }

    //revisamos columnas
    for(int i=0;i<3;i++)
    {
        if(g->board[0][i]==g->currentPlayer &&
           g->board[1][i]==g->currentPlayer &&
           g->board[2][i]==g->currentPlayer)
            return g->currentPlayer;
    }
    //revisar diagonales
    //esta es la diagonal que empieza en el 0,0, izquierda
    if(g->board[0][0]==g->currentPlayer &&
       g->board[1][1]==g->currentPlayer &&
       g->board[2][2]==g->currentPlayer)
        return g->currentPlayer;


    //esta es la que empieza en ll 0,2 , derecha
    if(g->board[0][2]==g->currentPlayer &&
       g->board[1][1]==g->currentPlayer &&
       g->board[2][0]==g->currentPlayer)
        return g->currentPlayer;

    int vecesJugadas=0,counter=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(g->board[i][j]!='0'+counter++)
                vecesJugadas++;
        }
    if(vecesJugadas==9)
        return g->tableroLeno;



    //si no encuentra a alguien que gane entonces:
    return 0;

}

char getCurrentPlayer(Game *g)
{
    return g->currentPlayer;
}

void makeMove(Game *g, int place)
{
    //modficiamos el tablero tal que se pone una ficha del current player
    int row=place/3;
    int col=place%3;
    if(g->board[row][col]!='x'&& g->board[row][col]!='o')
        g->board[row][col]=g->currentPlayer;
    else
    {
        printf("Posicion no validaaaa, selecciona otra --> \n");
            if(g->currentPlayer=='o')
                g->currentPlayer='x';
            else
                g->currentPlayer='o';

    }
}

void switchPlayer(Game *g)
{
    if(g->currentPlayer=='o')
        g->currentPlayer='x';
    else
        g->currentPlayer='o';
}



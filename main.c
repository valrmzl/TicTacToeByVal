#include <stdio.h>
#include "Gato.h"
int bandera=0;
//la ventaja de la libreria es que asi capsulamos informacion
int main()
{
    while(bandera==0)
    {
        Game *juego=newGame();
        //mientras no se tenga un jugador ganador el juego va a estar corriendo
        while(!getWinner(juego))
        {
            displayBoard(juego);
            switchPlayer(juego);
            int place;
            printf("Es el turno del juagador: %c\n", getCurrentPlayer(juego));
            printf("Numero de coordenada donde quieres colocar tu ficha -->  \n");
            fscanf(stdin,"%d",&place);
            makeMove(juego,place);
        }
        if(getWinner(juego)!='F')
        {
            displayBoard(juego);
            printf("El ganador es: %c\n", getWinner(juego));
            bandera=1;
        }
        else
        {
            printf("Nadie gano, el tablero se lleno :(\n");
            printf("El juego se va a reinciar :) \n\n\n");
        }
    }
    return 0;
}

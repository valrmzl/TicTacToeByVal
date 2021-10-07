//
// Created by luax2 on 05/10/2021.
//

#ifndef GATO_GATO_H   //si no esta definido, lo define
#define GATO_GATO_H

typedef struct GameState Game;
void displayBoard(Game *g);

Game* newGame();

char getWinner(Game *g);
char getCurrentPlayer(Game *g);
void makeMove(Game *g, int place );
void switchPlayer(Game *g);
#endif //GATO_GATO_H

#ifndef TURN_H
#define TURN_H
#include "boardstate.h"
#include "displayboard.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <QGraphicsScene>


UserInput GUIFunction(BoardState *state, guiPiece *piecearray);

BoardState * easyMode(BoardState * game,QGraphicsScene *scene);

BoardState * computerTurn(BoardState * game, int difficulty, QGraphicsScene *scene);

void userOneMove(BoardState * game, UserInput & input, guiPiece * piecearray, QGraphicsScene *scene);

BoardState * userTurn(BoardState * game, guiPiece *piecearray, QGraphicsScene *scene);

#endif // TURN_H

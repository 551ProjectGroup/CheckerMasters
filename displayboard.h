#ifndef DISPLAYBOARD_H
#define DISPLAYBOARD_H
#include <QGraphicsScene>
#include <vector>
#include "boardstate.h"
#include "guipiece.h"
class DisplayBoard
{
public:
    DisplayBoard();
    guiPiece *makeScene(BoardState *currstate, QGraphicsScene *scene);
    void getStartGameScreen(QGraphicsScene *scene);
    void addBoardScene(QGraphicsScene *scene);
    void displayScene(BoardState *currstate, QGraphicsScene *scene);
};

#endif // DISPLAYBOARD_H

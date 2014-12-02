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
    void makeScene(BoardState *currstate, QGraphicsScene *scene, MainWindow * window);
    void getStartGameScreen(QGraphicsScene *scene);
    void addBoardScene(QGraphicsScene *scene);
};

#endif // DISPLAYBOARD_H

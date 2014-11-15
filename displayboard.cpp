#include "displayboard.h"
#include "piece.h"
#include <QtDebug>
#include <vector>

DisplayBoard::DisplayBoard()
{
}

guiPiece * DisplayBoard::makeScene(BoardState *currstate, QGraphicsScene *scene)
{
    addBoardScene(scene);
    guiPiece *g = new guiPiece[24];
    //std::vector< guiPiece > * g;
    int count=0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(!currstate->getPiece(i,j).getEmpty()) {
                Piece p = currstate->getPiece(i,j);
                guiPiece * gui = new guiPiece(i,j,p.getPieceColor());
                scene->addItem(gui);
                count++;
               // scene->addEllipse((i*100)+25,(j*100)+25,50,50);
            }
        }
    }
    return g;
}

void DisplayBoard::addBoardScene(QGraphicsScene *scene)
{
    QPen pen = QPen(Qt::black);
    QRectF rec = QRectF(QPointF(0,0),QPointF(800,800));   //This is the place where we paint the board and its pieces. I am still writing it.
    scene->addRect(rec,pen);
    for (int i=1;i<8;i++) {
        scene->addLine(i*100,0,i*100,800);
   }

    for(int j=1;j<8;j++) {
        scene->addLine(0,j*100,800,j*100);
    }
}

void DisplayBoard::displayScene(BoardState *currstate, QGraphicsScene *scene)
{
    addBoardScene(scene);
    int count=0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(!currstate->getPiece(i,j).getEmpty()) {
                guiPiece g(i,j,currstate->getPiece(i,j).getPieceColor());
                scene->addItem(&g);
                count++;
               // scene->addEllipse((i*100)+25,(j*100)+25,50,50);
            }
        }
    }

}

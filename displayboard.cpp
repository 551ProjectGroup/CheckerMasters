#include "displayboard.h"
#include "piece.h"
#include <QtDebug>
#include <vector>

DisplayBoard::DisplayBoard()
{
}

void DisplayBoard::makeScene(BoardState *currstate, QGraphicsScene *scene, MainWindow *w)
{
    addBoardScene(scene);
    int count=0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(!currstate->getPiece(i,j).getEmpty()) {
                guiPiece *g = new guiPiece(currstate->getPiece(i,j).getType(),i,j,currstate->getPiece(i,j).getPieceColor(),currstate,w);
                scene->addItem(g);
                count++;
            }
        }
    }
}

void DisplayBoard::addBoardScene(QGraphicsScene *scene)
{
    QPen pen = QPen(Qt::black);
    QColor colorOdd = QColor(139,69,19);
    QColor colorEven = QColor(238,197,145);
    QBrush brushEven = QBrush(colorEven,Qt::SolidPattern);
    QBrush brushOdd = QBrush(colorOdd,Qt::SolidPattern);
    QRectF rec = QRectF(QPointF(0,0),QPointF(640,640));   //This is the place where we paint the board and its pieces. I am still writing it.
    scene->addRect(rec,pen);
    for (int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
             if(i%2==0 && j%2==0) {

        scene->addRect((i*80),(j*80),80,80,pen,brushEven);

             }
             else if(i%2==0 && j%2!=0){
                 scene->addRect((i*80),(j*80),80,80,pen,brushOdd);
             }
        }
   }
    for (int i=1;i<8;i=i+2) {
        for(int j=0;j<8;j++) {
             if(j%2!=0) {
        scene->addRect((i*80),(j*80),80,80,pen,brushEven);
             }
             else{
                 scene->addRect((i*80),(j*80),80,80,pen,brushOdd);
             }
        }
   }

}

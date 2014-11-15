#ifndef GUIPIECE_H
#define GUIPIECE_H
#include <QPainter>
#include <QGraphicsItem>
#include "userinput.h"

class guiPiece : public QGraphicsItem  {
private:
    bool moved;
    bool Pressed;
    int boardX;
    int boardY;
    int piececolor;
    UserInput uin;
public:
    guiPiece(int x,int y, int c): boardX(x),boardY(y),piececolor(c),moved(false) {
        setFlags(ItemIsMovable);
    }
    guiPiece(const guiPiece &rhs) {
        moved = rhs.moved;
        Pressed = rhs.Pressed;
        boardX = rhs.boardX;
        boardY = rhs.boardY;
        piececolor = rhs.piececolor;
        uin = rhs.uin;
    }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    guiPiece();
    int getBoardX() const;
    void setBoardX(int value);
    int getBoardY() const;
    void setBoardY(int value);
    int getPiececolor() const;
    void setPiececolor(int value);

   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
   bool getMoved() const;
   void setMoved(bool value);
   UserInput getUin() const;
   void setUin(const UserInput &value);
};

#endif // GUIPIECE_H

#include "guipiece.h"
#include "piece.h"
#include <QGraphicsSceneMouseEvent>
#include "userinput.h"
#include "turn.h"


int guiPiece::getBoardX() const
{
    return boardX;
}

void guiPiece::setBoardX(int value)
{
    boardX = value;
}

int guiPiece::getBoardY() const
{
    return boardY;
}

void guiPiece::setBoardY(int value)
{
    boardY = value;
}

int guiPiece::getPiececolor() const
{
    return piececolor;
}

void guiPiece::setPiececolor(int value)
{
    piececolor = value;
}

void guiPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        Pressed = true;
        update();
        QPointF point = event->scenePos();
        uin.setCurrentPosition(point);
        QGraphicsItem::mousePressEvent(event);
}

void guiPiece::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QPointF point = event->scenePos();
    uin.setNextPosition(point);
    QGraphicsItem::mouseReleaseEvent(event);
}

bool guiPiece::getMoved() const
{
    return moved;
}

void guiPiece::setMoved(bool value)
{
    moved = value;
}

UserInput guiPiece::getUin() const
{
    return uin;
}

void guiPiece::setUin(const UserInput &value)
{
    uin = value;
}
QRectF guiPiece::boundingRect() const
{
    return QRectF(((getBoardX()*100)+25),((getBoardY()*100)+25),50,50);
}

void guiPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec=boundingRect();
    QBrush brushRed(Qt::red);
    QBrush brushBlack(Qt::black);

    if(getPiececolor()) {
    painter->setBrush(brushRed);
    painter->drawEllipse(rec);
    }
    else {
        painter->setBrush(brushBlack);
        painter->drawEllipse(rec);
    }
}

guiPiece::guiPiece()
{
    setFlags(ItemIsMovable);
}

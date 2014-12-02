#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QRadialGradient>
#include <QSoundEffect>
#include "guipiece.h"
#include "piece.h"
#include "userinput.h"
#include "turn.h"
#include <QDir>


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
    QDir dir(QCoreApplication::applicationDirPath());
    QSoundEffect *wls = new QSoundEffect;
    tick = new QSoundEffect;
    tick->setSource(QUrl::fromLocalFile(dir.absolutePath() + "/tick.wav"));
    tick->setVolume(0.25);
    tick->play();
    Pressed = false;
    update();
    QPointF point = event->scenePos();
    uin.setNextPosition(point);
    QGraphicsItem::mouseReleaseEvent(event);
    bool userWin = false;
    bool compWin = false;
    if(trueState->getTurn() == 0){
       trueState = userTurn(trueState, uin);
       userWin = trueState->winLoss();
       if (userWin == true){
           window->updateGame(trueState);
           wls->setSource(QUrl::fromLocalFile(dir.absolutePath() + "/victory.wav"));
           wls->setVolume(0.25f);
           wls->play();
           QMessageBox::information(NULL,"CheckersMaster","You Won the Game!");
           trueState->emptyBoard();
       }
       window->updateGame(trueState);
    }
    if(trueState->getTurn() == 1 && userWin == false){
        trueState = computerTurn(trueState, window->getDifficulty());
        compWin = trueState->winLoss();
        if (compWin == true){
            window->updateGame(trueState);
            wls->setSource(QUrl::fromLocalFile(dir.absolutePath() + "/defeat.wav"));
            wls->setVolume(0.25f);
            wls->play();
            QMessageBox::information(NULL,"CheckersMaster","You Lost the Game");
            trueState->emptyBoard();
        }
    }

    window->updateGame(trueState);
    window->userlcd(trueState);
    window->complcd(trueState);
    window->movelcd(trueState);
    if (userWin == true || compWin==true){
        delete trueState;
    }

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

int guiPiece::getType() const
{
    return type;
}

void guiPiece::setType(int value)
{
    type = value;
}
QRectF guiPiece::boundingRect() const
{
    return QRectF(((getBoardX()*80)+20),((getBoardY()*80)+20),40,40);
}

void guiPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QStyleOptionGraphicsItem * errorFree = option;
    QWidget * errorFree2 = widget;
    option = errorFree;
    widget = errorFree2;
    QColor crimson = QColor(176,23,31);
    QRectF rec=boundingRect();
    QDir dir(QCoreApplication::applicationDirPath());
    QPixmap king = QPixmap(dir.absolutePath() + "/crown.png");
    QRadialGradient gradRed(getBoardX()*80+40,getBoardY()*80+40,30);
    QRadialGradient gradBlack(getBoardX()*80+40,getBoardY()*80+40,30);

    gradRed.setColorAt(0.0,crimson);
    gradRed.setColorAt(0.6,Qt::red);
    gradRed.setColorAt(0.8,Qt::white);


    gradBlack.setColorAt(0.0,Qt::black);
    gradBlack.setColorAt(0.7,Qt::gray);
    gradBlack.setColorAt(0.8,Qt::white);
    if(getPiececolor() && !getType()) {
    painter->setBrush(gradRed);
    painter->drawEllipse(rec);
    }
    else if(!getPiececolor() && !getType()){
        painter->setBrush(gradBlack);
        painter->drawEllipse(rec);
    }
    else if(getPiececolor() && getType()) {
        painter->setBrush(gradRed);
        painter->drawEllipse(rec);
        painter->drawPixmap(getBoardX()*80+25,getBoardY()*80+25,30,30,king);
    }
    else if(!getPiececolor() && getType()) {
        painter->setBrush(gradBlack);
        painter->drawEllipse(rec);
        painter->drawPixmap(getBoardX()*80+25,getBoardY()*80+25,30,30,king);
    }
}

guiPiece::guiPiece()
{
    setFlags(ItemIsMovable);
}

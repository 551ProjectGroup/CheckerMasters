#include "userinput.h"

QPointF UserInput::getCurrentPosition() const
{
    return currentPosition;
}

void UserInput::setCurrentPosition(const QPointF &value)
{
    currentPosition = value;
}

QPointF UserInput::getNextPosition() const
{
    return nextPosition;
}

void UserInput::setNextPosition(const QPointF &value)
{
    nextPosition = value;
}

int UserInput::computePixelToBoard(int x)
{
    for(int i=1;i<9;i++) {
        if(x >=(i*100) && x<=((i+1)*100)) {
            return i-1;
        }
    }
    return -1;
}

int UserInput::convertnxtX()
{
    return computePixelToBoard(getNextPosition().rx());
}

int UserInput::convertcurX()
{
    return computePixelToBoard(getCurrentPosition().rx());
}

int UserInput::convertcurY()
{
    return computePixelToBoard(getCurrentPosition().ry());
}

int UserInput::convertnxtY()
{
    return computePixelToBoard(getNextPosition().ry());
}

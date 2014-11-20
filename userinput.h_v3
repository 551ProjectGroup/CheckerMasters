#ifndef USERINPUT_H
#define USERINPUT_H
#include "struct.h"
#include <QtCore>
#include <vector>

class UserInput
{
private:
    int interType;
    QPointF currentPosition;
    QPointF nextPosition;
    Coor current;
    Coor next;

public:
    UserInput(){
      interType = 0;
      current.x = 0;
      current.y = 0;
      next.x = 0;
      next.y = 0;
    }
    UserInput(int i, Coor c, Coor n): interType(i), current(c), next(n){}
    QPointF getCurrentPosition() const;
    void setCurrentPosition(const QPointF &value);
    QPointF getNextPosition() const;
    void setNextPosition(const QPointF &value);
    int convertcurX();
    int convertcurY();
    int convertnxtX();
    int convertnxtY();
    int computePixelToBoard(int x);

    UserInput(const UserInput & rhs){
      interType = rhs.interType;
      current.x = rhs.current.x;
      current.y = rhs.current.y;
      next.x = rhs.next.x;
      next.y = rhs.next.y;
      currentPosition = rhs.currentPosition;
      nextPosition = rhs.nextPosition;
    }
    UserInput & operator=(const UserInput & rhs){
      if (this != &rhs){
        interType = rhs.interType;
        current.x = rhs.current.x;
        current.y = rhs.current.y;
        next.x = rhs.next.x;
        next.y = rhs.next.y;
      }
      return *this;
    }

    int getType(){ return interType;}
    Coor getCurrent(){ return current;}
    Coor getNext(){ return next;}
};


struct _allMoves{
  std::vector< UserInput > jumpArray;
  int jArrNum;
  std::vector< UserInput > regArray;
  int rArrNum;
};
typedef struct _allMoves allMoves;

struct _jumpCompare{
    std::vector <UserInput> jumpOrder;
    int jOrderSize;
    int value;
    _jumpCompare & operator =(_jumpCompare & rhs){
        if (this != &rhs){
            jumpOrder = rhs.jumpOrder;
            jOrderSize = rhs.jOrderSize;
            value = rhs.value;
        }
        return *this;
    }
};
typedef struct _jumpCompare jumpCompare;

#endif // USERINPUT_H

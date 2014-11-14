#ifndef __BOARDSTATE_H__
#define __BOARDSTATE_H__
#include <vector>

struct _Coor{
  int x;
  int y;  
};
typedef struct _Coor Coor;

class UserInput{
 private:
  int interType;
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
  UserInput(const UserInput & rhs){
    interType = rhs.interType;
    current.x = rhs.current.x;
    current.y = rhs.current.y;
    next.x = rhs.next.x;
    next.y = rhs.next.y;
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

class Piece{
 private:
  int empty; //empty -> 1 ignore all fields
  int pieceColor; //1 -> red, 0 -> black, 2-> not valid bc piece is empty
  int type; //0 -> normal, 1 -> king
  int upgrade; //1 -> yes, 0 -> no
  int state; //0 -> dead, 1-> alive
 public:
 Piece(): empty(1), pieceColor(2), type(0), upgrade(0), state(1){} 
 Piece(int c): empty(0), pieceColor(c), type(0), upgrade(0), state(1){}
 Piece(int c, int t, int u): empty(0), pieceColor(c), type(t), upgrade(u), state(1){}
  Piece(Piece & rhs){
    empty = rhs.empty;
    pieceColor = rhs.pieceColor;
    type = rhs.type;
    upgrade = rhs.upgrade;
    state = rhs.state;
  }
  Piece & operator=(Piece & rhs){
   if (this != &rhs){
     empty = rhs.empty;
     pieceColor = rhs.pieceColor;
     type = rhs.type;
     upgrade = rhs.upgrade;
     state = rhs.state;
   }
   return *this;
 }
 int getPieceColor(){ 
   if (empty == 0){
     return pieceColor;
   }
   return 2;
 }
 int getType(){ return type;}
 int getUpgrade(){ return upgrade;}
 int getEmpty(){ return empty;}
};

class BoardState{
 private:
  Piece board[8][8];
  int userColor; // 1-> red, 0 -> black
  int compColor; 
  int turn; //0 <- user, 1 <- computer
 public:
  BoardState(int color);
  bool checkLegality(UserInput & input);
  bool checkLegalJump(UserInput & input);
  bool checkNoJumps(UserInput & Input);
  bool checkRegMove(UserInput & Input);
  int getTurn();
  void updateBoard(UserInput & input);
  bool checkFurther(UserInput & input);
  Piece getPiece(int x, int y);
  void changeTurn();
  void comPossibleMoves(allMoves * comp);
  UserInput * comMoreMove(Coor start);
};

class Menu{
 private:
  int settings;

};

class NewGame : public Menu{
 private:
  int difficulty;
  int color; 
 public:
  NewGame(): difficulty(0), color(0) {}
  NewGame(int d, int c): difficulty(d), color(c) {}
  int getColor(void){
    return color;
  }
};

#endif

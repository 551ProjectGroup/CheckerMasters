#ifndef __BOARDSTATE_H__
#define __BOARDSTATE_H__

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
  UserInput(UserInput & rhs){
    interType = rhs.interType;
    current.x = rhs.current.x;
    current.y = rhs.current.y;
    next.x = rhs.next.x;
    next.y = rhs.next.y;
  }
  UserInput & operator=(UserInput & rhs){
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

class Piece{
 private:
  int empty; //empty -> 1 ignore all fields
  int pieceColor; //1 -> red, 0 -> black
  int type; //0 -> normal, 1 -> king
  int upgrade; //1 -> yes, 0 -> no
  int state; //0 -> dead, 1-> alive
 public:
 Piece(): empty(1), pieceColor(0), type(0), upgrade(0), state(1){} 
 Piece(int c): empty(0), pieceColor(c), type(0), upgrade(0), state(1){}
 Piece(int c, int t, int u): empty(0), pieceColor(c), type(t), upgrade(u), state(1){}
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
 int getPieceColor(){ return pieceColor;}
 int getType(){ return type;}
 int getUpgrade(){ return upgrade;}
 int getEmpty(){ return empty;}
};

class BoardState{
 private:
  Piece board[8][8];
  int userColor; // 1-> red, 0 -> black
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

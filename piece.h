#ifndef PIECE_H
#define PIECE_H
#include "userinput.h"

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
 ~Piece(){}
 Piece(const Piece & rhs){
    empty = rhs.empty;
    pieceColor = rhs.pieceColor;
    type = rhs.type;
    upgrade = rhs.upgrade;
    state = rhs.state;
  }
  Piece & operator=(const Piece & rhs){
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

#endif //PIECE_H

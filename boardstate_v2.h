#ifndef BOARDSTATE_H
#define BOARDSTATE_H
#include "userinput.h"
#include "piece.h"
#include "struct.h"



class BoardState{
 private:
  Piece board[8][8];
  int userColor; // 1-> red, 0 -> black
  int compColor;
  int turn; //0 <- user, 1 <- computer
 public:
  BoardState(int color);
  bool checkLegality(UserInput& input);
  bool checkLegalJump(UserInput & input);
  bool checkNoJumps(UserInput & input);
  bool checkRegMove(UserInput & input);
  int getTurn();
  void updateBoard(UserInput & input);
  bool checkFurther(UserInput & input);
  Piece getPiece(int x, int y);
  void changeTurn();
  void comPossibleMoves(allMoves * comp);
  UserInput * comMoreMove(Coor start);
};

#endif // BOARDSTATE_H

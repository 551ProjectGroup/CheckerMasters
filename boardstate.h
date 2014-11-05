#ifndef __BOARDSTATE_H__
#define __BOARDSTATE_H__

class Piece{
 private:
  int empty; //empty -> 1 ignore all fields
  int color; //1 -> red, 0 -> black
  int type; //0 -> normal, 1 -> king
  int upgrade; //1 -> yes, 0 -> no
  int state; //0 -> dead, 1-> alive
 public:
 Piece(): empty(1), color(0), type(0), upgrade(0), state(0){} 
};

class BoardState{
 private:
  Piece board[8][8];
  int turn; //0 <- user, 1 <- computer
 public:
  BoardState(int color){
    turn = color;
    for(int i = 0; i < 8; i=i+2){
      for(int j = 0; j < 8; j=j+2){
	board[i][j] = Piece();
      }
    }
    for(int i = 1; i < 8; i=i+2){
      for(int j = 1; j < 8; j=j+2){
	board[i][j] = Piece();
      }
    } 
    for (int j = 0; j < 8; j=j+2){
      board[3][j] = Piece();
    }
    for (int j = 1; j < 8; j=j+2){
      board[4][j] = Piece();
    }
  }
  //This is where we stopped
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

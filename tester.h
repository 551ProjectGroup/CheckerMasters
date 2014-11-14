#ifndef __TESTER_H__
#define __TESTER_H__
#include <iostream>
#include <stdio.h>
#include "boardstate.h"

int mainMenu(){ return 0;}
int difficultyMenu(){ return 0;}
int colorMenu(){ return 0;}

void GUIShow(BoardState * game){
  std::cout << "   0 1 2 3 4 5 6 7 " <<std::endl;
  for (int i = 0; i < 8; i++){
    std::cout << "  -----------------" <<std::endl;
    std::cout << i << ":";
    for (int j = 0; j<8; j++){
      std::cout << "|";
      if (game->getPiece(j,i).getEmpty() == 1){
	std::cout << " ";
      }
      else{
	if (game->getPiece(j,i).getPieceColor() == 0 && game->getPiece(j,i).getType() == 0){
	  std::cout << "b";
	}
	if (game->getPiece(j,i).getPieceColor() == 0 && game->getPiece(j,i).getType() == 1){
	  std::cout << "B";
	}
	if (game->getPiece(j,i).getPieceColor() == 1 && game->getPiece(j,i).getType() == 0){
	  std::cout << "r";
	}
	if (game->getPiece(j,i).getPieceColor() == 1 && game->getPiece(j,i).getType() == 1){
	  std::cout << "R";
	}
      }
    }
    std::cout << "|" << std::endl;
  }
  std::cout << "  -----------------" <<std::endl;
}

UserInput & GUIFunction(BoardState * game){
  GUIShow(game);
  std::cout << "Enter User Turn (cX, cY, nX, nY) (i.e 0 0 1 1)" << std::endl;
  char * line;
  size_t bytes = 0;
  getline(&line, &bytes, stdin);
  Coor c;
  c.x = line[0] - '0';
  c.y = line[2] - '0';
  Coor n;
  n.x = line[4] - '0';
  n.y = line[6] - '0';
  free(line);
  UserInput * user = new UserInput(0, c, n);
  return *user;
}

/*BoardState * computerTurn(BoardState * gameBoard){
  GUIShow(gameBoard);
  std::cout << "Enter Computer Turn (cX, cY, nX, nY) (i.e 0 0 1 1)" << std::endl;
  char * line;
  size_t bytes = 0;
  getline(&line, &bytes, stdin);
  Coor c;
  c.x = line[0] - '0';
  c.y = line[2] - '0';
  Coor n;
  n.x = line[4] - '0';
  n.y = line[6] - '0';
  UserInput computer(0, c, n);
  free(line);
  gameBoard->updateBoard(computer);
  gameBoard->changeTurn();
  return gameBoard;
}
*/
#endif

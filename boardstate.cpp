#include <iostream>
#include <cstdlib>
#include <vector>
#include "boardstate.h"

void BoardState::changeTurn(void){
  if (turn == 1){
    turn = 0;
  }
  else{
    turn = 1;
  }
}

Piece BoardState::getPiece(int x, int y){
  return board[x][y];
}

bool BoardState::checkLegalJump(UserInput & input){
  int nY = input.getNext().y;
  int nX = input.getNext().x;
  int cY = input.getCurrent().y;
  int cX = input.getCurrent().x;
  if ((cY - nY == 2) || (cY - nY == -2)){  
    if ((cX - nX == 2) || (cX - nX == -2)){
      if (board[cX][cY].getType() == 1){
	if (board[nX][nY].getEmpty() != 1){
	  return false;
	} 
	if (board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)].getPieceColor() == compColor){
	  return true;
	}
	else{
	  return false;
	}
      }
      else{ //check normal piece
	if (nY - cY == 2){  
	  return false; //if going backwards
	}
	else{ 
	  if (board[nX][nY].getEmpty() != 1){
	    return false;
	  } 
	  if (board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)].getPieceColor() == compColor){
	    return true;
	  }
	  else{
	    return false;
	  }
	}
      }
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}
bool BoardState::checkNoJumps(UserInput & Input){
  for(int i = 0; i < 8; i++){
    for(int j =0; j <8; j++){
      if (board[i][j].getPieceColor() == userColor && board[i][j].getEmpty() != 1){
	if (j>1){
	  if ( i > 1){
	    if (board[i-1][j-1].getPieceColor() == compColor && board[i-2][j-2].getEmpty() == 1){
	      return false;
	    }
	  }
	  if ( i < 6){
	    if (board[i+1][j-1].getPieceColor() == compColor && board[i+2][j-2].getEmpty() == 1){
	      return false;
	    }
	  }
	}
	if (j<6 && board[i][j].getType() == 1){
	  if ( i > 1){
	    if (board[i-1][j+1].getPieceColor() == compColor && board[i-2][j+2].getEmpty() == 1){
	      return false;
	    }
	  }
	  if ( i < 6){
	    if (board[i+1][j+1].getPieceColor() == compColor && board[i+2][j+2].getEmpty() == 1){
	      return false;
	    }
	  }
	}
      }
    }
  }
  return true;
}
bool BoardState::checkRegMove(UserInput & Input){
  int nY = Input.getNext().y;
  int nX = Input.getNext().x;
  int cY = Input.getCurrent().y;
  int cX = Input.getCurrent().x;
  if ((cY - nY == 1) || (cY - nY == -1)){  
    if ((cX - nX == 1) || (cX - nX == -1)){
      if (board[cX][cY].getType() == 1){
	if (board[nX][nY].getEmpty() != 1){
	  return false;
	}
	return true;
      }
      else{ //regular piece
	if (nY - cY == 1){ //going backward
	  return false; 
	}
	if (board[nX][nY].getEmpty() != 1){
	  return false;
	}
	return true;
      }
    }
  }
  return false;
}

bool BoardState::checkLegality(UserInput & input){
  if (board[input.getCurrent().x][input.getCurrent().y].getPieceColor() != userColor){
    return false;
  }
  //check jump
  bool jump = checkLegalJump(input);
  if (jump == true){
    return true;
  }
  else{
    bool regMove = checkRegMove(input);
    if (regMove == true){
      bool noJump = checkNoJumps(input);
      if (noJump == true){
	return true;
      }
      else{
	return false;
      }
    }
    else{
      return false;
    }
  }
}

int BoardState::getTurn(void){
  return turn;
}

BoardState::BoardState(int color){
  turn = color;
  userColor = color;
  if (color == 1){
    compColor = 0;
  }
  else{
    compColor = 1;
  }
  for(int i = 0; i < 8; i=i+2){
    for(int j = 0; j < 8; j=j+2){
      Piece * newPiece = new Piece();
      board[j][i] = *newPiece;
    }
  }
  for(int i = 1; i < 8; i=i+2){
    for(int j = 1; j < 8; j=j+2){
      Piece * newPiece = new Piece();
      board[j][i] = *newPiece;
    }
  } 
  for (int j = 0; j < 8; j=j+2){
    Piece * newPiece = new Piece();
    board[j][3] = *newPiece;
  }
  for (int j = 1; j < 8; j=j+2){
    Piece * newPiece = new Piece();
    board[j][4] = *newPiece;
  }
  for (int i = 5; i < 8; i = i+2){
    for (int j = 0; j < 8; j= j+2){
      Piece * userPiece = new Piece(color);
      board[j][i] = *userPiece;
    }
  }
  for(int j = 1; j< 8; j=j+2){
    Piece * userPiece = new Piece(color);
    board[j][6] = *userPiece;
  }
  for (int i = 0; i < 3; i = i+2){
    for (int j = 1; j < 8; j= j+2){
      Piece * computerPiece = new Piece(compColor);
      board[j][i] = *computerPiece;
    }
  }
  for(int j = 0; j< 8; j=j+2){
    Piece * computerPiece = new Piece(compColor);
    board[j][1] = *computerPiece;
  }
}

void BoardState::updateBoard(UserInput & input){
  int nY = input.getNext().y;
  int nX = input.getNext().x;
  int cY = input.getCurrent().y;
  int cX = input.getCurrent().x;
  if (board[cX][cY].getPieceColor() == userColor){
    if (nY == 0 && board[cX][cY].getType() != 1){
      Piece * update = new Piece(board[cX][cY].getPieceColor(), 1, 1);
      board[nX][nY] = *update;
      delete update;
    }
    else{
      board[nX][nY] = board[cX][cY];
    }
  }
  if (board[cX][cY].getPieceColor() == compColor){
    if (nY == 7 && board[cX][cY].getType() != 1){
      Piece * update = new Piece(board[cX][cY].getPieceColor(), 1, 1);
      board[nX][nY] = *update;
      delete update;
    }
    else{
      board[nX][nY] = board[cX][cY];
    }
  }
  //sets empty piece to old current square
  Piece * newPiece = new Piece();
  board[cX][cY] = *newPiece;
  delete newPiece;
  //deletes middle piece in a jump
  if (cX - nX == -2 || cX - nX == 2){
    Piece * deletePiece = new Piece();
    board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)] = *deletePiece;
    delete deletePiece;
  }
}

bool BoardState::checkFurther(UserInput & input){
  int nY = input.getNext().y;
  int nX = input.getNext().x;
  //int cY = input.getCurrent().y;
  int cX = input.getCurrent().x;
  int opponentColor;
  if (turn == 0){
    opponentColor = compColor;
  }
  else{
    opponentColor = userColor;
  }
  if (board[nX][nY].getUpgrade() == 1){
    Piece * update = new Piece(board[nX][nY].getPieceColor(), 1, 0);
    board[nX][nY] = *update;
    delete update;
    return false;
  }
  if (cX - nX == 1 || cX - nX == -1){
    return false;
  }
  if ((nY > 1 && board[nX][nY].getType() == 1) || (nY>1 && opponentColor == compColor)){
    if ( nX > 1){
      if (board[nX-1][nY-1].getPieceColor() == opponentColor && board[nX-2][nY-2].getEmpty() == 1){
	return true;
      }
    }
    if ( nX < 6){
      if (board[nX+1][nY-1].getPieceColor() == opponentColor && board[nX+2][nY-2].getEmpty() == 1){
	return true;
      }
    }
  }
  if ((nY <6 && board[nX][nY].getType() == 1) || (nY < 6 && opponentColor == userColor)){
    if ( nX > 1){
      if (board[nX-1][nY+1].getPieceColor() == opponentColor && board[nX-2][nY+2].getEmpty() == 1){
	return true;
      }
    }
    if ( nX < 6){
      if (board[nX+1][nY+1].getPieceColor() == opponentColor && board[nX+2][nY+2].getEmpty() == 1){
	return true;
      }
    }
  }
  return false;
}

UserInput * BoardState::comMoreMove(Coor start){
  std::vector<Coor> nextSquare;
  int size = 0;
  Coor current = start;
  Coor next;
  int j = current.x;
  int i = current.y;
  if (i < 6){
    if ( j > 1){
      if (board[j-1][i+1].getPieceColor() == userColor && board[j-2][i+2].getEmpty() == 1){
	next.x = j-2;
	next.y = i+2;
	nextSquare.push_back(next); 
	size++;
      }
    }
    if ( j < 6){
      if (board[j+1][i+1].getPieceColor() == userColor && board[j+2][i+2].getEmpty() == 1){
	next.x = j+2;
	next.y = i+2;
	nextSquare.push_back(next); 
	size++;
      }
    }
  }
  if (i > 1 && board[j][i].getType() == 1){
    if ( j > 1){
      if (board[j-1][i-1].getPieceColor() == userColor && board[j-2][i-2].getEmpty() == 1){
	next.x = j-2;
	next.y = i-2;
	nextSquare.push_back(next); 
	size++;
      }
    }
    if ( j < 6){
      if (board[j+1][i-1].getPieceColor() == userColor && board[j+2][i-2].getEmpty() == 1){
	next.x = j+2;
	next.y = i-2;
	nextSquare.push_back(next); 
	size++;
      }
    }
  }
  int randomMove = rand() % size;
  next = nextSquare[randomMove];
  UserInput * nextMove = new UserInput(0, current, next);
  return nextMove;
}

void BoardState::comPossibleMoves(allMoves * comp){
  for (int i = 0; i < 8; i++){
    for (int j = 0; j< 8; j++){
      if (board[j][i].getPieceColor() == compColor){
	Coor current;
	Coor next;
	current.x = j;
	current.y = i;
	if (i < 6){
	  if ( j > 1){
	    if (board[j-1][i+1].getPieceColor() == userColor && board[j-2][i+2].getEmpty() == 1){
	      next.x = j-2;
	      next.y = i+2;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->jumpArray).push_back(*newElement);
	      comp->jArrNum++;
	    }
	  }
	  if ( j < 6){
	    if (board[j+1][i+1].getPieceColor() == userColor && board[j+2][i+2].getEmpty() == 1){
	      next.x = j+2;
	      next.y = i+2;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->jumpArray).push_back(*newElement);
	      comp->jArrNum++; 
	    }
	  }
	}
	if (i > 1 && board[j][i].getType() == 1){
	  if ( j > 1){
	    if (board[j-1][i-1].getPieceColor() == userColor && board[j-2][i-2].getEmpty() == 1){
	      next.x = j-2;
	      next.y = i-2;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->jumpArray).push_back(*newElement); 
	      comp->jArrNum++;
	    }
	  }
	  if ( j < 6){
	    if (board[j+1][i-1].getPieceColor() == userColor && board[j+2][i-2].getEmpty() == 1){
	      next.x = j+2;
	      next.y = i-2;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->jumpArray).push_back(*newElement); 
	      comp->jArrNum++;
	    }
	  }
	}
	if (i < 7){ // moving to regular moves
	  if ( j > 0){
	    if (board[j-1][i+1].getEmpty() == 1){
	      next.x = j-1;
	      next.y = i+1;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->regArray).push_back(*newElement);
	      comp->rArrNum++;
	    }
	  }
	  if ( j < 7){
	    if (board[j+1][i+1].getEmpty() == 1){
	      next.x = j+1;
	      next.y = i+1;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->regArray).push_back(*newElement); 
	      comp->rArrNum++;
	    }
	  }
	}
	if (i > 0 && board[j][i].getType() == 1){
	  if ( j > 0){
	    if (board[j-1][i-1].getEmpty() == 1){
	      next.x = j-1;
	      next.y = i-1;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->regArray).push_back(*newElement);
	      comp->rArrNum++;
	    }
	  }
	  if ( j < 7){
	    if (board[j+1][i-1].getEmpty() == 1){
	      next.x = j+1;
	      next.y = i-1;
	      UserInput * newElement = new UserInput(0, current, next);
	      (comp->regArray).push_back(*newElement);
	      comp->rArrNum++;
	    }
	  }
	}
      }
    }
  }
}

#include "boardstate.h"
#include <iostream>

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
  int computerColor;
  if (userColor == 1){
    computerColor = 0;
  }
  else{
    computerColor = 1;
  }
  if ((cY - nY == 2) || (cY - nY == -2)){  
    if ((cX - nX == 2) || (cX - nX == -2)){
      if (board[cX][cY].getType() == 1){
	if (board[nX][nY].getEmpty() != 1){
	  return false;
	} 
	if (board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)].getPieceColor() == computerColor){
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
	  if (board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)].getPieceColor() == computerColor){
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
  int compColor;
  if (userColor == 1){
    compColor = 0;
  }
  else{
    compColor = 1;
  }
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
  int computerColor;
  if (color == 1){
    computerColor = 0;
  }
  else{
    computerColor = 1;
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
      Piece * computerPiece = new Piece(computerColor);
      board[j][i] = *computerPiece;
    }
  }
  for(int j = 0; j< 8; j=j+2){
    Piece * computerPiece = new Piece(computerColor);
    board[j][1] = *computerPiece;
  }
}

void BoardState::updateBoard(UserInput & input){
  int nY = input.getNext().y;
  int nX = input.getNext().x;
  int cY = input.getCurrent().y;
  int cX = input.getCurrent().x;
  if (nY == 0 && board[cX][cY].getType() != 1){
    Piece * update = new Piece(board[cX][cY].getPieceColor(), 1, 1);
    board[nX][nY] = *update;
    delete update;
  }
  else{
    board[nX][nY] = board[cX][cY];
  }
  Piece * newPiece = new Piece();
  board[cX][cY] = *newPiece;
  delete newPiece;
  if (cX - nX == -2 || cX - nX == 2){
    Piece * deletePiece = new Piece();
    board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)] = *deletePiece;
    delete deletePiece;
  }
}

bool BoardState::checkFurther(UserInput & input){
  int nY = input.getNext().y;
  int nX = input.getNext().x;
  int cY = input.getCurrent().y;
  int cX = input.getCurrent().x;
  int compColor;
  if (userColor == 1){
    compColor = 0;
  }
  else{
    compColor = 1;
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
  if (nY > 1){
    if ( nX > 1){
      if (board[nX-1][nY-1].getPieceColor() == compColor && board[nX-2][nY-2].getEmpty() == 1){
	return true;
      }
    }
    if ( nX < 6){
      if (board[nX+1][nY-1].getPieceColor() == compColor && board[nX+2][nY-2].getEmpty() == 1){
	return true;
      }
    }
  }
  if (nY <6 && board[cX][cY].getType() == 1){
    if ( nX > 1){
      if (board[nX-1][nY+1].getPieceColor() == compColor && board[nX-2][nY+2].getEmpty() == 1){
	return true;
      }
    }
    if ( nX < 6){
      if (board[nX+1][nY+1].getPieceColor() == compColor && board[nX+2][nY+2].getEmpty() == 1){
	return true;
      }
    }
  }
  return false;
}

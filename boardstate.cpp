#include <iostream>
#include <cstdlib>
#include <vector>
#include "boardstate.h"
#include <QMessageBox>
#include <string>
#include <fstream>

int * BoardState::loadBoard(){
    std::ifstream f("saved.txt");
    std::string line;
    int * returnValues = new int[4];
    for (int i = 0; i < 4; i++){
        returnValues[i] = 0;
    }
    if (!f){
        QMessageBox::information(NULL,"Invalid File","File does not exist!");
        returnValues[0] = 3;
        return returnValues;
    }
    for (int i = 0; i<8; i++){
        for (int j=0; j<8; j++){
            std::getline(f, line);
            if (line[0] == '1'){
                board[j][i] = Piece();
            }
            else{
                int color = line[1] - '0';
                int type = line[2] - '0';
                int upgrade = line[3] -'0';
                board[j][i] = Piece(color, type, upgrade);
            }
        }
    }
    std::getline(f, line);
    userColor = line[0] - '0';
    compColor = line[1] - '0';
    turn = line[2] - '0';
    startOfUserTurn = line[3] - '0';
    lastX = line[4] - '0';
    lastY = line[5] - '0';
    std::getline(f, line);
    moveCounter = strtol(line.c_str(), NULL, 10);
    std::getline(f, line);
    returnValues[0] = line[0] - '0';
    std::getline(f, line);
    returnValues[1] = line[0] - '0';
    std::getline(f, line);
    returnValues[2] = strtol(line.c_str(), NULL, 10);
    std::getline(f, line);
    returnValues[3] = strtol(line.c_str(), NULL, 10);
    std::getline(f, line);
    numUserPieces = strtol(line.c_str(), NULL, 10);
    std::getline(f, line);
    numCompPieces = strtol(line.c_str(), NULL, 10);
    f.close();
    return returnValues;
}

int BoardState::getUserPieces()
{
    return numUserPieces;
}

int BoardState::getCompPieces()
{
    return numCompPieces;
}

void BoardState::saveBoard(int difficulty, bool timerOn, int minutes, int seconds){
    FILE * f = fopen("saved.txt", "w");
    for (int i = 0; i<8; i++){
        for (int j=0; j<8; j++){
            fprintf(f, "%d%d%d%d\n", board[j][i].getEmpty(),board[j][i].getPieceColor(),board[j][i].getType(),board[j][i].getUpgrade() );
        }
    }
    fprintf(f, "%d%d%d%d%d%d\n",userColor,compColor,turn,startOfUserTurn,lastX,lastY);
    fprintf(f,"%d\n",moveCounter);
    fprintf(f, "%d\n",difficulty);
    fprintf(f, "%d\n", timerOn);
    fprintf(f, "%d\n", minutes);
    fprintf(f, "%d\n", seconds);
    fprintf(f, "%d\n", numUserPieces);
    fprintf(f, "%d\n", numCompPieces);
    fclose(f);
}

bool BoardState::endGameWin(){
    //first four instructions are for upper corner
    if (board[0][1].getEmpty()==1 && board[1][0].getType() == 1 && board[1][0].getPieceColor()==userColor && board[2][3].getPieceColor()==compColor && board[2][3].getType() ==1 && board[1][2].getType() == 1 && board[1][2].getPieceColor() == compColor){
        Coor cur;
        cur.x = 1;
        cur.y = 2;
        Coor nex;
        nex.x = 0;
        nex.y = 1;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[1][0].getEmpty()==1 && board[2][1].getType() == 1 && board[2][1].getPieceColor()==userColor && board[2][3].getPieceColor()==compColor && board[2][3].getType() ==1 && board[0][1].getType() == 1 && board[0][1].getPieceColor() == compColor){
        Coor cur;
        cur.x = 0;
        cur.y = 1;
        Coor nex;
        nex.x = 1;
        nex.y = 0;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[3][4].getEmpty()==1 && board[3][0].getType() == 1 && board[3][0].getPieceColor()==userColor && board[2][3].getPieceColor()==compColor && board[2][3].getType() ==1 && board[1][0].getType() == 1 && board[1][0].getPieceColor() == compColor){
        Coor cur;
        cur.x = 2;
        cur.y = 3;
        Coor nex;
        nex.x = 3;
        nex.y = 4;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[4][3].getEmpty()==1 && board[4][1].getType() == 1 && board[4][1].getPieceColor()==userColor && board[3][4].getPieceColor()==compColor && board[3][4].getType() ==1 && board[1][0].getType() == 1 && board[1][0].getPieceColor() == compColor){
        Coor cur;
        cur.x = 3;
        cur.y = 4;
        Coor nex;
        nex.x = 4;
        nex.y = 3;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    //upper corner variation
    if (board[1][0].getEmpty()==1 && board[0][1].getType() == 1 && board[0][1].getPieceColor()==userColor && board[2][1].getPieceColor()==compColor && board[2][1].getType() ==1 && board[3][2].getType() == 1 && board[3][2].getPieceColor() == compColor){
        Coor cur;
        cur.x = 2;
        cur.y = 1;
        Coor nex;
        nex.x = 1;
        nex.y = 0;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[0][1].getEmpty()==1 && board[1][2].getType() == 1 && board[1][2].getPieceColor()==userColor && board[3][2].getPieceColor()==compColor && board[3][2].getType() ==1 && board[1][0].getType() == 1 && board[1][0].getPieceColor() == compColor){
        Coor cur;
        cur.x = 1;
        cur.y = 0;
        Coor nex;
        nex.x = 0;
        nex.y = 1;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[4][3].getEmpty()==1 && board[0][3].getType() == 1 && board[0][3].getPieceColor()==userColor && board[0][1].getPieceColor()==compColor && board[0][1].getType() ==1 && board[3][2].getType() == 1 && board[3][2].getPieceColor() == compColor){
        Coor cur;
        cur.x = 3;
        cur.y = 2;
        Coor nex;
        nex.x = 4;
        nex.y = 3;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[3][4].getEmpty()==1 && board[1][4].getType() == 1 && board[1][4].getPieceColor()==userColor && board[4][3].getPieceColor()==compColor && board[4][3].getType() ==1 && board[0][1].getType() == 1 && board[0][1].getPieceColor() == compColor){
        Coor cur;
        cur.x = 4;
        cur.y = 3;
        Coor nex;
        nex.x = 3;
        nex.y = 4;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    //lower corner variation
    if (board[6][7].getEmpty()==1 && board[7][6].getType() == 1 && board[7][6].getPieceColor()==userColor && board[4][5].getPieceColor()==compColor && board[4][5].getType() ==1 && board[5][6].getType() == 1 && board[5][6].getPieceColor() == compColor){
        Coor cur;
        cur.x = 5;
        cur.y = 6;
        Coor nex;
        nex.x = 6;
        nex.y = 7;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[7][6].getEmpty()==1 && board[6][5].getType() == 1 && board[6][5].getPieceColor()==userColor && board[4][5].getPieceColor()==compColor && board[4][5].getType() ==1 && board[6][7].getType() == 1 && board[6][7].getPieceColor() == compColor){
        Coor cur;
        cur.x = 6;
        cur.y = 7;
        Coor nex;
        nex.x = 7;
        nex.y = 6;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[3][4].getEmpty()==1 && board[7][4].getType() == 1 && board[7][4].getPieceColor()==userColor && board[4][5].getPieceColor()==compColor && board[4][5].getType() ==1 && board[7][6].getType() == 1 && board[7][6].getPieceColor() == compColor){
        Coor cur;
        cur.x = 4;
        cur.y = 5;
        Coor nex;
        nex.x = 3;
        nex.y = 4;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[4][3].getEmpty()==1 && board[6][3].getType() == 1 && board[6][3].getPieceColor()==userColor && board[3][4].getPieceColor()==compColor && board[3][4].getType() ==1 && board[7][6].getType() == 1 && board[7][6].getPieceColor() == compColor){
        Coor cur;
        cur.x = 3;
        cur.y = 4;
        Coor nex;
        nex.x = 4;
        nex.y = 3;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    //these four are for lower corner
    if (board[7][6].getEmpty()==1 && board[6][7].getType() == 1 && board[6][7].getPieceColor()==userColor && board[5][4].getPieceColor()==compColor && board[5][4].getType() ==1 && board[6][5].getType() == 1 && board[6][5].getPieceColor() == compColor){
        Coor cur;
        cur.x = 6;
        cur.y = 5;
        Coor nex;
        nex.x = 7;
        nex.y = 6;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[6][7].getEmpty()==1 && board[5][6].getType() == 1 && board[5][6].getPieceColor()==userColor && board[5][4].getPieceColor()==compColor && board[5][4].getType() ==1 && board[7][6].getType() == 1 && board[7][6].getPieceColor() == compColor){
        Coor cur;
        cur.x = 7;
        cur.y = 6;
        Coor nex;
        nex.x = 6;
        nex.y = 7;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[4][3].getEmpty()==1 && board[4][7].getType() == 1 && board[4][7].getPieceColor()==userColor && board[5][4].getPieceColor()==compColor && board[5][4].getType() ==1 && board[6][7].getType() == 1 && board[6][7].getPieceColor() == compColor){
        Coor cur;
        cur.x = 5;
        cur.y = 4;
        Coor nex;
        nex.x = 4;
        nex.y = 3;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    if (board[3][4].getEmpty()==1 && board[3][6].getType() == 1 && board[3][6].getPieceColor()==userColor && board[4][3].getPieceColor()==compColor && board[4][3].getType() ==1 && board[6][7].getType() == 1 && board[6][7].getPieceColor() == compColor){
        Coor cur;
        cur.x = 4;
        cur.y = 3;
        Coor nex;
        nex.x = 3;
        nex.y = 4;
        UserInput finish(0, cur, nex);
        updateBoard(finish);
        return true;
    }
    return false;
}

BoardState & BoardState::operator=(BoardState & rhs){
    if (this != &rhs){
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                board[j][i] = rhs.board[j][i];
            }
        }
        numUserPieces = rhs.numUserPieces;
        numCompPieces = rhs.numCompPieces;
        moveCounter = rhs.moveCounter;
        userColor = rhs.userColor;
        compColor = rhs.compColor;
        turn = rhs.turn;
        startOfUserTurn = rhs.startOfUserTurn;
        lastX = rhs.lastX;
        lastY = rhs.lastY;
    }
    return *this;
}

int BoardState::checkMoveValue(int depth){
    if (depth < 1){
        int compValue = 0;
        int userValue = 0;
        int userKingX = 8;
        int userKingY = 8;
        bool breakBig = false;
        for (int i = 0; i<8; i++){
            for (int j =0; j < 8; j++){
                if (board[j][i].getPieceColor() == userColor && board[j][i].getType()==1){
                    userKingX = j;
                    userKingY = i;
                    breakBig = true;
                    break;
                }
            }
            if (breakBig == true){
                break;
            }
        }
        for (int i = 0; i< 8; i++){
            for (int j = 0; j<8; j++){
                if (board[j][i].getPieceColor() == userColor && board[j][i].getType()==0){
                    userValue += (30 + (7-i));
                }
                if (board[j][i].getPieceColor() == userColor && board[j][i].getType()==1){
                    userValue = userValue + 40;
                }
                if (board[j][i].getPieceColor() == compColor && board[j][i].getType()==0){
                    compValue = compValue + 30 + i;
                }
                if (board[j][i].getPieceColor() == compColor && board[j][i].getType()==1){
                    compValue = compValue + 40;
                    if (userKingX != 8){ //used to close the gap at the end of the game to allow comp to win
                        int distanceX = userKingX - j;
                        if (distanceX < 0){
                            distanceX = -distanceX;
                        }
                        int distanceY = userKingY - i;
                        if (distanceY < 0){
                            distanceY = -distanceY;
                        }
                        int distance;
                        if (distanceX > distanceY){
                            distance = distanceX;
                        }
                        else{
                            distance = distanceY;
                        }
                        if (distance > 2){
                            compValue += (7-distance);
                        }
                        else{
                            compValue += 4; //max points for reaching within three squares - no further points for moving farther away
                        }


                    }
                }
            }
        }
        bool solution = endGameWin();
        if(solution == true){
            compValue += 20;
        }
        return (userValue - compValue);
    }
    else{
        int checkPiece;
        if (turn == 0){
            checkPiece = userColor;
        }
        else{
            checkPiece = compColor;
        }
        allMoves * moves = new allMoves();
        moves->jArrNum = 0;
        moves->rArrNum = 0;
        PossibleMoves(moves, checkPiece);
        if (moves->jArrNum == 0 && moves->rArrNum == 0){
            if (turn == 0){
                delete moves;
                return -1000;
            }
            else{
                delete moves;
                return 1000;
            }
        }
        else if (moves->jArrNum == 0){
            int best;
            if (turn == 0){
                best = -1000;
            }
            else{
                best = 1000;
            }
            for (int i = 0; i < moves->rArrNum; i++){
                BoardState newCopy = *this;
                newCopy.updateBoard(moves->regArray[i]);
                newCopy.changeTurn();
                int result = newCopy.checkMoveValue(depth - 1);
                if (result > 900){ // the move loses value the longer it takes to get to that point
                    result--;
                }
                if (result < 900){
                    result++;
                }
                if (turn == 0 && (result > best)){
                    best = result;
                }
                else if(turn == 1 && (result < best)){
                    best = result;
                }
            }
            delete moves;
            return best;
        }
        else{
            jumpCompare best;
            if (turn == 0){
                best.value = -1000;
            }
            else{
                best.value = 1000;
            }
            for (int i = 0; i < moves->jArrNum; i++){
                BoardState newCopy = *this;
                jumpCompare result = newCopy.detJumpOrder(moves->jumpArray[i], depth);
                if (result.value > 900){ // the move loses value the longer it takes to get there
                    best.value--;
                }
                if (result.value < 900){
                    best.value++;
                }
                if (turn == 0 && (result.value > best.value)){
                    best = result;
                }
                else if(turn == 1 && (result.value < best.value)){
                    best = result;
                }
            }
            delete moves;
            return best.value;
        }
    }
}

jumpCompare BoardState::detJumpOrder(UserInput & currentMove, int depth){
    jumpCompare end;
    end.jumpOrder.push_back(currentMove);
    end.jOrderSize = 1;
    BoardState updated = *this;
    updated.updateBoard(currentMove);
    return updated.detJumpOrderHelper(end, depth);
}

jumpCompare BoardState::detJumpOrderHelper(jumpCompare lowerMove, int depth){
    //bool further = checkFurther(lowerMove.jumpOrder[jOrderSize-1]);
    int checkPiece;
    if (turn == 0){
        checkPiece = userColor;
    }
    else{
        checkPiece = compColor;
    }
    allMoves * moves = new allMoves();
    moves->jArrNum = 0;
    moves->rArrNum = 0;
    PossibleMoves(moves, checkPiece);
    if (moves->jArrNum == 0){
        changeTurn();
        //Value recursion
        int moveValue = checkMoveValue(depth); //doesn't lower depth for jump sequence
        //return jumpCompare
        lowerMove.value = moveValue;
        delete moves;
        return lowerMove;
    }
    else{
        jumpCompare best;
        if (turn == 0){
            best.value = -1000;
        }
        else{
            best.value = 1000;
        }
        for(int i = 0; i < moves->jArrNum; i++){
          BoardState newCopy = *this;
          newCopy.updateBoard(moves->jumpArray[i]);
          jumpCompare jCopy = lowerMove;
          jCopy.jOrderSize++;
          jCopy.jumpOrder.push_back(moves->jumpArray[i]);
          jumpCompare result = newCopy.detJumpOrderHelper(jCopy, depth);
          if (turn == 0 && (result.value > best.value)){
              best = result;
          }
          else if(turn == 1 && (result.value < best.value)){
              best = result;
          }
        }
        delete moves;
        return best;
    }
}


void BoardState::emptyBoard(){
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
              board[j][i] = Piece();
        }
    }
    numUserPieces = 0;
    numCompPieces = 0;
    moveCounter = 0;
}

bool BoardState::winLoss(void){
    int checkPiece;
    if (turn == 0){
        checkPiece = userColor;
    }
    else{
        checkPiece = compColor;
    }
    allMoves * moves = new allMoves();
    moves->jArrNum = 0;
    moves->rArrNum = 0;
    PossibleMoves(moves, checkPiece);
    if (moves->jArrNum == 0 && moves->rArrNum == 0){
        delete moves;
        return true;
    }
    else{
        delete moves;
        return false;
    }
}

void BoardState::changeStep(int change, int x, int y){
    startOfUserTurn = change;
    lastX = x;
    lastY = y;
}

int BoardState::getStartOfUserTurn(void){
    return startOfUserTurn;
}

int BoardState::getLastY(void){
    return lastY;
}

int BoardState::getLastX(void){
    return lastX;
}

int BoardState::getCompColor(void){
    return compColor;
}

int BoardState::getMoveCounter(void){
    return (moveCounter / 2);
}

void BoardState::changeTurn(void){
  moveCounter++;
  startOfUserTurn = 0;
  if (board[lastX][lastY].getUpgrade() == 1){
    board[lastX][lastY] = Piece(board[lastX][lastY].getPieceColor(), 1, 0);
  }
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
bool BoardState::checkNoJumps(){
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
     QMessageBox::information(NULL,"Not Your Piece","You chose a computer's piece!");
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
      bool noJump = checkNoJumps();
      if (noJump == true){
           return true;
      }
      else{
          QMessageBox::information(NULL,"Jump","You have to jump!");
          return false;
      }
    }
    else{
       QMessageBox::information(NULL,"Not Legal","That's not a legal move!");
       return false;
    }
  }
}

int BoardState::getTurn(void){
  return turn;
}

BoardState::BoardState(int color){
  numUserPieces = 12;
  numCompPieces = 12;
  startOfUserTurn = 0;
  lastX = 0;
  lastY = 0;
  turn = color;
  userColor = color;
  moveCounter = 0;
  if (color == 1){
    compColor = 0;
  }
  else{
    compColor = 1;
  }
  for(int i = 0; i < 8; i=i+2){
    for(int j = 0; j < 8; j=j+2){
      board[j][i] = Piece();
    }
  }
  for(int i = 1; i < 8; i=i+2){
    for(int j = 1; j < 8; j=j+2){
      board[j][i] = Piece();
    }
  }
  for (int j = 0; j < 8; j=j+2){
    board[j][3] = Piece();
  }
  for (int j = 1; j < 8; j=j+2){
    board[j][4] = Piece();
  }
  for (int i = 5; i < 8; i = i+2){
    for (int j = 0; j < 8; j= j+2){
      board[j][i] = Piece(color);
    }
  }
  for(int j = 1; j< 8; j=j+2){
    board[j][6] = Piece(color);
  }
  for (int i = 0; i < 3; i = i+2){
    for (int j = 1; j < 8; j= j+2){
      board[j][i] = Piece(compColor);
    }
  }
  for(int j = 0; j< 8; j=j+2){
    board[j][1] = Piece(compColor);
  }
}

void BoardState::updateBoard(UserInput & input){
  int nY = input.getNext().y;
  int nX = input.getNext().x;
  int cY = input.getCurrent().y;
  int cX = input.getCurrent().x;
  lastX = nX;
  lastY = nY;
  if (board[cX][cY].getPieceColor() == userColor){
    if (nY == 0 && board[cX][cY].getType() != 1){
      board[nX][nY] = Piece(board[cX][cY].getPieceColor(), 1, 1);
    }
    else{
      board[nX][nY] = board[cX][cY];
    }
  }
  if (board[cX][cY].getPieceColor() == compColor){
    if (nY == 7 && board[cX][cY].getType() != 1){
      board[nX][nY] = Piece(board[cX][cY].getPieceColor(), 1, 1);
    }
    else{
      board[nX][nY] = board[cX][cY];
    }
  }
  //sets empty piece to old current square
  board[cX][cY] = Piece();
  //deletes middle piece in a jump
  if (cX - nX == -2 || cX - nX == 2){
    startOfUserTurn = 1; //sets the middle of the turn -- used for both computer and user
    board[cX - ((cX - nX) /2)][cY - ((cY - nY)/2)] = Piece();
    if (turn == 0){
        numCompPieces--;
    }
    else{
        numUserPieces--;
    }
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
    board[nX][nY] = Piece(board[nX][nY].getPieceColor(), 1, 0);
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

void BoardState::PossibleMoves(allMoves * comp, int checkColor){
   int opponentColor;
   if (checkColor == 0){
       opponentColor = 1;
   }
   else{
       opponentColor = 0;
   }
   for (int i = 0; i < 8; i++){
    for (int j = 0; j< 8; j++){
      if ((startOfUserTurn == 1 && j == lastX && i == lastY) || startOfUserTurn == 0){
        if (board[j][i].getPieceColor() == checkColor && board[j][i].getUpgrade() == 0){
        Coor current;
        Coor next;
        current.x = j;
        current.y = i;
        if (i < 6 && (board[j][i].getType() == 1 || board[j][i].getPieceColor() == compColor)){
            if ( j > 1){
                if (board[j-1][i+1].getPieceColor() == opponentColor && board[j-2][i+2].getEmpty() == 1){
                    next.x = j-2;
                    next.y = i+2;
                    UserInput newElement(0, current, next);
                    (comp->jumpArray).push_back(newElement);
                    comp->jArrNum++;
                }
            }
      if ( j < 6){
        if (board[j+1][i+1].getPieceColor() == opponentColor && board[j+2][i+2].getEmpty() == 1){
          next.x = j+2;
          next.y = i+2;
          UserInput newElement(0, current, next);
          (comp->jumpArray).push_back(newElement);
          comp->jArrNum++;
        }
      }
    }
    if (i > 1 && (board[j][i].getType() == 1 || board[j][i].getPieceColor() == userColor)){
      if ( j > 1){
        if (board[j-1][i-1].getPieceColor() == opponentColor && board[j-2][i-2].getEmpty() == 1){
          next.x = j-2;
          next.y = i-2;
          UserInput newElement(0, current, next);
          (comp->jumpArray).push_back(newElement);
          comp->jArrNum++;
        }
      }
      if ( j < 6){
        if (board[j+1][i-1].getPieceColor() == opponentColor && board[j+2][i-2].getEmpty() == 1){
          next.x = j+2;
          next.y = i-2;
          UserInput newElement(0, current, next);
          (comp->jumpArray).push_back(newElement);
          comp->jArrNum++;
        }
      }
    }
    if (i <7 && (board[j][i].getType() == 1 || board[j][i].getPieceColor() == compColor)){ // moving to regular moves
        if ( j > 0){
          if (board[j-1][i+1].getEmpty() == 1){
            next.x = j-1;
            next.y = i+1;
            UserInput newElement(0, current, next);
            (comp->regArray).push_back(newElement);
            comp->rArrNum++;
            }
          }
        if ( j < 7){
            if (board[j+1][i+1].getEmpty() == 1){
                next.x = j+1;
                next.y = i+1;
                UserInput newElement(0, current, next);
                (comp->regArray).push_back(newElement);
                comp->rArrNum++;
            }
        }
      }
    if (i > 0 && (board[j][i].getType() == 1 || board[j][i].getPieceColor() == userColor)){
      if ( j > 0){
        if (board[j-1][i-1].getEmpty() == 1){
          next.x = j-1;
          next.y = i-1;
          UserInput newElement(0, current, next);
          (comp->regArray).push_back(newElement);
          comp->rArrNum++;
        }
      }
      if ( j < 7){
        if (board[j+1][i-1].getEmpty() == 1){
          next.x = j+1;
          next.y = i-1;
          UserInput newElement(0, current, next);
          (comp->regArray).push_back(newElement);
          comp->rArrNum++;
        }
      }
        }
        }
      }
  }
  }
}

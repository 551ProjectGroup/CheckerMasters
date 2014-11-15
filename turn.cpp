#include "boardstate.h"
#include "displayboard.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <QGraphicsScene>
#include "turn.h"

BoardState * easyMode(BoardState * game,QGraphicsScene *scene);

UserInput GUIFunction(BoardState *state, guiPiece *piecearray) {
    for(int i=0;i<24;i++) {
        if(piecearray[i].getMoved()) {
            return piecearray[i].getUin();
        }
    }
}

BoardState * easyMode(BoardState * game,QGraphicsScene *scene){
  //userInput -> name is not appropriate, may need to change later
  allMoves * comp = new allMoves();
  //comp->jumpArray = new UserInput*();
  comp->jArrNum = 0;
  comp->rArrNum = 0;
  game->comPossibleMoves(comp);
  //choose random move and updateBoard
  srand(time(NULL));
  if (comp->jArrNum != 0){
    int randomMove = rand() % comp->jArrNum;
    game->updateBoard(comp->jumpArray[randomMove]);
    bool further = game->checkFurther(comp->jumpArray[randomMove]);
    while (further == true){
      UserInput * nextMove = game->comMoreMove(comp->jumpArray[randomMove].getNext()); //takes in the previous next coordinate to use as the start coordinate. Also, computes the next move with a random value
      game->updateBoard(*nextMove);
      further = game->checkFurther(*nextMove);
      comp->jumpArray[randomMove] = *nextMove;
    }
  }
  else{
    int randomMove = rand() % comp->rArrNum;
    game->updateBoard(comp->regArray[randomMove]);
  }
  DisplayBoard disp;
  disp.displayScene(game,scene);
  return game;
}

BoardState * computerTurn(BoardState * game, int difficulty, QGraphicsScene *scene){
  if (difficulty == 0){
    game = easyMode(game,scene);
  }
  else{
    //game = hardMode(game); // This mode is not currently enabled
  }
  game->changeTurn();
  DisplayBoard disp;
  disp.displayScene(game,scene);
  return game;
}

void userOneMove(BoardState * game, UserInput & input, guiPiece * piecearray, QGraphicsScene *scene){
  bool legal = false;
  if (input.getType() == 0){ // 0 -> normal input
    while (legal == false){
      legal = game->checkLegality(input);
      if (legal == false){
    input = GUIFunction(game,piecearray);
      }
    }

  //update the board state(board) -> BoardState
    game->updateBoard(input);
    DisplayBoard disp;
    disp.displayScene(game,scene);
  }
}

BoardState * userTurn(BoardState * game, guiPiece *piecearray, QGraphicsScene *scene){
  //check for interrups (i.e menu options, move(next square or current square), computer's turn...)
  UserInput input(GUIFunction(game, piecearray));
  //if next square, current square -> check the legality of the move -> BoardState(current square, next square)
  if (input.getType() == 0){ // 0 -> normal input
    userOneMove(game, input, piecearray, scene);
  //Load the graphics -> Ashwin

  //check if there are any further moves that turn
  //if there are: Repeat steps -> check for... until Load the graphics
  //if there are no further moves: update BoardState(turn) -> to computer
    bool further = game->checkFurther(input);
    while (further == true){
      UserInput newInput(GUIFunction(game,piecearray));
      if (newInput.getCurrent().x == input.getNext().x && newInput.getCurrent().y == input.getNext().y){
    userOneMove(game, newInput,piecearray, scene);
    further = game->checkFurther(newInput);
    input = newInput;
      }
    }
  }
  game->changeTurn();
  DisplayBoard disp;
  disp.displayScene(game,scene);;
  return game;
}

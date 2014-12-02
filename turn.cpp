#include "boardstate.h"
#include "displayboard.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <QGraphicsScene>
#include "turn.h"
#include <QMessageBox>

BoardState * hardMode(BoardState * game, int depth){
  allMoves * comp = new allMoves();
  comp->jArrNum = 0;
  comp->rArrNum = 0;
  game->PossibleMoves(comp, game->getCompColor());
  srand(time(NULL));
  if (comp->jArrNum != 0){
      //takes in middle move -> calls a function returns a structure (vector of userinput and a value)
    //compares the structure to the best structure
    //if same, pick random otherwise pick lowest
      jumpCompare best;
      best.value = 1000;
      for(int i =0; i < comp->jArrNum; i++){
         BoardState newCopy = *game;
         jumpCompare result = newCopy.detJumpOrder(comp->jumpArray[i], depth+1);
         if (result.value == best.value){
            int randomMove = rand() % 2;
            if (randomMove == 1){
                best = result;
            }
         }
         else if (result.value < best.value){
            best = result;
         }
      }
       //now has best structure

      //for loop which does the following
      //executes the moves
      //updates the board
      for (int i = 0; i < best.jOrderSize; i++){
          game->updateBoard(best.jumpOrder[i]);
      }
      delete comp;
      return game;
      //return
  }
  else{
      //for loop
      //sub function of jump function
      //compares the numbers
      //if same, pick random, otherwise pick lowest
      int best = 1000;
      int bestIndex = 0;
      for (int i = 0; i < comp->rArrNum; i++){
          BoardState newCopy = *game;
          newCopy.updateBoard(comp->regArray[i]);
          newCopy.changeTurn();
          int result = newCopy.checkMoveValue(depth);
          if (result == best){
             int randomMove = rand() % 2;
             if (randomMove == 1){
                 best = result;
                 bestIndex = i;
             }
          }
          else if (result < best){
             best = result;
             bestIndex = i;
          }
      }
      if (best > -900){ //no winning solution was found
          //endgame table
          bool solution = game->endGameWin();
          if(solution == true){
              delete comp;
              return game;
          }
      }
      //now has the best number
      //execute
      //update board
      game->updateBoard(comp->regArray[bestIndex]);
      //return
      delete comp;
      return game;
  }
}

BoardState * easyMode(BoardState * game){
  allMoves * comp = new allMoves();
  comp->jArrNum = 0;
  comp->rArrNum = 0;
  game->PossibleMoves(comp, game->getCompColor());
  //choose random move and updateBoard
  srand(time(NULL));
  int randomMove;
  bool further;
  if (comp->jArrNum != 0){
    randomMove = rand() % comp->jArrNum;
    game->updateBoard(comp->jumpArray[randomMove]);
    further = game->checkFurther(comp->jumpArray[randomMove]);
    while (further == true){
      UserInput * nextMove = game->comMoreMove(comp->jumpArray[randomMove].getNext()); //takes in the previous next coordinate to use as the start coordinate. Also, computes the next move with a random value
      game->updateBoard(*nextMove);
      further = game->checkFurther(*nextMove);
      comp->jumpArray[randomMove] = *nextMove;
      delete nextMove;
    }
  }
  else{
    randomMove = rand() % comp->rArrNum;
    game->updateBoard(comp->regArray[randomMove]);
    //checks if there is a newly promoted king and sets upgrade to 0 (check further usually also check for further moves but there is no way the computer could have additional moves in this case)
    further = game->checkFurther(comp->regArray[randomMove]);
  }
  delete comp;
  return game;
}

BoardState * computerTurn(BoardState * game, int difficulty){
  if (difficulty == 0 || game->getMoveCounter() < 1){
    game = easyMode(game);
  }
  else if(difficulty == 1){
    game = hardMode(game, 3); // This mode is not currently enabled
  }
  else if(difficulty == 2){
    game = hardMode(game, 4);
  }
  game->changeTurn();
  return game;
}

BoardState * userTurn(BoardState * game, UserInput & input){
    if (game->getStartOfUserTurn() == 1){ //This means the user is in the middle of a turn
       if (input.getCurrent().x != game->getLastX() || input.getCurrent().y != game->getLastY()){ //the user didn't select the same piece
           QMessageBox::information(NULL,"Invalid Jump","You must jump with the same piece!");
           return game;
       }
    }
    bool legal = game->checkLegality(input);
    if (legal == false){
        return game; //user made an illegal move
    }
    game->updateBoard(input);
    bool further = game->checkFurther(input);
    if (further == true){
       game->changeStep(1, input.getNext().x, input.getNext().y);
       return game;
    }
    else{
        game->changeStep(0, input.getNext().x, input.getNext().y);
        game->changeTurn(); //user has completed his turn. Now computer's turn
        return game;
    }
}

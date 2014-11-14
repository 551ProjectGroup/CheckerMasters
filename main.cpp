#include<cstdlib>
#include "boardstate.h"
#include "tester.h"
#include <cstdlib>
#include <time.h>
#include <vector>

BoardState * easyMode(BoardState * game){
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
  GUIShow(game);
  return game;
}

BoardState * computerTurn(BoardState * game, int difficulty){
  if (difficulty == 0){
    game = easyMode(game);
  }
  else{
    //game = hardMode(game); // This mode is not currently enabled
  }
  game->changeTurn();
  return game;
}

void userOneMove(BoardState * game, UserInput & input){
  bool legal = false;
  if (input.getType() == 0){ // 0 -> normal input    
    while (legal == false){
      legal = game->checkLegality(input); 
      if (legal == false){
	input = GUIFunction(game);
      }
    }
  
  //update the board state(board) -> BoardState
    game->updateBoard(input);
    GUIShow(game);
  }
}
 
BoardState * userTurn(BoardState * game){
  //check for interrups (i.e menu options, move(next square or current square), computer's turn...)
  UserInput input(GUIFunction(game));
  //if next square, current square -> check the legality of the move -> BoardState(current square, next square)
  if (input.getType() == 0){ // 0 -> normal input    
    userOneMove(game, input);
  //Load the graphics -> Ashwin
    
  //check if there are any further moves that turn
  //if there are: Repeat steps -> check for... until Load the graphics
  //if there are no further moves: update BoardState(turn) -> to computer
    bool further = game->checkFurther(input);
    while (further == true){
      UserInput newInput(GUIFunction(game));
      if (newInput.getCurrent().x == input.getNext().x && newInput.getCurrent().y == input.getNext().y){
	userOneMove(game, newInput);
	further = game->checkFurther(newInput);
	input = newInput;
      }
    }
  }
  game->changeTurn();
  GUIShow(game);
  return game;
}

BoardState * newGameFunction(NewGame & game){
  //Make a board -> BoardState
  BoardState * newBoard = new BoardState(game.getColor());
  //Load the start state -> BoardState (default constructor)
  //Make default piece -> Piece()
  //Assign pieces to places of board
  return newBoard;
}

int main(){
  //Menu input -> user chooses color and difficulty -> Later
  //Discuss with Ashwin what kind of value it returns
  //Returns game status(new game(0), save game, load game, quit game, settings(maybe))
  int gameStatus = mainMenu();// = need input from user -> well need to change with mainMenu
  BoardState * gameBoard = NULL;
  int difficulty;
  if (gameStatus == 0){ 
  //If new game: color, difficulty, timer(maybe)   
    difficulty = difficultyMenu(); // = need input from user
    int color = colorMenu(); // = need input from user
    NewGame game(difficulty, color);
    gameBoard = newGameFunction(game);
  }

 
  //Load the graphics -> Ashwin
  GUIShow(gameBoard);

  //check whose turn it is -> in board state
  //either userTurn
  //or computerTurn
  while(1){
    if(gameBoard->getTurn() == 0){
      gameBoard = userTurn(gameBoard);
    }
    else{
      gameBoard = computerTurn(gameBoard, difficulty);
    }
    //check for win loss
    /*int win = winLoss(gameBoard);
    if (win == 1){
      break;
      }*/
  }
  
 

  return EXIT_SUCCESS;
}

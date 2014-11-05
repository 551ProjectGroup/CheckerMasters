#include<cstdlib>
#include "boardstate.h"

void userTurn(){
  //check for interrups (i.e menu options, move(next square or current square), computer's turn...)
  //if next square, current square -> check the legality of the move -> BoardState(current square, next square)

  //update the board state(board) -> BoardState

  //Load the graphics -> Ashwin

  //check if there are any further moves that turn
  //if there are: Repeat steps -> check for... until Load the graphics
  //if there are no further moves: update BoardState(turn) -> to computer
}

void newGameFunction(NewGame & game){
  //Make a board -> BoardState
  BoardState * newBoard = new BoardState(game.getColor());
  //Load the start state -> BoardState (default constructor)
  //Make default piece -> Piece()
  //Assign pieces to places of board
}

int main(){
  //Menu input -> user chooses color and difficulty -> Later
  //Discuss with Ashwin what kind of value it returns
  //Returns game status(new game(0), save game, load game, quit game, settings(maybe))
  int gameStatus;// = need input from user
  if (gameStatus == 0){ 
  //If new game: color, difficulty, timer(maybe)   
    int difficulty; // = need input from user
    int color; // = need input from user
    NewGame game(difficulty, color);
    newGameFunction(game);
  }

 
  //Load the graphics -> Ashwin
  
  //check whose turn it is -> in board state
  //either userTurn
  //or computerTurn

  //check for win loss

  return EXIT_SUCCESS;
}

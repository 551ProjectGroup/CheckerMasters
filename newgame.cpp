#include "newgame.h"
#include "piece.h"



BoardState *NewGame::getGamestate() const
{
    return gamestate;
}

void NewGame::setGamestate(BoardState *value)
{
    gamestate = value;
}

void NewGame::winLoss(int val)
{
    winloss = val;
}

void NewGame::compplays(int play) {
    compturn = play;
}

void NewGame::run()
{
   /* QMutex mutex;
    mutex.lock();
    while(1) {
    Call methods to make the computer play. At the end of that method the turn is changed.

    if(winloss) {
        emit decision(winloss);
        break;
    }
    compplays.wait(&mutex);
     This thread is sleeping till its the comps turn to play again.
     That way we wont be executing the inifinite loop over and over again.
     We wake this thread up at the end of the users turn check method
    }*/
}

NewGame::NewGame(NewGame &rhs) : QThread() {
    color = rhs.color;
    difficulty = rhs.difficulty;
}

int NewGame::getPieceColor()
{
    return color;
}

void NewGame::setDifficulty(int d)
{
  difficulty = d;
}

int NewGame::getDifficulty(void)
{
  return difficulty;
}

void NewGame::setPieceColor(int color)
{
    color = color;
}

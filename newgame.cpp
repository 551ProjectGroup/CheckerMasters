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
void NewGame::run()
{
    //Inifinite loop to be made here.
}

NewGame::NewGame(NewGame &rhs) {
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

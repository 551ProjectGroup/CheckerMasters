#ifndef NEWGAME_H
#define NEWGAME_H
#include <QThread>
#include <QGraphicsScene>
#include "boardstate.h"

class NewGame : public QThread
{
private:
Q_OBJECT                                        //This guy is needed to start a thread. This thread will run our game without stopping.
int difficulty;                                 //Difficulty
int color;                                      //user colour.
BoardState *gamestate;
int winloss;
int compturn;

public:
virtual void run();
explicit NewGame(QObject *parent = 0);          //a method needed for threads.
NewGame(): difficulty(0), color(0) {}
NewGame(int d, int c): difficulty(d), color(c) {}
NewGame(NewGame &rhs);
int getPieceColor(void);                        //Getters and setters.
void setDifficulty(int d);
int getDifficulty(void);
void setPieceColor(int color);
                    //This guy renders the board pieces and gives back a board.
void winLoss(int val);
void compplays(int play);
BoardState *getGamestate() const;
void setGamestate(BoardState *value);
};

#endif // NEWGAME_H

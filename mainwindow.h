#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "boardstate.h"
#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtGui>
#include <QtCore>
#include <QLinearGradient>
#include <QRadialGradient>
#include "piece.h"
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getDifficulty() const;
    void setDifficulty(int value);
    int getPieceColor() const;
    void setPieceColor(int value);
    void updateGame(BoardState * currstate);
    void setTimer(bool timeOption);
    void userlcd(BoardState * bState);
    void complcd(BoardState * bState);
    void movelcd(BoardState * bState);
private:
    QTimer *timer;
    QTime *timeLim;
    bool audio;
    bool paused;
    bool timerOn;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int difficulty;     //need the difficulty to be passed from the UI to the newgame object.
    int color;          //same for the color object.
    BoardState * bState;
    int timeLength;
private slots:
    void update();
    void on_actionExit_triggered();                     //All of these are the UI events. eg: action on click of EXIT
    void on_actionNew_Game_triggered();
    void on_actionEasy_triggered();                     //Action for difficulty easy
    void on_actionOn_triggered();                       //Action for Audio on
    void on_actionOff_triggered();                      //Action for Audio off
    void on_actionHard_triggered();                     //Action for difficulty hard
    void on_actionBlack_Magic_triggered();              //Try this button!
    void on_actionRed_triggered();                      //Select red for the player.
    void on_actionBlack_triggered();                    //Select Black for the player.
    void on_actionLoad_Game_triggered();
    void on_actionSave_Game_triggered();
    void on_actionForfeit_triggered();
    void on_actionHard_2_triggered();
    void on_actionOn_2_triggered();
    void on_actionOff_2_triggered();
    void on_action5_min_triggered();
    void on_action10_min_triggered();
    void on_action1_min_triggered();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "boardstate.h"
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QLinearGradient>
#include <QRadialGradient>
#include "piece.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int difficulty;     //need the difficulty to be passed from the UI to the newgame object.
    int color;          //same for the color object.

private slots:
    void on_actionExit_triggered();                     //All of these are the UI events. eg: action on click of EXIT
    void on_actionNew_Game_triggered();
    void on_actionEasy_triggered();                     //Action for difficulty easy
    void on_actionOn_triggered();                       //Action for Audio on
    void on_actionOff_triggered();                      //Action for Audio off
    void on_actionHard_triggered();                     //Action for difficulty hard
    void on_actionBlack_Magic_triggered();              //Try this button!
    void on_actionRed_triggered();                      //Select red for the player.
    void on_actionBlack_triggered();                    //Select Black for the player.
};

#endif // MAINWINDOW_H
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardstate.h"
#include "displayboard.h"
#include "turn.h"
#include "guipiece.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));                                 //Test code here
    scene = new QGraphicsScene(this);                   //This is a test code that uses a scene. A scene is nothing but a canvas on which you can draw stuff.
    QDir dir(QCoreApplication::applicationDirPath());
    QPixmap backgroundImge(dir.absolutePath() + "/checkers1.jpg");
    scene->addPixmap(backgroundImge);                                                 //A piece was just drawn on the canvas.
    ui->graphicsView->setScene(scene);
    timeLim = new QTime(0,0,0);
    ui->lcdNumber->display(timeLim->toString());
    audio = false;
    BoardState *currstate = new BoardState(getPieceColor());
    bState = currstate;
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer(this,QMediaPlayer::StreamPlayback);
    player->setPlaylist(playlist);
    playlist->addMedia(QUrl::fromLocalFile(dir.absolutePath() + "/Pixel Peeker Polka - slower.mp3"));
    playlist->addMedia(QUrl::fromLocalFile(dir.absolutePath() + "/Sneaky Snitch.mp3"));
    playlist->setCurrentIndex(2);
    player->setVolume(50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getDifficulty() const
{
    return difficulty;
}

void MainWindow::setDifficulty(int value)
{
    difficulty = value;
}
int MainWindow::getPieceColor() const
{
    return color;
}

void MainWindow::setPieceColor(int value)
{
    color = value;
}

void MainWindow::on_actionExit_triggered()                      //Here start the declarations of the actions we specified in the headers.
{
    bState->saveBoard(difficulty, timerOn, timeLim->minute(), timeLim->second());
    delete bState;
    close();                                                    //thats EXIT_SUCCESS
}

void MainWindow::updateGame(BoardState * currstate){
    DisplayBoard disp;
    scene = new QGraphicsScene(this);
    disp.makeScene(currstate, scene, this);                                                               //The new game class has a method whichs gives the painted board back.
    ui->graphicsView->setScene(scene);                                     //return a graphics scene from the board.
    scene->setSceneRect(0,0,800,800);
}

void MainWindow::update()
{
    timeLim->setHMS(0,timeLim->addSecs(-1).minute(),timeLim->addSecs(-1).second());
    ui->lcdNumber->display(timeLim->toString());
    if (timeLim->minute() == 0 && timeLim->second() == 0){
        QMessageBox::information(NULL,"CheckersMaster","You Ran Out of Time");
        bState->emptyBoard();
        updateGame(bState);
        timer->stop();
    }
}

void MainWindow::on_actionNew_Game_triggered()
{
    delete bState;
    if (timerOn == true){
        timer->start(1000);
        timeLim = new QTime(0,timeLength,0);
        ui->lcdNumber->display(timeLim->toString());
    }
    if(audio){
        player->play();
    }

        //This sets a default value if the user does not select a difficulty or color before new game
        DisplayBoard disp;                                                                        // makes a new game object.
        BoardState *currstate = new BoardState(getPieceColor());
        bState = currstate;
        scene = new QGraphicsScene(this);
        if(currstate->getTurn() == 1){
            currstate = computerTurn(currstate, getDifficulty());
        }
        disp.makeScene(currstate,scene, this);
                                                                        //The new game class has a method whichs gives the painted board back.
        ui->graphicsView->setScene(scene);                                     //return a graphics scene from the board.
        scene->setSceneRect(0,0,800,800);                                   //This guy kind of defines the boundries in which we can play.
        userlcd(bState);
        complcd(bState);
        movelcd(bState);
}

void MainWindow::on_actionEasy_triggered()
{
    setDifficulty(0);
}

void MainWindow::on_actionOn_triggered()
{
    audio = true;
    player->play();
    paused = false;
}

void MainWindow::on_actionOff_triggered()
{
    audio = false;
    player->pause();
    paused = true;
}

void MainWindow::on_actionHard_triggered() //this is normal/medium difficulty after update
{
     setDifficulty(1);
}

void MainWindow::on_actionBlack_Magic_triggered()
{
    QMessageBox::information(this,"Black Magic","Were you expecting Black Magic on the click of a button?");
}

void MainWindow::on_actionRed_triggered()
{
    setPieceColor(1);
}

void MainWindow::on_actionBlack_triggered()
{
    setPieceColor(0);
}

void MainWindow::on_actionLoad_Game_triggered()
{
    delete bState;
    DisplayBoard disp;                                                                        // makes a new game object.
    BoardState *currstate = new BoardState(getPieceColor());
    int * startValues = currstate->loadBoard();
    setDifficulty(startValues[0]);
    if (getDifficulty() == 3){ //file does not exist error return
        setDifficulty(0);
        on_actionNew_Game_triggered();
    }
    else{
        timerOn = startValues[1];
        if (timerOn == true){
            timer->start(1000);
            timeLim = new QTime(0,startValues[2],startValues[3]);
            ui->lcdNumber->display(timeLim->toString());
        }
        else{
            timer->stop();
            timeLim = new QTime(0,0,0);
            ui->lcdNumber->display(timeLim->toString());
        }
        bState = currstate;
        scene = new QGraphicsScene(this);
        //disp.addBoardScene(scene);
        if(currstate->getTurn() == 1){
            currstate = computerTurn(currstate, getDifficulty());
        }
        disp.makeScene(currstate,scene, this);
                                                                 //The new game class has a method whichs gives the painted board back.
        ui->graphicsView->setScene(scene);                                     //return a graphics scene from the board.
        scene->setSceneRect(0,0,800,800);
        userlcd(bState);
        complcd(bState);
        movelcd(bState);
     }
     delete startValues;
}

void MainWindow::on_actionSave_Game_triggered()
{
    bState->saveBoard(difficulty, timerOn, timeLim->minute(), timeLim->second());
}

void MainWindow::on_actionForfeit_triggered()
{
    QDir dir(QCoreApplication::applicationDirPath());
    QSoundEffect *wls = new QSoundEffect;
    wls->setSource(QUrl::fromLocalFile(dir.absolutePath() + "/defeat.wav"));
    wls->setVolume(0.25f);
    wls->play();
    QMessageBox::information(this,"CheckersMaster","You Gave Up!!");
    bState->emptyBoard();
    updateGame(bState);
    userlcd(bState);
    complcd(bState);
    movelcd(bState);
    delete bState;
}

void MainWindow::on_actionHard_2_triggered()
{
    setDifficulty(2);
}

void MainWindow::on_actionOn_2_triggered()
{
    timeLength = 15;
    timerOn = true;
    QMessageBox::information(this,"CheckersMasters","Timer will start on a New Game.");
}

void MainWindow::on_actionOff_2_triggered()
{
    timer->stop();
    timeLim->setHMS(0,0,0);
    ui->lcdNumber->display(timeLim->toString());
    timerOn = false;
}

void MainWindow::on_action5_min_triggered()
{
    timeLength = 5;
    timerOn = true;
    QMessageBox::information(this,"CheckersMasters","Timer will start on a New Game.");
}

void MainWindow::on_action10_min_triggered()
{
    timeLength = 10;
    timerOn = true;
    QMessageBox::information(this,"CheckersMasters","Timer will start on a New Game.");
}

void MainWindow::on_action1_min_triggered()
{
    timeLength = 1;
    timerOn = true;
    QMessageBox::information(this,"CheckersMasters","Timer will start on a New Game.");
}

void MainWindow::setTimer(bool timeOption){
    timerOn = timeOption;
}

void MainWindow::userlcd(BoardState *bState)
{
    ui->lcdNumber_4->display(bState->getUserPieces());
}

void MainWindow::complcd(BoardState *bState)
{
    ui->lcdNumber_3->display(bState->getCompPieces());
}

void MainWindow::movelcd(BoardState *bState)
{
    ui->lcdNumber_2->display(bState->getMoveCounter());
}


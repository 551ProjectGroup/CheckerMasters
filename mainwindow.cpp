#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardstate.h"
#include "displayboard.h"
#include "newgame.h"
#include "turn.h"
#include "guipiece.h"
#include <QtWidgets>
#include <QtGui>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);                                   //This line gives this object to actually starting displaying the UI.
    //piece1 = new Pieces(1);
                                      //Test code here
    scene = new QGraphicsScene(this);                   //This is a test code that uses a scene. A scene is nothing but a canvas on which you can draw stuff.
    //scene->addItem(p);                             //A piece was just drawn on the canvas.
    ui->graphicsView->setScene(scene);
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
    close();                                                    //thats EXIT_SUCCESS
}

void MainWindow::on_actionNew_Game_triggered()
{

        DisplayBoard disp;                                                                        // makes a new game object.
        NewGame *game = new NewGame(getDifficulty(),getPieceColor());       //Here a new game object is made based on the use inputs.
        BoardState *currstate = new BoardState(getPieceColor());
        scene = new QGraphicsScene(this);
        disp.addBoardScene(scene);
        guiPiece *piecearray = disp.makeScene(currstate,scene);
                                                                        //The new game class has a method whichs gives the painted board back.
        ui->graphicsView->setScene(scene);                                     //return a graphics scene from the board.
        scene->setSceneRect(0,0,800,800);                                   //This guy kind of defines the boundries in which we can play.
        //hardgame.run();
       // while(1) {
//            if(currstate->getTurn() == 0){
//                  currstate = userTurn(currstate, piecearray,scene);
//                }
//                else{
//                  currstate = computerTurn(currstate, difficulty,scene);
//                }
                                                                                 //This might be a good place for a thread.run()
              //  }
//    else {
//                                                                                //makes a new game class object.
//        NewGame *easygame = new NewGame(getDifficulty(),getPieceColor());       //Same for the easy difficulty setting.
//        DisplayBoard disp;
//        BoardState *currstate = new BoardState(getPieceColor());
//        scene = new QGraphicsScene(this);

//        disp.addBoardScene(scene);
//        disp.makeScene(currstate,scene);
//                                           //This might be a thread with a thread.run
//        ui->graphicsView->setScene(scene);
//        scene->setSceneRect(0,0,800,800);
//        //easygame.run();



}

void MainWindow::on_actionEasy_triggered()
{
    setDifficulty(0);
}

void MainWindow::on_actionOn_triggered()
{
    //audio comes later.
}

void MainWindow::on_actionOff_triggered()
{
    //audio comes later.
}

void MainWindow::on_actionHard_triggered()
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
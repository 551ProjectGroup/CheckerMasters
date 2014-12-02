#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;
    w.setDifficulty(0);
    w.setPieceColor(0);
    w.setTimer(false);
    w.show();

    return a.exec();
}

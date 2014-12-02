/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionExit;
    QAction *actionBlack_Magic;
    QAction *actionEasy;
    QAction *actionHard;
    QAction *actionOn;
    QAction *actionOff;
    QAction *actionBlack;
    QAction *actionRed;
    QAction *actionLoad_Game;
    QAction *actionSave_Game;
    QAction *actionForfeit;
    QAction *actionHard_2;
    QAction *actionOn_2;
    QAction *actionOff_2;
    QAction *action5_min;
    QAction *action10_min;
    QAction *action1_min;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLCDNumber *lcdNumber_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber_3;
    QLabel *label_3;
    QLCDNumber *lcdNumber_4;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuDifficulty;
    QMenu *menuAudio;
    QMenu *menuColour;
    QMenu *menuTimer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 720);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionBlack_Magic = new QAction(MainWindow);
        actionBlack_Magic->setObjectName(QStringLiteral("actionBlack_Magic"));
        actionEasy = new QAction(MainWindow);
        actionEasy->setObjectName(QStringLiteral("actionEasy"));
        actionHard = new QAction(MainWindow);
        actionHard->setObjectName(QStringLiteral("actionHard"));
        actionOn = new QAction(MainWindow);
        actionOn->setObjectName(QStringLiteral("actionOn"));
        actionOff = new QAction(MainWindow);
        actionOff->setObjectName(QStringLiteral("actionOff"));
        actionBlack = new QAction(MainWindow);
        actionBlack->setObjectName(QStringLiteral("actionBlack"));
        actionRed = new QAction(MainWindow);
        actionRed->setObjectName(QStringLiteral("actionRed"));
        actionLoad_Game = new QAction(MainWindow);
        actionLoad_Game->setObjectName(QStringLiteral("actionLoad_Game"));
        actionSave_Game = new QAction(MainWindow);
        actionSave_Game->setObjectName(QStringLiteral("actionSave_Game"));
        actionForfeit = new QAction(MainWindow);
        actionForfeit->setObjectName(QStringLiteral("actionForfeit"));
        actionHard_2 = new QAction(MainWindow);
        actionHard_2->setObjectName(QStringLiteral("actionHard_2"));
        actionOn_2 = new QAction(MainWindow);
        actionOn_2->setObjectName(QStringLiteral("actionOn_2"));
        actionOff_2 = new QAction(MainWindow);
        actionOff_2->setObjectName(QStringLiteral("actionOff_2"));
        action5_min = new QAction(MainWindow);
        action5_min->setObjectName(QStringLiteral("action5_min"));
        action10_min = new QAction(MainWindow);
        action10_min->setObjectName(QStringLiteral("action10_min"));
        action1_min = new QAction(MainWindow);
        action1_min->setObjectName(QStringLiteral("action1_min"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(11, 11, 640, 640));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(640, 640));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(660, 60, 231, 111));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 20, 231, 31));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(660, 210, 231, 111));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(660, 180, 231, 31));
        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(660, 360, 231, 111));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 330, 231, 31));
        lcdNumber_4 = new QLCDNumber(centralWidget);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(660, 510, 231, 111));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(660, 480, 231, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuDifficulty = new QMenu(menuOptions);
        menuDifficulty->setObjectName(QStringLiteral("menuDifficulty"));
        menuAudio = new QMenu(menuOptions);
        menuAudio->setObjectName(QStringLiteral("menuAudio"));
        menuColour = new QMenu(menuOptions);
        menuColour->setObjectName(QStringLiteral("menuColour"));
        menuTimer = new QMenu(menuOptions);
        menuTimer->setObjectName(QStringLiteral("menuTimer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew_Game);
        menuFile->addAction(actionSave_Game);
        menuFile->addAction(actionLoad_Game);
        menuFile->addAction(actionForfeit);
        menuFile->addAction(actionExit);
        menuOptions->addAction(menuDifficulty->menuAction());
        menuOptions->addAction(menuAudio->menuAction());
        menuOptions->addAction(menuColour->menuAction());
        menuOptions->addAction(menuTimer->menuAction());
        menuOptions->addSeparator();
        menuOptions->addAction(actionBlack_Magic);
        menuDifficulty->addAction(actionEasy);
        menuDifficulty->addAction(actionHard);
        menuDifficulty->addAction(actionHard_2);
        menuAudio->addAction(actionOn);
        menuAudio->addAction(actionOff);
        menuColour->addAction(actionBlack);
        menuColour->addAction(actionRed);
        menuTimer->addAction(action1_min);
        menuTimer->addAction(action5_min);
        menuTimer->addAction(action10_min);
        menuTimer->addAction(actionOn_2);
        menuTimer->addAction(actionOff_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CheckersMaster", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionBlack_Magic->setText(QApplication::translate("MainWindow", "Black Magic", 0));
        actionEasy->setText(QApplication::translate("MainWindow", "Easy", 0));
        actionHard->setText(QApplication::translate("MainWindow", "Normal", 0));
        actionOn->setText(QApplication::translate("MainWindow", "On", 0));
        actionOff->setText(QApplication::translate("MainWindow", "Off", 0));
        actionBlack->setText(QApplication::translate("MainWindow", "Black", 0));
        actionRed->setText(QApplication::translate("MainWindow", "Red", 0));
        actionLoad_Game->setText(QApplication::translate("MainWindow", "Load Game", 0));
        actionSave_Game->setText(QApplication::translate("MainWindow", "Save Game", 0));
        actionForfeit->setText(QApplication::translate("MainWindow", "Forfeit", 0));
        actionHard_2->setText(QApplication::translate("MainWindow", "Hard", 0));
        actionOn_2->setText(QApplication::translate("MainWindow", "15 min", 0));
        actionOff_2->setText(QApplication::translate("MainWindow", "Off", 0));
        action5_min->setText(QApplication::translate("MainWindow", "5 min", 0));
        action10_min->setText(QApplication::translate("MainWindow", "10 min", 0));
        action1_min->setText(QApplication::translate("MainWindow", "1 min", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Game Time Countdown</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Move Counter</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Computer Pieces</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">User Pieces</span></p></body></html>", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuDifficulty->setTitle(QApplication::translate("MainWindow", "Difficulty", 0));
        menuAudio->setTitle(QApplication::translate("MainWindow", "BGM", 0));
        menuColour->setTitle(QApplication::translate("MainWindow", "Color", 0));
        menuTimer->setTitle(QApplication::translate("MainWindow", "Timer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

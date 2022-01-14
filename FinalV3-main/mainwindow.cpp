#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <ctime>
#include "gamehandler.h"
#include <QPalette>
#include "difficulty.h"
#include "gamewindow.h"
#include "editwindow.h"
#include "highscore.h"
#include <QDesktopServices>
#include <QDir>

using namespace std;



GameHandler gamer;
int iSecret;
int colorTimer = 0;
QDir dirPath;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->setStyleSheet("background-color: rgb(25, 255, 155);");
    ui->statusbar->showMessage(dirPath.currentPath());

    //start timer for game
    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));
    timer->start(1000);

    //start timer to change background every minute
    colorChangeTimer = new QTimer(this);
    connect(colorChangeTimer, SIGNAL(timeout()),this, SLOT(colorTimerSlot()));
    colorChangeTimer->start(60000);

    //ui->lcdNumber->setPalette(QColor(0,0,255));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::colorTimerSlot()
{

    //if minute is even, background is blue
    if (colorTimer % 2 == 0) {
        ui->centralwidget->setStyleSheet("Background-color: rgb(110,216,255);");
    }
    //else background is green
    else {
        ui->centralwidget->setStyleSheet("Background-color: rgb(200,255,194);");
    }

    //incriment
    colorTimer++;
}

// set initials
void MainWindow::on_InitialsButton_clicked()
{
    srand(time(NULL));
    iSecret = rand() % 11 + 0;

    string init = this->ui->InitialsTextBox->toPlainText().toStdString();
    gamer.setInitials(init);

    QString qstr = QString::fromStdString(gamer.getInitials());
    this->ui->CurrentInitials->setText(qstr);

    gamer.hide(true, iSecret);
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}

//reset button
void MainWindow::cust_Slot() {

    this->ui->InitialsTextBox->clear();
    this->ui->CurrentInitials->clear();
    this->ui->WordIs->clear();
    gamer.setCurrentScore(0);
    gamer.clearBank();
    gamer.clearScore();
}

//progress to difficulty
void MainWindow::on_pushButton_clicked()
{
    //QString difficulty;

    Difficulty DifficultyWindow;
    DifficultyWindow.setModal(true);
    DifficultyWindow.exec();
}

//go to the edit window
void MainWindow::cust_Slot2(){
    editWindow editwindow;
    editwindow.setModal(true);
    editwindow.exec();
}

//go to highscores window
void MainWindow::cust_Slot3(){
    highScore highscore;
    highscore.setModal(true);
    highscore.exec();
}

//mail us
void MainWindow::cust_Slot4(){
    QDesktopServices::openUrl(QUrl("mailto:calebbrace@email.grcc.edu; calebmcgraw@email.grcc.edu; amanuelfufa@email.grcc.edu;?subject=Feedback", QUrl::TolerantMode));
}

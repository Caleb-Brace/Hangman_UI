#include "mainwindow.h"
#include "gamehandler.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <iostream>
#include <ctime>
#include <vector>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

QStringList strings;
QTimer timer;
QTimer colorChangeTimer;
QString quoteOutput;

using namespace std;


int main(int argc, char *argv[])
{

    srand(time(NULL));


    //attempt to open quotes file for splash
    QFile file("quotes.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            strings += stream.readLine();

        }
        short int quoteSelect = rand()% 11 + 0;
        quoteOutput = strings[quoteSelect];
    }
    file.close();

    QApplication a(argc, argv);
    MainWindow w;

    QPixmap SplashIMage(800,250);
    SplashIMage.fill(Qt::white);
    SplashIMage.fill(Qt::red);

    QSplashScreen HangmanSplashScreen(SplashIMage, Qt::WindowStaysOnTopHint);
    HangmanSplashScreen.show();

    HangmanSplashScreen.showMessage("Loading Hangman Program...\n"
    "Developers: Caleb M, Amanuel F, Caleb B\n"
    "Version 3.1\n" + quoteOutput + "\n _ \n" +
+ "| |\n" +
+ "| |__    __ _ _ __    __ _ _ __ ___    __ _ _ __ \n" +
+ "| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n" +
+ "| | | |  (_| | | | |  (_| | | | | | |  (_| | | | |\n" +
+ "|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n" +
+ "                      __/ |                      \n" +
+ "                     |___/ ");

    //HangmanSplashScreen.showMessage(quoteOutput);

    QTimer::singleShot(5000, &HangmanSplashScreen, SLOT(close()));
    QTimer::singleShot(5000, &w,SLOT(show()));

    return a.exec();
}


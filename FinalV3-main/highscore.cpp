#include "highscore.h"
#include "ui_highscore.h"
#include "gamehandler.h"
#include <string>
#include <iostream>
#include <QIODevice>
#include <QFile>
#include <QDir>

using namespace std;

highScore::highScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::highScore)
{
    ui->setupUi(this);

}

highScore::~highScore()
{
    delete ui;
}

//populate from the master score file "scores"
void highScore::on_scoreButton_clicked()
{
    QStringList scores;
    QFile file("Scores.txt");

            if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream stream(&file);
                while (!stream.atEnd()){
                    scores += stream.readLine();

                }
            }
            file.close();

            ui->scoreList->clear();
            ui->scoreList->addItems(scores);


}


void highScore::on_exitScore_clicked()
{
    this -> hide();
}

//get file and copy it into the scores directory
void highScore::on_locationButton_clicked()
{
    try {
        ui->scoreList->clear();

        QString qFileLocation;
        string sFileLocation;
        string correctedLocation = "";
        QStringList scores;

        qFileLocation = this->ui->fileLocationEdit->text();
        sFileLocation = qFileLocation.toStdString();

        for (char x : sFileLocation) {
            if (x == '\\') {
                correctedLocation.append("/");
            }
            else {
                correctedLocation += x;
            }
        }

        qFileLocation = QString::fromStdString(correctedLocation);
        QDir directory("");
        directory.setNameFilters(QStringList()<<"*.txt");
        QFile file(qFileLocation);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            while (!stream.atEnd()){
                scores += stream.readLine();
            }
        }
        file.close();
        QFile file2("UserScores.txt");
        if (file2.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream stream(&file2);
            for (int i = 0; i < scores.length(); i++) {
                stream << scores[i] << '\n';
            }
        }

        file2.close();

        this->ui->scoreList->addItems(directory.entryList());

    }  catch (exception e) {
    }
}

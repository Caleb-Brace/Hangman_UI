#include "difficulty.h"
#include "ui_difficulty.h"
#include <string>
#include "gamewindow.h"

GameHandler handler;

Difficulty::Difficulty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
}

Difficulty::~Difficulty()
{
    delete ui;
}

//sets difficulty of words
void Difficulty::on_StartGame_clicked()
{
    if (this->ui->EasyRadio->isChecked()) {
        GameWindow game("Easy");
        game.setModal(true);
        game.exec();
    }
    else if (this->ui->MediumRadio->isChecked()) {  // Radio button selections for set difficulty
        GameWindow game("Medium");
        game.setModal(true);
        game.exec();
    }
    else {
        GameWindow game("Hard");
        game.setModal(true);
        game.exec();
    }


    this->hide();   //Hide menu after selection has been chosen

}

#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include "gamehandler.h"
#include <QDialog>

namespace Ui {
class Difficulty;
}

class Difficulty : public QDialog
{
    Q_OBJECT

public:
    explicit Difficulty(QWidget *parent = nullptr);
    //explicit Difficulty(GameHandler);

    ~Difficulty();

private slots:


    void on_StartGame_clicked();

private:
    Ui::Difficulty *ui;
};

#endif // DIFFICULTY_H

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "gamehandler.h"
#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    explicit GameWindow(QString);
    ~GameWindow();

private slots:
    void on_pushButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H

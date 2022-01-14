#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>

namespace Ui {
class highScore;
}

class highScore : public QDialog
{
    Q_OBJECT

public:
    explicit highScore(QWidget *parent = nullptr);
    ~highScore();

private slots:
    void on_scoreButton_clicked();

    void on_exitScore_clicked();

    void on_locationButton_clicked();

private:
    Ui::highScore *ui;
};

#endif // HIGHSCORE_H

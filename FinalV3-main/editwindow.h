#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>

namespace Ui {
class editWindow;
}

class editWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editWindow(QWidget *parent = nullptr);
    ~editWindow();

private slots:
    void on_exitButton2_clicked();

    void on_popButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::editWindow *ui;
};

#endif // EDITWINDOW_H

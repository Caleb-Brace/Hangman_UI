#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include <iostream>
#include <QTimer>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;
    QTimer *colorChangeTimer;

public slots:
    //void MyTimerSlot();
    void colorTimerSlot();

private slots:
    void on_InitialsButton_clicked();

    void on_exitButton_clicked();

    //void on_GuessPushButton_clicked();

    void cust_Slot();

    void on_pushButton_clicked();

    void cust_Slot2();

    void cust_Slot3();

    void cust_Slot4();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

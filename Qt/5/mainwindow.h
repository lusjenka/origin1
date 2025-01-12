#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "Stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotTimerAlarm();

    void on_pB_Start_clicked();

    void on_pB_Circle_clicked();

    //void RcvSignalShowTime();

    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;
    QTimer* qTimer;
    int m,s,ms;
    int m_circle,s_circle,ms_circle;
    bool flag = true;
    int circle;

};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "Stopwatch.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m = 0;
    s = 0;
    ms = 0;
    m_circle = 0;
    s_circle = 0;
    ms_circle = 0;
    circle = 0;
    //ui->label->setText(QString::number(MainWindow::cur_time));
   // ui->label->setText(0);

    qTimer = new QTimer();

        connect(qTimer, &QTimer::timeout, this, &MainWindow::slotTimerAlarm);

      //  connect(qTimer, &Stopwatch::sig_SendCircle, this, &MainWindow::RcvSignal);
        //qTimer->start(1000);

    //connect(qTimer, &QTimer::timeout, this, &Foo::processOneThing);
      //  timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerAlarm()
{
   //ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));
   // ui->label->setText(QString::number(MainWindow::cur_time));
   // cur_time = cur_time + 0.1;
   //ui->label->setText("Время: " + QString::number(MainWindow::cur_time));
    ms = ms + 100;
    if(ms>=1000)
    {
        ms = 0;
        s++;
    }
    if(s>=60)
    {
        s = 0;
        m++;
    }
    ui->label_2->setText(QString::number(m) + " : ");
    ui->label_3->setText(QString::number(s));
    ui->label_4->setText(" : " + QString::number(ms));

    ms_circle = ms_circle + 100;
    if(ms_circle>=1000)
    {
        ms_circle = 0;
        s_circle++;
    }
    if(s_circle>=60)
    {
        s_circle = 0;
        m_circle++;
    }
    ui->label_6->setText(QString::number(m_circle) + " : ");
    ui->label_7->setText(QString::number(s_circle));
    ui->label_8->setText(" : " + QString::number(ms_circle));
}


void MainWindow::on_pB_Start_clicked()
{
    flag = !flag;
    if(flag)
    {
     ui->pB_Start->setText("Старт");
     qTimer->stop();
    }
    else
    {
      ui->pB_Start->setText("Стоп");
      qTimer->start(100);

       //while(ui->pB_Start->text() != "Старт")
       //{
      //cur_time = cur_time + 0.1;
       //}
    }

}


void MainWindow::on_pB_Circle_clicked()
{
     if(ui->pB_Start->text() == "Стоп")
    {

    circle++;

    QString m_ = ui->label_6->text();
    QString s_ = ui->label_7->text();
    QString ms_ = ui->label_8->text();

    ui->textBrowser->append(QString("Круг № %1 Время:  %2  %3  %4 ").arg(circle).arg(m_).arg(s_).arg(ms_));
   // emit qTimer->sig_SendCircle(m_,s_,ms_);
    //ui->textBrowser->append("Круг №" + circle + " : " + m_ + " : " + s_+ " : " + ms_);
    m_circle = 0;
    s_circle = 0;
    ms_circle = 0;

     }

}

/*void MainWindow::RcvSignal(QString m_, QString s_, QString ms_)
{
  //  m_ = m;
 ui->textBrowser->append();
}*/


void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
    qTimer->stop();
    m = 0;
    s = 0;
    ms = 0;
    circle = 0;
    ui->pB_Start->setText("Старт");
    m_circle = 0;
    s_circle = 0;
    ms_circle = 0;

    ui->label_2->setText(QString::number(m) + " : ");
    ui->label_3->setText(QString::number(s));
    ui->label_4->setText(" : " + QString::number(ms));
    ui->label_6->setText(QString::number(m_circle) + " : ");
    ui->label_7->setText(QString::number(s_circle));
    ui->label_8->setText(" : " + QString::number(ms_circle));

}


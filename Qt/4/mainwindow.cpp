#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rBut_1->setText("Радиокнопка 1");
    ui->rBut_2->setText("Радиокнопка 2");
    ui->pBut_1->setText("Кнопочка");
    for(int i = 1; i <= 10; ++i)
        {
        //auto item = new QComboBox(QString("Строка %1 ").arg(i));
            //ui->
            //ui->cBox->addItem(item);
            //ui->comboBox->addItem("Строка " + QString::number(i));
        ui->cBox->addItem(QString("Строка %1").arg(i) );
        }
    ui->pBut_1->setCheckable(true);
    ui->prBar->setMinimum(0);
    ui->prBar->setMaximum(10);
    ui->prBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rBut_1_clicked()
{

}


void MainWindow::on_pBut_1_toggled(bool checked)
{

    if (ui->prBar->value() < ui->prBar->maximum())
        {
            ui->prBar->setValue(ui->prBar->value() + 1);
        }
        else
        {
            ui->prBar->setValue(0);
        }

}


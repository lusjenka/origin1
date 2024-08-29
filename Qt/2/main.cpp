#include "mainwindow.h"
#include <QApplication>
#include <QDnsLookup>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("testBD"); //экземпляр класса QSqlDatabase (обрабатывает подключение к базе данных)

    QDnsLookup* dns; // экземпляр класса QDnsLookup (представляет собой поиск в DNS)

    MainWindow w;
    w.show();
    return a.exec();



}

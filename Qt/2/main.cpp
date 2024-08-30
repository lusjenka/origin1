#include <QCoreApplication>
#include <QDnsLookup>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("testBD"); //экземпляр класса QSqlDatabase (обрабатывает подключение к базе данных)
    QDnsLookup* dns; // экземпляр класса QDnsLookup (представляет собой поиск в DNS)

    return a.exec();
}

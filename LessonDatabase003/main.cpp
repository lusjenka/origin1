
#include "ClientsDB.h"


int main(int argc, char** argv)
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    setvbuf(stdout, nullptr, _IOFBF, 1000);
    try
    {
        std::string connection_string = "host=localhost port=5432 dbname=clients user=postgres password=479Hgf43";
        ClientsDB db(connection_string);
        db.dropTables();
        db.createTables();

        db.addClient("Иван", "Иванов", "ivanov@mail.ru", "89156468745");
        db.show();


        db.addClient("Петр", "Петров", "petrov@mail.ru", "");
        db.show();

        db.addClient("Ксения", "Сидорова", "sidorova@mail.ru", "89776334565");
        db.show();

        try
        {
            db.addPhone("Иван", "89776224841");
            db.show();

            db.addPhone("Ксения", "89155662771");
            db.show();
        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception happened: " << ex.what() << std::endl;
        }

        try
        {
            db.updateClient("ivanov@mail.ru", "Иван", "Иванченко", "new_ivanov@mail.ru"); //меняем фамилию Иванова
            db.show();

            db.updateClient("petrov@mail.ru", "Петр", "Петренко", "new_petrov@mail.ru");//меняем фамилию Петрова
            db.show();
        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception happened: " << ex.what() << std::endl;
        }

        db.removePhone("new_ivanov@mail.ru", "+79115464033");//удаляем телефон Иванченко

        db.removeClient("new_ivanov@mail.ru");//удаляем Иванченко

        std::vector<Client> foundClients = db.findClients("Иван");
        for (const auto& [name, surname, email, phones] : foundClients)
        {
            std::cout << "Найден клиент: " << name << " " << surname << " " << email << " " << std::endl;
            
        }
        db.show();

       

    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception happened: " << ex.what() << std::endl;
    }

    return 0;
};

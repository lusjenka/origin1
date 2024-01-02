// month.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

enum class months
{
    январь = 1,
    февраль,
    март,
    апрель,
    май,
    июнь,
    июль,
    август,
    сентябрь,
    октябрь,
    ноябрь,
    декабрь
};

int main()
{
    system("chcp 1251>nul");
    std::cout << "Введите номер месяца : \n";
    int x;
    std::cin >> x;
    if (x < 0 || x > 12)
    {
        std::cout << "Некорректное число введено \n";
    }
   if (x==0)
   {
       return 0;
   }
   while (x != 0) {
           
           switch (x)

           {

           case static_cast<int>(months::январь):

               std::cout << "Январь" << std::endl;

               break;

           case static_cast<int>(months::февраль):

               std::cout << "Февраль" << std::endl;

               break;

           case static_cast<int>(months::март):

               std::cout << "Март" << std::endl;

               break;

           case static_cast<int>(months::апрель):

               std::cout << "Апрель" << std::endl;

               break;

           case static_cast<int>(months::май):

               std::cout << "Май" << std::endl;

               break;

           case static_cast<int>(months::июнь):

               std::cout << "Июнь" << std::endl;

               break;
           case static_cast<int>(months::июль):

               std::cout << "Июль" << std::endl;

               break;
           case static_cast<int>(months::август):

               std::cout << "Август" << std::endl;

               break;
           case static_cast<int>(months::сентябрь):

               std::cout << "Сентябрь" << std::endl;

               break;
           case static_cast<int>(months::октябрь):

               std::cout << "Октябрь" << std::endl;

               break;
           case static_cast<int>(months::ноябрь):

               std::cout << "Ноябрь" << std::endl;

               break;
           case static_cast<int>(months::декабрь):

               std::cout << "Декабрь" << std::endl;

               break;


           }
           std::cout << "Введите номер месяца : \n";
           std::cin >> x;
           if (x < 0 || x > 12)
           {
               std::cout << "Некорректное число \n";
           }
             
   }

}



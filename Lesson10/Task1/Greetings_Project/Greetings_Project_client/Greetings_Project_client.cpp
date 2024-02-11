#include <iostream>
#include "Greetings_project.h"


int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введите имя: ";
    std::string name;
    std::cin >> name;
    Greeter greeter;
    greeter.greet(name);
  

}


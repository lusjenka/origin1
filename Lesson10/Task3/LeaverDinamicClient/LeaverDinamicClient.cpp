#include <iostream>
#include "LeaverDinamic.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введите имя: \n";
    std::string name;
    std::cin >> name;
    Leaver d;
    d.leave(name);
}
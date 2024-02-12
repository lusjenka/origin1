// LeaverDinamicClient.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LeaverDinamic.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введите имя: \n";
    char name = 'f';
    std::cin >> name;
    Leaver d;
    d.leave(name);
}

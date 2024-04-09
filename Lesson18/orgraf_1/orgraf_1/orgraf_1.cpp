﻿// orgraf_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[9][9] = {
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,1,0,1,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0}
    };
    int count;
    for (int i = 0; i < 9; i++)
    {
        count = 0;
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 1)
            {
                if (count == 0)
                {
                    std::cout << i + 1 << ": ";
                }
                else { std::cout << " "; }
                std::cout << j + 1;
                count++;
            }
        }
        if (count == 0) {
            std::cout << i + 1 << ": " << "нет";
        }
        std::cout << "\n";
    }
    return 0;

}

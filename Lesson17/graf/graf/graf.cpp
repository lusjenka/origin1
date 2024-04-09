// graf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int arr[7][7] = {
        {0,0,1,0,0,1,1},
        {0,0,1,1,0,0,1},
        {1,1,0,0,0,0,1},
        {0,1,0,0,1,0,0},
        {0,0,0,1,0,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,0,1,1,0}
    };
    int visited[] = { 0,0,0,0,0,0,0 };
    visited[0] = 1;
    int vertex_order[7];
    vertex_order[0] = 1;
    int count = 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr[i][j] == 1)
            {
                if (visited[j] != 1) {
                    visited[j] = 1;
                    vertex_order[count] = j + 1;
                    i = j;
                    j = -1;
                    count++;
                }
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        std::cout << vertex_order[i] << " ";
    }

    return 0;

}
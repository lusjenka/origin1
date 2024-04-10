// orgraf_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    int visited[] = { 0,0,0,0,0,0,0,0,0 };// посещенные вершины
    int vis[] = { 0,0,0,0,0,0,0,0,0 };//с какой начать (если нет вершины, в которую ничего не входит, то обход начинаем с вершины 1) 
    int vertex_order[9] = { 0,0,0,0,0,0,0,0,0 };//порядок обхода
    int count = 0;
    int index = 0;
    int* ptr = vertex_order;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 1)
            {
                vis[j] += 1;
            }
        }
    }
    for (int i = 0; i < 9; i++)//показывает сколько исходящих граней у вершины
    {
        //std::cout << vis[i] << " ";
        if (vis[i] == 0) {
            vertex_order[0] = i + 1;
            visited[i] = 1;
            break;
        }
    }
    if (vertex_order[0] == 0)
    {
        vertex_order[0] = 1;
        visited[0] = 1;
    }
    for (int i = vertex_order[index] - 1; i < 9; i++)
    {
        count = 0;
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 1)
            {
                if (visited[j] == 0)
                {
                    count = 0;
                    visited[j] = 1;
                    index++;
                    vertex_order[index] = j + 1;
                    ptr++;
                    i = j;
                    j = -1;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                count++;
             }
            if (count == 8 && arr[i][j+1] != 1) {
                ptr--;
                i = *ptr;
                i--;
                j = 0;
                count = 0;
            }
            if (index == 8) {
                break;
            }
        }
    }
    //std::cout << "\n";
    std::cout << "Топологический порядок вершин: ";
    for (int i = 0; i < 9; i++)
    {
        std::cout << vertex_order[i] << " ";
    }

    return 0;

}

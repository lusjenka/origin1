#include <iostream>
#include <list>
#include "my_list.h"
using namespace std;

const int N = 11;




void insert_to_hash(List hash[], int value) //принимает массив и значение, которое надо положить в массив
    {
    int backet = value % N;// "случайное" число для нумерации ячеек
    hash[backet].insert_back(value);//для ячейки под "случайным" номером вызывается функция вставки данных
    }


int find_in_hash(List hash[], int value)
{
    int backet = value % N;// "случайное" число для нумерации ячеек
    if (hash[backet].find(value))
    {
        return backet;
    }
    else
    {
        return -1;
    }
}

void print_hash(List hash[])
{
    for (size_t i = 0; i < N; i++)
    {
        if (!hash[i].is_empty())
        {
            cout << i << ": ";
            hash[i].print();
        }
        cout << endl;
    }
}
int main()
{
    List hash[N];// массив объектов класса List
    for (size_t i = 0; i < 10; i++)
    {
        insert_to_hash(hash, rand() % 100);
    }
    print_hash(hash);

    return 0;

}
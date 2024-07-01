#include <iostream>
#include <vector>
#include <algorithm>
#include <future>


void multiplyVec(int& MultiplierVec)
{
    MultiplierVec *= 3;
}

template <typename Iterator>
void parallelForEachAsyncRecursive(Iterator begin, Iterator end)
{
    auto currSize = std::distance(begin, end);//помогает найти расстояние между двумя итераторами.
    //std::cout << "currSize: " << currSize << std::endl;
    if (currSize <= 3)
    {
        std::for_each(begin, end, multiplyVec);
    }
    else
    {
        auto mid = begin;
        std::advance(mid, currSize / 2);// Эквивалентно mid = mid + currSize / 2;
        auto ftRes = std::async(parallelForEachAsyncRecursive<Iterator>, begin, mid);//используется для асинхронного выполнения функции или вызываемого объекта и получения объекта future, представляющего результат вычислений. 
        parallelForEachAsyncRecursive(mid, end);//рекурсивный вызов

        ftRes.get();
    }
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Before: ";
    for (int i : vec)//вывод вектора
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    parallelForEachAsyncRecursive(vec.begin(), vec.end());//передаем итераторы на начло и конец вектора

    std::cout << "\nAfter: ";
    for (int i : vec)//вывод вектора
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
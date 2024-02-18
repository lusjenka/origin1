#include <iostream>



int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введи точку отсчета (ТО): \n";
    const int size = 9;
    int to;
    std::cin >> to;
    int arr[size] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int left = 0;
    int right = size - 1;

   while (left < right) {
        int middle = (left + right) / 2;
       if (arr[middle] >= to) {
            right = middle - 1;
        }
        else if (arr[middle] < to) {
            left = middle + 1;
        }
    }
   if (arr[size-1] >= to) {
        std::cout << "\nКоличество элементов, которые больше чем ТО: " << (size-1)-left;
    }
    else std::cout << "\nНет элементов, которые больше чем ТО.";

    return 0;
}

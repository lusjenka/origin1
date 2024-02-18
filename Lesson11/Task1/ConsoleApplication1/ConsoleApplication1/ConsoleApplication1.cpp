#include <iostream>

void binSearch(int* arr, int size, int to) {
    int left = 0;
    int right = size - 1;
    int middle = 0;
     while (left < right) {

        middle = (left + right) / 2;
        if (to < arr[0]) {
            std::cout << "\nКоличество элементов, которые больше чем ТО: " << size;
            break;
       }
        if (to >= arr[size-1]) {
            std::cout << "\nНет элементов, которые больше чем ТО.";
            break;
        }
       if (arr[middle] > to) {
            right = middle - 1;
        }
        else if (arr[middle] <= to) {
            left = middle + 1;
        }
    }
   
     if (arr[size - 1] > to && arr[0]<=to) {
         if (arr[middle] > to) { std::cout << "\nКоличество элементов, которые больше чем ТО: " << size - middle; }
         else if (arr[middle] == to || arr[middle] < to) { std::cout << "\nКоличество элементов, которые больше чем ТО: " << size - middle - 1; }
        
     }
     
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введи точку отсчета (ТО): \n";
    const int size = 9;
    int to;
    std::cin >> to;
    int arr[size] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    binSearch(arr, size, to);

    return 0;
}

#include <iostream>
using namespace std;

void qsortRecursive(int* mas, int size) {

    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {

        while (mas[i] < mid) {
            i++;
        }

        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {

        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
 
        qsortRecursive(&mas[i], size - i);
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int sizeA = 10, sizeB = 15, sizeC = 18;
    int A[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int B[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int C[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    cout << "Исходный массив: ";
    for (int i = 0; i < sizeA; i++) {
        cout << A[i] << " ";
    }
    cout << "\nОтсортированный массив: ";
    qsortRecursive(A, sizeA);
    for (int i = 0; i < sizeA; i++)
        cout << A[i] << " ";

    cout << "\n\nИсходный массив: ";
    for (int i = 0; i < sizeB; i++) {
        cout << B[i] << " ";
    }
    cout << "\nОтсортированный массив: ";
    qsortRecursive(B, sizeB);
    for (int i = 0; i < sizeB; i++)
        cout << B[i] << " ";

    cout << "\n\nИсходный массив: ";
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << "\nОтсортированный массив: ";
    qsortRecursive(C, sizeC);
    for (int i = 0; i < sizeC; i++)
        cout << C[i] << " ";
    return 0;
}
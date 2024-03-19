#include <iostream>
using namespace std;


void Merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2;  
    start = first;                
    final = middle + 1;           
    for (j = first; j <= last; j++)  
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
   
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};

void MergeSort(int* A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);  
        MergeSort(A, (first + last) / 2 + 1, last);  
        Merge(A, first, last);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int sizeA = 10, sizeB = 15, sizeC = 18;
    int A[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int B[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int C[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    cout << "Исходный массив: ";
    for (int i = 0; i < sizeA; i++) {
        cout << A[i] << " ";
    }
    cout << "\nОтсортированный массив: ";
    MergeSort(A, 0, sizeA-1); 
    for (int i = 0; i < sizeA; i++)
        cout << A[i] << " ";
   
    cout << "\n\nИсходный массив: ";
    for (int i = 0; i < sizeB; i++) {
        cout << B[i] << " ";
    }
    cout << "\nОтсортированный массив: ";
    MergeSort(B, 0, sizeB - 1);
    for (int i = 0; i < sizeB; i++)
        cout << B[i] << " ";

    cout << "\n\nИсходный массив: ";
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << "\nОтсортированный массив: ";
    MergeSort(C, 0, sizeC - 1);
    for (int i = 0; i < sizeC; i++)
        cout << C[i] << " ";
    return 0;
}
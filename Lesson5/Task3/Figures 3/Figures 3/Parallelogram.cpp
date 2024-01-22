#include "Parallelogram.h"

    Parallelogram::Parallelogram() {
        name = "Параллелограмм: ";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
    }

    Parallelogram::Parallelogram(int a, int b, int A, int D) {
        this->a = a = c;
        this->b = b = d;
        this->A = A = C;
        this->B = B = D;
    }
    void Parallelogram::bool_check()  {
        if (A == C && B == D && a == c && b == d)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

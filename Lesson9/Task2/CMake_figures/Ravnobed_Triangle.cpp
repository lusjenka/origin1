#include "Ravnobed_Triangle.h"

Ravnobed_Triangle::Ravnobed_Triangle(int a, int c, int A, int B) {
    this->a = a = b;
    this->c = c;
    this->A = A = C;
    this->B = B;
}

Ravnobed_Triangle::Ravnobed_Triangle() {
        name = "Равнобедренный треугольник: ";
        a = 40;
        b = 40;
        c = 30;
        A = 55;
        C = 55;
        B = 70;
    }
    void Ravnobed_Triangle::bool_check()  {
        if (a == b && A == C)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

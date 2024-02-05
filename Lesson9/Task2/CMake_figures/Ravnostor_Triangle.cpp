#include "Ravnostor_Triangle.h"


Ravnostor_Triangle::Ravnostor_Triangle(int a) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = 60;
        this->B = 60;
        this->C = 60;

    }

    Ravnostor_Triangle::Ravnostor_Triangle() {
        name = "Равносторонний треугольник: ";
        a = 40;
        b = 40;
        c = 40;
        A = 60;
        B = 60;
        C = 60;
    }
    void Ravnostor_Triangle::bool_check()  {
        if (a == b && b == c && A == B && B == C)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

#include "Square.h"

    square::square() {
    name = "Квадрат: ";
    a = c = b = d = 20;
    A = C = B = D = 90;
}

    square::square(int a) {
        this->a = a = c = b;

    }
    void square::bool_check()  {
        if (A == C && C == B && B == D && D == 90 && a == c && c == b && b == d)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

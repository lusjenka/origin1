#include "Romb.h"

    Romb::Romb() {
    name = "����: ";
    a = c = b = d = 30;
    A = C = 60;
    B = D = 75;
}

    Romb::Romb(int a, int A, int B) {
        this->a = a = c = b;
        this->A = A = C;
        this->B = B = D;
    }
    void Romb::bool_check()  {
        if (a == b && b == c && c == d && A == C && B == D)
        {
            std::cout << "\n���������� ";
        }
        else { std::cout << "\n������������ "; }
    };

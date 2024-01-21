#include "hRomb.h"

    void Romb::bool_check()  {
        if (a == b && b == c && c == d && A == C && B == D)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

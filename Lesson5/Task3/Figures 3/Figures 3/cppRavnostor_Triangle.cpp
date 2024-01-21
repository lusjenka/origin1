#include "hRavnostor_Triangle.h"


    void Ravnostor_Triangle::bool_check()  {
        if (a == b && b == c && A == B && B == C)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

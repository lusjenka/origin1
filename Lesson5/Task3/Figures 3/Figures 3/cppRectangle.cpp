#include "hRectangle.h"


    void Rectangle::bool_check() {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

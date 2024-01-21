#include <iostream>
#include "hQuadrangle.h"
#pragma once

    void Quadrangle::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count;
        std::cout << "\nСтороны: " << a << ", " << b << ", " << c << ", " << d << "\nУглы: " << A << ", " << B << ", " << C << ", " << D << std::endl << std::endl;
    };

    void Quadrangle::bool_check() {
        if (A + B + C + D == 360 && sides_count == 4)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

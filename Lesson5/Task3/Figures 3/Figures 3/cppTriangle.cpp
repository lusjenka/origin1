#include <iostream>
#include "hTriangle.h"
#pragma once

    void Triangle::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count;
        std::cout << "\nСтороны: " << a << ", " << b << ", " << c << "\nУглы: " << A << ", " << B << ", " << C << std::endl << std::endl;
    };

    void Triangle::bool_check() {
        if (A + B + C == 180)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };

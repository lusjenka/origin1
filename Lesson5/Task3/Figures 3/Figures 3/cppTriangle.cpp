#include <iostream>
#include "hTriangle.h"
#pragma once

    void Triangle::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\n���������� ������: " << sides_count;
        std::cout << "\n�������: " << a << ", " << b << ", " << c << "\n����: " << A << ", " << B << ", " << C << std::endl << std::endl;
    };

    void Triangle::bool_check() {
        if (A + B + C == 180)
        {
            std::cout << "\n���������� ";
        }
        else { std::cout << "\n������������ "; }
    };

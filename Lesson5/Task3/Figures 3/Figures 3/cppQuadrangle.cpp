#include <iostream>
#include "hQuadrangle.h"
#pragma once

    void Quadrangle::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\n���������� ������: " << sides_count;
        std::cout << "\n�������: " << a << ", " << b << ", " << c << ", " << d << "\n����: " << A << ", " << B << ", " << C << ", " << D << std::endl << std::endl;
    };

    void Quadrangle::bool_check() {
        if (A + B + C + D == 360 && sides_count == 4)
        {
            std::cout << "\n���������� ";
        }
        else { std::cout << "\n������������ "; }
    };

#include <iostream>
#include "hFigure.h"
#pragma once

   void Figure::get_sides_count() {
        std::cout << name << std::endl;
    }

   void Figure::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\nКоличество сторон: " << sides_count << std::endl << std::endl;
    };

   void Figure::bool_check() {
        if (sides_count == 0)
        {
            std::cout << "\nПравильная ";
        }
        else { std::cout << "\nНеправильная "; }
    };


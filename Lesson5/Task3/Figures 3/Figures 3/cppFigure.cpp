#include <iostream>
#include "hFigure.h"
#pragma once

class Figure
{
protected:
    int a, b, c, d, A, B, C, D;


public:
    std::string name;
    int sides_count;
protected:
    Figure(std::string name, int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

    Figure::Figure()
    {
        name = "������: ";
        sides_count = 0;
    }
    Figure::get_sides_count() {
        std::cout << name << std::endl;
    }

    Figure::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\n���������� ������: " << sides_count << std::endl << std::endl;
    };

        Figure::bool_check() {
        if (sides_count == 0)
        {
            std::cout << "\n���������� ";
        }
        else { std::cout << "\n������������ "; }
    };
};
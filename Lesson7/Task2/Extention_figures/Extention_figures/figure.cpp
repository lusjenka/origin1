#include "figure.h"
#include <iostream>


Figure::Figure(std::string name, int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

Figure::Figure()
    {
        name = "������";
        sides_count = 0;
    }

    void  Figure::get_sides_count() {
        std::cout << name << std::endl;
    }

    void  Figure::get_figure() {
        if (sides_count == 4) {
            std::cout << name << "\n�������: " << a << ", " << b << ", " << c << ", " << d << "\n����: " << A << ", " << B << ", " << C << ", " << D << std::endl << std::endl;
        }
        else if (sides_count == 3) { std::cout << name << "\n�������: " << a << ", " << b << ", " << c << "\n����: " << A << ", " << B << ", " << C << std::endl << std::endl; }
    }

        void  Figure::print_info() {
        this->Figure::get_figure();
    };

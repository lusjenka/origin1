#include <iostream>
#include "Figure.h"


Figure::Figure(std::string name, int sides_count)
    {
        this->name = name;
        this->sides_count = sides_count;
    }

Figure::Figure()
    {
        name = "������: ";
        sides_count = 0;
    }
   void Figure::get_sides_count() {
        std::cout << name << std::endl;
    }

   void Figure::print_info() {
        std::cout << name;
        bool_check();
        std::cout << "\n���������� ������: " << sides_count << std::endl << std::endl;
    };

   void Figure::bool_check() {
        if (sides_count == 0)
        {
            std::cout << "\n���������� ";
        }
        else { std::cout << "\n������������ "; }
    };


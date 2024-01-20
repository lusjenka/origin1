#include <iostream>
#include "h.h"
#pragma once

void plus(int x1, int x2) {
    std::cout << x1 << " + " << x2 << " = " << x1 + x2 << std::endl;
};
void minus(int x1, int x2) {
    std::cout << x1 << " - " << x2 << " = " << x1 - x2 << std::endl;
};
void multiplication(int x1, int x2) {
    std::cout << x1 * x2 << std::endl;
};
void division(int x1, int x2) {
    if (x2 != 0) { std::cout << x1 << " / " << x2 << " = " << static_cast<double>(x1) / static_cast<double>(x2) << std::endl; }
    else std::cout << "Делить на ноль нельзя!" << std::endl;
};
void degree(int x1, int x2) {
    int num = 0;
    int z = x1;
    if (x2 == 0) { std::cout << 0 << std::endl; }
    else if (x2 == 1) { std::cout << x1 << std::endl; }
    else {
        for (int i = 2; i <= x2; i++) {
            z *= x1;
            num = z;
        }
        std::cout << "Число " << x1 << " в степени " << x2 << " = " << num << std::endl;
    }
};
void foo(int x, int x1, int x2) {
    switch (x) {
    case 1: plus(x1, x2);
        break;
    case 2: minus(x1, x2);
        break;
    case 3: multiplication(x1, x2);
        break;
    case 4: division(x1, x2);
        break;
    case 5: degree(x1, x2);
        break;
    }
};
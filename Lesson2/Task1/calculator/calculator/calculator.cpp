#include <iostream>

class Calc
    {
    public:
    double num1;
    double num2;

    double add (double n1, double n2) { 
        double add = n1 + n2;
        return add;
    }
    double multiply (double n1, double n2) {
        double multiply = n1 * n2;
        return multiply;
    }
    double subtract_1_2 (double n1, double n2) {
        double subtract_1_2 = n1 - n2;
        return subtract_1_2;
    }
    double subtract_2_1(double n1, double n2) {
        double subtract_2_1 = n2 - n1;
        return subtract_2_1;
    }
    double divide_1_2(double n1, double n2) {
        double divide_1_2 = n1 / n2;
        return divide_1_2;
    }
    double divide_2_1(double n1, double n2) {
        double divide_2_1 = n2 / n1;
        return divide_2_1;
    }
    /*bool set_num1(double num1) {
        if (num1 !=0) this->num1 = num1;
    }
    bool set_num2(double num2) {
        if (num2 != 0) this->num2 = num2;
    }*/
        };

int main()
{
    setlocale(LC_ALL, "rus");
    Calc calc;
    while (true) {
        std::cout << "Введите num1: ";
        std::cin >> calc.num1;
        std::cout << "Введите num2: ";
        std::cin >> calc.num2;
        if (calc.num1 == 0 || calc.num2 == 0) {
            std::cout << "Значения введены некорректно. Введите заново\n";
            continue;
        }
        std::cout << "num1 + num2 = " << calc.add(calc.num1, calc.num2) << "\n";
        std::cout << "num1 * num2 = " << calc.multiply(calc.num1, calc.num2) << "\n";
        std::cout << "num1 - num2 = " << calc.subtract_1_2(calc.num1, calc.num2) << "\n";
        std::cout << "num2 - num1 = " << calc.subtract_2_1(calc.num1, calc.num2) << "\n";
        std::cout << "num1 / num2 = " << calc.divide_1_2(calc.num1, calc.num2) << "\n";
        std::cout << "num2 / num1 = " << calc.divide_2_1(calc.num1, calc.num2) << "\n";
    };
    return 0;
}



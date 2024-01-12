#include <iostream>

class Calc
    {
    private:
    double num1;
    double num2;

    public:
       Calc() {
            num1 = 1;
            num2 = 1;
        }

   bool set_num1(double num1) {
       if (num1 != 0) {
           this->num1 = num1;
           return true;
       }else return false;
   }
   bool set_num2(double num2) {
       if (num2 != 0) {
           this->num2 = num2;
           return true;
       }
       else return false;
        
   }
   double add () { 
        double add = num1 + num2;
        return add;
    }
    double multiply () {
        double multiply = num1 * num2;
        return multiply;
    }
    double subtract_1_2 () {
        double subtract_1_2 = num1 - num2;
        return subtract_1_2;
    }
    double subtract_2_1() {
        double subtract_2_1 = num2 - num1;
        return subtract_2_1;
    }
    double divide_1_2() {
        double divide_1_2 = num1 / num2;
        return divide_1_2;
    }
    double divide_2_1() {
        double divide_2_1 = num2 / num1;
        return divide_2_1;
    }
   
        };

int main()
{
    setlocale(LC_ALL, "rus");
    Calc calc;
    while (true) {
        double num1, num2;
        std::cout << "Введите num1: ";
        std::cin >> num1;
        std::cout << "Введите num2: ";
        std::cin >> num2;

        if (calc.set_num1(num1)==true && calc.set_num2(num2) == true) {

            std::cout << "num1 + num2 = " << calc.add() << "\n";
            std::cout << "num1 * num2 = " << calc.multiply() << "\n";
            std::cout << "num1 - num2 = " << calc.subtract_1_2() << "\n";
            std::cout << "num2 - num1 = " << calc.subtract_2_1() << "\n";
            std::cout << "num1 / num2 = " << calc.divide_1_2() << "\n";
            std::cout << "num2 / num1 = " << calc.divide_2_1() << "\n";
        }
        else {
            std::cout << "Значения введены некорректно. Введите заново\n";
            continue;
        };
    };
    return 0;
}



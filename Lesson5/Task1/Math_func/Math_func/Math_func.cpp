#include <iostream>
#include "h.h"


int main()

{
    setlocale(LC_ALL, "rus");
    int x1, x2, out;
    do {
        std::cout << "Введите первое число: \n";
        std::cin >> x1;
        std::cout << "Введите второе число: \n";
        std::cin >> x2;
        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): \n";
        std::cin >> out;
        foo(out, x1, x2);
    } while (true);

}



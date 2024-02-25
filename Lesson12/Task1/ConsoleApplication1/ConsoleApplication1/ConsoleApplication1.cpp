#include <iostream>

int fib(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }
    if (n > 3) {
        return fib(n - 2) + fib(n - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Номер числа Фибоначчи: \n";
    int n;
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Nevernoe chislo. ";
        return 0;
    }else
    std::cout << fib(n);
}




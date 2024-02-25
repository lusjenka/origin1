#include <iostream>

const int maxN = 100001;
int fib(int n) {
    static int knownF[maxN];
    if (knownF[n] != 0) return knownF[n];
    int t = n;
    if (n == 1) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }
    if (n > 3) {
        t = fib(n - 2) 
            + fib(n - 1);//почему проскакивает эту строку и записывает промежуточные результаты в массив?
        return knownF[n] = t;
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
    }
    else
        std::cout << fib(n);
    
}

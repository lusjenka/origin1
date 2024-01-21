#include <iostream>
#include "hCounter.h"


void foo(Counter& p) {
    do
    {
        std::cout << "Введите команду('+', '-', '=' или 'x'): ";
        char x;
        std::cin >> x;
        switch (x) {
        case '+': p.plus();
            break;
        case '-': p.minus();
            break;
        case '=': std::cout << "Текущее значение счетчика: " << p.get_priv_field() << "\n";
            break;
        case 'x': std::cout << "До свидания!" << "\n";
            break;
        }

        if (x == 'x' || x == 'х') { break; }
    } while (true);

}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    std::cout << "Вы хотите указать начальное значение счётчика? Введите +,сели да: ";
    char ques;
    std::cin >> ques;
    if (ques == '+') {
        std::cout << "\nВведите начальное значение счётчика: ";
        int begin_count;
        std::cin >> begin_count;
        Counter counter(begin_count);
        foo(counter);
    }
    else {
        Counter counter;
        foo(counter);

    }
    return 0;
}





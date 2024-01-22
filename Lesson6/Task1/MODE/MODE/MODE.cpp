#include <iostream>
using namespace std;

#define MODE 4
void foo(int num1, int num2) {

    cout << num1 + num2;

}

int main(int argc, char** argv)

{
    setlocale(LC_ALL, "rus");

#if !defined MODE

    std::cout << "Не определен" << std::endl;

#endif

#if defined MODE

#if (MODE==0)

    std::cout << "Работа в режиме тренировки" << std::endl;

#elif (MODE==1)

    std::cout << "Работа в боевом режиме" << std::endl;

    int num1; int num2;

    cout << "num1: " << endl;

    cin >> num1;

    cout << "num2: " << endl;

    cin >> num2;

    foo(num1, num2);

#elif (MODE!=1 && MODE!=0)

    std::cout << "Неизвестный режим. Завершение работы" << std::endl;

#endif 
#endif
}
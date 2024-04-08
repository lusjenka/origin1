// task1_L16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


int main()
{
    setlocale(LC_ALL, "rus");
    
    std::string s;
    while (1)
    {
        int sum = 0;
        std::cout << "Введите строку: ";
        std::cin >> s;
        if (s != "exit")
        {
            int k = 0;
            for (int i = 0; i < s.size(); i++) {
                sum += s[i];
            }
            std::cout << "Наивный хэш строки " << s << " = " << sum << "\n";
        }
        else
        {
            break;
        }
    }
    
    return 0;
}

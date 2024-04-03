// task1_L16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


int main()
{
    setlocale(LC_ALL, "rus");
    int sum;
    std::string s;
    while (true)
    {
        int sum = 0;
        std::cout << "Введите строку: ";
        std::cin >> s;
        char* char_array = new char[s.length() + 1];
        char_array[s.length()] = '\0';
        for (int i = 0; i < s.length(); i++) {
            char_array[i] = s[i];
            sum = sum + static_cast<int>(s[i]);
        }
        std::cout << "Наивный хэш строки " << s << " = " << sum;
        
        std::cout << "\n";
        delete[] char_array;
        if (s == "exit")
        {
            break;
        }
    }
    
    return 0;
}

// task2_L16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int real_string_hash(std::string s, int p, int n)
{
        int hash;
        long long sum = 0;
        long long k = static_cast<long long>(p);
        char* char_array = new char[s.length() + 1];
        char_array[s.length()] = '\0';
        if (s.length() == 1)
        {
            hash = static_cast<int>(s[0]) % n;
            delete[] char_array;
            return hash;
        }
        else {
            sum = static_cast<int>(s[0]);
            char_array[0] = s[0];
            for (int i = 1; i < s.length(); i++)
            {
                char_array[i] = s[i];
                sum = sum + static_cast<int>(s[i]) * k;
                k = k * p;
            }
            hash = sum % n;
            delete[] char_array;
            return hash;
        }
 }


int main()
{
    setlocale(LC_ALL, "rus");
    int p,n;
    std::string s;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    while (true) 
    {
        std::cout << "Введите строку: ";
        std::cin >> s;
        std::cout << "Xэш строки " << s << " = " << real_string_hash(s, p, n) << "\n";
        if (s == "exit") 
        {
            break;
        }
    }
    

    return 0;
}


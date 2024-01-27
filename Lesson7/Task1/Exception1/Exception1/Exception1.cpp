#include <iostream>
#include <string>

int function(std::string str, int forbidden_lenght) {
    if (forbidden_lenght != str.length()) {
        std::cout << str << ":" << str.length();
    }
    else
    {
        throw std::runtime_error("Вы ввели слово запретной длины. Программа завершена.");
   }
}

int main() {
    setlocale(LC_ALL, "rus");
    int lenght;
    std::string str;
    std::cout << "Введите запретную длину: ";
    std::cin >> lenght;
    do {
        std::cout << "\nВведите слово: ";
        std::cin >> str;
        try {

            function(str, lenght);
        }
        catch (std::exception const& e)
        {
            std::cout << "Exception: " << e.what() << "\n";
            break;
        }
    }

    while (true);

}

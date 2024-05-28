// kurs3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct ss
{
    ss(std::string _section, std::string _name, std::string _value) : section(_section), name(_name), value(_value) {}
    std::string section, name, value;
};

int main()
{
    setlocale(LC_ALL, "rus");
    std::string h_section = "";
    std::string search_section = "[Section1]";
    std::string search_value = "var1";
    std::ifstream ifs{ "test.ini" };
    std::vector<ss> result;
    std::cout << "Ищем в секции " << search_section << " параметр - " << search_value << std::endl << "\nРезультат поиска:\n";


    for (std::string values, str1, str2; std::getline(ifs, values);)
    {
        if (values == search_section)
        {
            h_section = values;
            ifs >> values;
            while (values.at(0) != '[')
            {
                if (values.find("=") != -1)
                {
                    size_t p = values.find("=");
                    str1 = values.substr(0, p++);
                    if (str1 == search_value)
                    {
                        str2 = values.substr(p, values.size() - p);
                        if (!result.empty())
                        {
                            result.clear();
                        }
                        result.emplace_back(ss(h_section, str1, str2));
                    }
                }
               
                if (ifs.eof())
                {
                   break;
                }
                ifs >> values;
            }
           
        }
    }

 
    for (auto& p : result)
        if (!p.name.empty())
        {
            if (!p.value.empty())
            {
                std::cout << p.section << "\n" << p.name << " = " << p.value << "\n";
            }
            else
            {
                std::cout << "В секции " << h_section << " нет значения для параметра " << p.name << std::endl;
            }
        }
        else
        {
            std::cout << "Нет параметра в секции" << search_section << std::endl;
        }

    if (result.empty())
    {
        if (h_section != "")
        {
            std::cout << "В секции " << h_section << " нет искомого параметра." << std::endl;
        }
        else
        {
            std::cout << "Секции " << search_section << " в файле не найдено." << std::endl;
        }
    }

        
    return 0;
}
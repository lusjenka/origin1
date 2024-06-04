#include "parser.h"


iniParser::iniParser(const std::string& filename) : filename_{ filename }//конструктор принимает ссылку на файл ини

{
    std::ifstream file(filename_);//открываем файл для чтения

    if (!file.is_open())//если закрыт, то вызываем исключение
    {
        throw std::runtime_error("Ошибка открытия файла: " + filename_);
    }

    while (std::getline(file, line_)) // пока файл не кончится читаем в переменную line_
    {
        // Пропускаем комментарии и пустые строки
        if (line_.empty() || line_[0] == ';')
        {
            ++lineNumber_;//если пусто или комментарий, то увеличиваем lineNumber_ на 1
            continue;//выходим считывать следующу строку
        }

        // Находим новый раздел
        if ((line_[0] == '[') && (line_[line_.length() - 1] == ']'))//если нашли секцию
        {
            ++lineNumber_;//заходим в секцию
            // Найден новый раздел
            currentSection_ = line_.substr(1, line_.length() - 2);//в currentSection_ записываем найденную секцию
        }
        else // если не нашли секцию
        {
            ++lineNumber_;
            // Найдена строка с ключом и значением
            std::istringstream iss(line_);//преобразует поток??

            if (std::getline(iss, key_, '='))//читаем line_ записываем в key_ пока не встретим = (было ; всемто =)
            {
                if (key_ == "")//было value_ вместо key_
                {
                    //std::cout << "key_: " << key_ << std::endl;
                    //throw std::runtime_error("нет значения переменной в " + currentSection_ + " в строке № " + std::to_string(lineNumber_));
                }
                

                if (std::getline(iss, value_))//читаем дальше line_ после =
                {
                    size_t pos = value_.find(';');  // находим позицию первого вхождения знака ";"

                    if (pos != std::string::npos) // если знак найден
                    {
                        value_ = value_.substr(0, pos);  // обрезаем строку, оставляя только часть до знака ";"
                    }
                    iniData_[currentSection_][key_] = value_;//записываем в мап [найденная секция][ключ] = значение параметра
                }
            }
        }
    }
    file.close();
}

std::string iniParser::getStringValue(const std::string currentSection, const std::string key, const int lineNumber)
{
    std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
    if (it1 == iniData_.end())
    {
        printMap(currentSection, key);
        throw std::runtime_error(currentSection + " не найдена");
    }
    else
    {
        std::map<std::string, std::string>& innerMap = iniData_[currentSection];
        if (!innerMap.count(key))
        {
            printMap(currentSection, key);
            throw std::runtime_error("");
        }
    }
    return iniData_[currentSection][key];
}

void iniParser::printMap(const std::string currentSection, const std::string key)
{
    std::cout << "Нет значения: " + key + ", в секции " + currentSection << std::endl;
  
}
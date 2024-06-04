#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <type_traits>
#include <locale>

enum class iniWarning
{
    pointIsFound = 1, dataTypeFalse = -1
};

class iniParser
{
private:
	std::map<std::string, std::map<std::string, std::string>> iniData_;
    std::string filename_;
    std::string currentSection_;
    std::string line_;
    std::string key_;
    std::string value_;
    std::string tmpIniDataString_;
    int tmpIniDataInt_ = 0;
    double tmpIniDataDouble_ = 0.0;
    float tmpIniDataFloat_ = 0.0;
    int lineNumber_ = 0;
    
    std::string getStringValue(const std::string currentSection, const std::string key, const int lineNumber);

    void printMap(const std::string currentSection, const std::string key);

public:
    iniParser(const std::string& filename);//конструктор принимает ссылку на файл ини

    
    template <class T>
    T getValue(const std::string currentSection, const std::string key)
    {
        if constexpr (std::is_same_v<T, std::string>) {
            // достаём std::string
            return getStringValue(currentSection, key, lineNumber_);
        }

        if constexpr (std::is_same_v<T, int>) {
            // достаём int
            tmpIniDataString_ = getStringValue(currentSection, key, lineNumber_);

            if (tmpIniDataString_.find(".") == static_cast<size_t>(iniWarning::pointIsFound))
            {
                std::cout << "Предупреждение. Тип этого значения double или float преобразуется в ini !!!" << std::endl;
            }

            try
            {
                tmpIniDataInt_ = std::stoi(tmpIniDataString_);
            }
            catch (const std::out_of_range& ex)
            {
                throw ex;
            }
            catch (const std::invalid_argument& ex)
            {
                throw ex;
            }
            return tmpIniDataInt_;
        }
        if constexpr (std::is_same_v<T, double>) {
            // достаём double
            try
            {
                tmpIniDataDouble_ = std::stod(getStringValue(currentSection, key, lineNumber_));
            }
            catch (const std::out_of_range& ex)
            {
                throw ex;
            }
            catch (const std::invalid_argument& ex)
            {
                throw ex;
            }
            return tmpIniDataDouble_;
        }
        if constexpr (std::is_same_v<T, float>) {
            // достаём float
            try
            {
                tmpIniDataFloat_ = std::stof(getStringValue(currentSection, key, lineNumber_));
            }
            catch (const std::out_of_range& ex)
            {
                throw ex;
            }
            catch (const std::invalid_argument& ex)
            {
                throw ex;
            }
            return tmpIniDataFloat_;
        }

    };

 };
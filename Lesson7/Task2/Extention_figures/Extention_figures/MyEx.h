#pragma once
#include <exception>

class MyEx : public std::exception
{
private:
    std::string message;
    std::string name;
public:
    MyEx(std::string message, std::string name) {
        this->message = message;
        this->name = name;
    }
public:
    std::string getMessage() const { std::cout << "Фигура " << name << "не создана. "; return  message; }
};

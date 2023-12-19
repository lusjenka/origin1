#include <iostream>

struct bank_account
{
    int score;
    std::string name;
    double balance;
};
void change_balance(bank_account& p)
{
    std::cout << "Введите новый баланс: \n";
    std::cin >> p.balance;
}

int main(int argc, char** argv)
{
    system("chcp 1251>null");
    bank_account pers;
    std::cout << "Введите номер счета: \n";
    std::cin >> pers.score;
    std::cout << "Введите имя: \n";
    std::cin >> pers.name;
    std::cout << "Введите баланс: \n";
    std::cin >> pers.balance;
    change_balance(pers);
    std::cout << "Номер счета: " << pers.score << "\n" << "Имя: " << pers.name << "\n" << "Баланс: " << pers.balance << "\n";
}
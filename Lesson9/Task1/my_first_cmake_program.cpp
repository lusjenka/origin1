#include<iostream>

int main()
{
	setlocale(LC_ALL,"rus");
	std::cout << "Введите ваше имя: ";
	std::string name;
	std::cin >> name;
	std::cout << "\nЗдравствуйте, " << name;
	return 0;
}
#include<iostream>

int main()
{
	setlocale(LC_ALL,"rus");
	std::cout << "������� ���� ���: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n������������, " << name;
	return 0;
}
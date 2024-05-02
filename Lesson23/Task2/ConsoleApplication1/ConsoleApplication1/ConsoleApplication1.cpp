#include <iostream>
#include <algorithm>
#include <forward_list>

int main()
{
	setlocale(LC_ALL,"rus");
	std::forward_list<int> fl;
	std::cout << "Размер: \n";
	int size;
	std::cin >> size;
	std::cout << "Cписок: \n";
	for (int x, i = 0; i < size && std::cin >> x; i++)
		fl.push_front(x);


	fl.sort(); 

	fl.unique();
	fl.reverse();
	std::cout << "\n";
	for (const auto& elem : fl)
		std::cout << elem << "\n";
		
}

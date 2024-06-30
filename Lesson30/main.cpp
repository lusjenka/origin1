#include <iostream>
#include <thread>
#include <chrono>

int maxClients = 5, counter = 0;

void func1()
{
	while (counter < maxClients)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		counter++;
		std::cout << "Пришел клиент. Всего клиентов: " << counter << "\n";
	}
}
void func2()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		if (counter > 0)
		{
			counter--;
			std::cout << "Оператор отпустил клиента. Всего клиентов: " << counter << "\n";
		}
		else
		{
			std::cout << "Оператор свободен. Всего клиентов: " << counter << "\n";
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Hello";
	std::thread cl (func1);
	std::thread op (func2);

	cl.join();
	op.join();

	return 0;
}

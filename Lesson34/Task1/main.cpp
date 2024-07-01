#include <iostream>
#include <vector>
#include <random>
#include<future>
#include<algorithm>


void printVector(const std::vector<int>& v_)
{
	for (const auto& i : v_)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

void findMin(const std::vector<int> v, int i, std::promise<int> pr)
{
		int minIndex = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[minIndex])
			{
				minIndex = j;
			}
		}
		pr.set_value(minIndex);
};


int main()
{
	setlocale(LC_ALL, "rus");
	std::vector<int> v{ 5,56,71,2,48,56,9,15,-3,10 };
	std::cout << "Было: ";
	printVector(std::ref(v));//передаем вектор по ссылке

	for (int i = 0; i < v.size() - 1; i++)
	{
		std::promise<int> pr;//предоставляет механизм для связи потока, который обещает предоставить значение в будущем (поставщик), с потоком, который ожидает получение этого значения (потребитель)
		std::future<int> fut = pr.get_future();//используется для получения результата асинхронно выполненной задачи, ещё не вычисленного, то есть будущего значения.

		auto asyncFindMin = std::async(std::launch::async, findMin, v, i, std::move(pr));//std::async создает новый поток или использует существующий поток из пула потоков реализации для выполнения поставленной задачи. Она возвращает объект std::future, который можно использовать для получения результата или статуса вычисления. 

		int min = fut.get();
		if (v[i] != v[min])
		{
			std::swap(v[i], v[min]);
		}
	}

	std::cout << "Стало: ";
	printVector(std::ref(v));
}
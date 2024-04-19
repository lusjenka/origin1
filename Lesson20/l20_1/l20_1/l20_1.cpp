// l20_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class smart_array
{
private:
	int* ptr_;
	int index_ = 0;
	size_t size_;
public:
	smart_array(size_t sz_) :size_(sz_), ptr_(new int[sz_])
	{
		std::cout << "Вызван конструктор."  << "\n";

	}
	~smart_array()
	{
		delete[] ptr_;
		std::cout << "Вызван деструктор." << "\n";

	}
	void add_element(int value)
	{
		if (index_ < size_)
		{
			ptr_[index_] = value;
			std::cout << "Добавлен элемент " << value << " в индекс " << index_ << "\n";
			index_++;
		}
		else
		{
			throw std::runtime_error("Переполнение массива.");
		}
	}
	int get_element(int ind_)
	{
		std::cout << "Получен элемент под индексом " << ind_<< ": ";
		return ptr_[ind_];
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
    try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		std::cout << arr.get_element(3) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}

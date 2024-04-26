// l20_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class smart_array
{
private:
	int* ptr_ = nullptr;
	int index_ = 0;
	size_t size_;
public:
	smart_array(size_t sz_) :size_(sz_), ptr_(new int[sz_])
	{

		std::cout << "Вызван конструктор." << "\n";

	}
	
	smart_array(const smart_array& other) :size_(other.size_),index_(other.index_), ptr_(new int[size_])
	{
			std::cout << "Вызван конструктор копирования." << "\n";

			for (int i = 0; i < size_; ++i)
			{
				ptr_[i] = other.ptr_[i];
			}
	}
	
	smart_array& operator=(const smart_array& other)
	{
		if (this != & other)
		{
			std::cout << "Вызван оператор присваивания." << "\n";
			delete[] ptr_;
			size_ = other.size_;
			index_ = other.index_;
			ptr_ = new int[size_];
			for (int i = 0; i < size_; ++i)
			{
				ptr_[i] = other.ptr_[i];
			}
		}
		
		return *this;
	}
	
	~smart_array()
	{
		std::cout << "Вызван деструктор." << "\n";
		delete[] ptr_;

		
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
		if ((ind_ < 0) || (ind_ > index_))
		{
			std::cout << "Некорректный индекс - ";
			return ind_;
		}
		std::cout << "Получен элемент под индексом " << ind_ << ": ";
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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
}


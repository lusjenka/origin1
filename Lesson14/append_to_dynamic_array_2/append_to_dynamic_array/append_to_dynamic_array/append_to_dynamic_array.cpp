#include <iostream>
using namespace std;

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size,int& addEl)
{
	if (logical_size == actual_size)
	{
		actual_size = actual_size * 2;
		arr[logical_size] = addEl;
		logical_size++;
		return arr;
	}
	else {
		arr[logical_size] = addEl;
		logical_size++;
		return arr;
	}
}

void add_first_dynamic_array(int* arr, int& logical_size)
{
	int count = 0;
	while (count < logical_size)
	{
		cout << "Введите " << "arr[" << count << "]:" << endl;
		cin >> arr[count];
		count++;

	}
		
};
void print_dynamic_array(int* arr, int& logical_size, int& actual_size)
{
	for (int i = 0; i < logical_size; i++)
	{
		cout << arr[i] << " ";
	}
	if (actual_size > logical_size)
	{
		for (int i = logical_size; i < actual_size; i++)
		{
			cout << " _ ";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int sizeF, sizeL,addEl;
	cout << "Введите фактичеcкий размер массива: ";
	cin >> sizeF;
	cout << "Введите логический размер массива: ";
	cin >> sizeL;
	
	if (sizeF < sizeL)
	{
		cout << "Ошибка! Логический размер массива не может превышать фактический!";
	}
	else {
		int* arr = new int[sizeF];
		add_first_dynamic_array(arr, sizeL);
		do
		{
			cout << "\nВведите элемент для добавления: ";
			cin >> addEl;
			if (addEl == 0) { break; }
			print_dynamic_array((append_to_dynamic_array(arr, sizeL, sizeF, addEl)), sizeL, sizeF);
		} while (addEl != 0);
		


		delete[] arr;
	}
	
	return 0;
}



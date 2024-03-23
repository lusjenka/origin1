#include <iostream>
using namespace std;

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	int count = 0;
	while (count<logical_size)
	{
		cout << "Введите" << "arr[" << count <<"]:" << endl;
		cin >> arr[count];
		count++;
		
	}
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
	int sizeF, sizeL;
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
		print_dynamic_array(arr, sizeL, sizeF);
		delete[] arr;
	}
	return 0;
}


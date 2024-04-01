#include <iostream>
using namespace std;

int left_index(int parent_index) { return 2 * parent_index + 1; }

int right_index(int parent_index) { return 2 * parent_index + 2; }

int parent_index(int child_index) { return (child_index - 1) / 2; }

void leftOrRight(int index)
{
    if (index % 2 == 0)
    {
        cout << " right(";
    }
    else
    {
        cout << " left(";
    }
}

void lev(int i, int &k, int &n, int &level)
{
    if (i == 1 || i == 2) { cout << 1 << " "; }

    else
    {
        if (k < n)
        {
            cout << level << " ";
            k++;
        }
        else
        {
            k = 1;
            n = n * 2;
            level++;
            cout << level << " ";
        }

    }
    
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 4;
    int level = 2;
    int k = 0;
    string step;
    int arr[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arr_level[10] = {0,1,1,2,2,2,2,3,3,3};
    cout << 0 << " root " << arr[0] << endl;

    for (int i = 1; i < 10; i++)

    {
        lev(i, k, n, level);
        leftOrRight(i);
        cout << arr[parent_index(i)] << ") ";
        cout << " " << arr[i] << endl;
    }

    cout << "Вы находитесь здесь: ";
    cout << 0 << " root " << arr[0] << endl;
    int i2 = 0;
    do {
        cout << "Введите команду: ";
        cin >> step;
        
        if (step == "exit") { break; }

        if (step == "left") { 
            if (left_index(i2) > 9) { cout << "Ошибка! Отсутствует левый потомок.\n\nВы находитесь здесь: ";
            cout << arr_level[i2];
            leftOrRight(i2);
            cout << arr[parent_index(i2)] << ") ";
            cout << arr[i2] << endl; 
            }
            else {
                cout << "Ok.\n";
                cout << "Вы находитесь здесь: ";
                cout << arr_level[left_index(i2)] << " ";
                leftOrRight(left_index(i2));
                cout << arr[parent_index(left_index(i2))] << ") ";
                cout << arr[left_index(i2)] << endl;
                i2 = left_index(i2);
            }

        }
        else if (step == "right") { 
            if (right_index(i2) > 9) { cout << "\nОшибка! Отсутствует правый потомок.\nВы находитесь здесь: ";
            cout << arr_level[i2];
            leftOrRight(i2);
            cout << arr[parent_index(i2)] << ") ";
            cout << arr[i2] << endl;
            }
            else {
                cout << "Ok.\n";
                cout << "Вы находитесь здесь: ";
                cout << arr_level[right_index(i2)] << " ";
                leftOrRight(right_index(i2));
                cout << arr[parent_index(right_index(i2))] << ") ";
                cout << arr[right_index(i2)] << endl;
                i2 = right_index(i2);
            }
        }
        else if (step == "up") { 
            if (i2 == 0) { cout << "\nОшибка! Отсутствует родитель.\nВы находитесь здесь : ";
            cout << arr_level[i2];
            leftOrRight(i2);
            cout << arr[parent_index(i2)] << ") ";
            cout << arr[i2] << endl;
            }
            else {
                cout << "Ok.\n";
                cout << "\nВы находитесь здесь: ";
                cout << arr_level[parent_index(i2)] << " ";
                leftOrRight(parent_index(i2));
                cout << arr[parent_index(parent_index(i2))] << ") ";
                cout << arr[parent_index(i2)] << endl;
                i2 = parent_index(i2);
            }
        }
                
    } 
    while (step != "exit");
    
    return 0;
}

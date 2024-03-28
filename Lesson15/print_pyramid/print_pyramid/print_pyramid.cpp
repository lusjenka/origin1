#include <iostream>
#include <cmath>
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

int main()
{
    int n = 4;
    int level = 2;
    int k = 0;
    int arr[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    cout << 0 << " root " << arr[0] << endl;

    for (int i = 1; i < 10; i++)

    {
        if (i == 1 || i == 2) { cout << 1 << " "; }
        else
        {
            if (k<n)
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
        leftOrRight(i);
        cout << arr[parent_index(i)] << ") ";
        cout << " " << arr[i] << endl;
    }
    return 0;
}

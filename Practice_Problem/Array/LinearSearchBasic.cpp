#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {3, 4, 90, 56, 12};
    int n = sizeof(arr) / sizeof(int);
    int key = 6;

    cout << linearSearch(arr, n, key) << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int arr[] = { 2, 8, 1, 8, 3, 2, 7, 6, 2, 1 };
    int len_arr = sizeof(arr) / sizeof(arr[0]);

    int biggest = arr[0];
    int lowest = arr[0];
    for (int i = 0; i < len_arr; i++)
    {
        if (arr[i] > biggest)
        {
            biggest = arr[i];
        }
        if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }

    int size = biggest - lowest + 1;
    int* new_arr = new int[size] {};
    for (int i = 0; i < len_arr; i++)
    {
        new_arr[arr[i] - lowest] += 1;
    }

    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < new_arr[i]; j++)
        {
            arr[ind++] = i + lowest;
        }
    }

    delete[] new_arr;

    if (len_arr > 0)
    {
        cout << arr[0];
    }

    for (int i = 1; i < len_arr; i++)
    {
        cout << ' ' << arr[i];
    }
}
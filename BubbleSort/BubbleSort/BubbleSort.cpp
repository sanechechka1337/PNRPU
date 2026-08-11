#include <iostream>

using namespace std;

int main()
{
    int c;
    int arr[] = { 98,88,3,2,1 };
    int len_arr = sizeof(arr) / 4;
    for (int i = 0; i < len_arr - 1; i++)
    {
        for (int j = 0; j < len_arr - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                c = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = c;
            }
        }
    }
    for (int k = 0;k < len_arr;k++)
    {
        cout << arr[k] << " ";
    }
}
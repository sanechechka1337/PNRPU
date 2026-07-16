#include <iostream>

using namespace std;

int main()
{
    int copy, ind;
    int arr[] = { 7,3,8,9,2,4 };
    int len_arr = sizeof(arr) / 4;
    for (int i = 1; i < len_arr; i++)
    {
        copy = arr[i];
        ind = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i - j - 1] > copy)
            {
                arr[i - j] = arr[i - j - 1];
                ind = i - j - 1;
            }
            else
            {
                break;
            }
        }
        arr[ind] = copy;
    }
    for (int k = 0;k < len_arr;k++)
    {
        cout << arr[k] << " ";
    }
}
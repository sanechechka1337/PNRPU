#include <iostream>

using namespace std;

int main()
{
    int copy, ind;
    int arr[] = { 10,20,30,40,15 };
    int len_arr = sizeof(arr) / 4;
    int step = len_arr;
    while (step > 1)
    {
        step = step / 2;
        for (int i = step; i < len_arr; i++)
        {
            copy = arr[i];
            ind = i;
            for (int j = i - step; j >= 0; j -= step)
            {
                if (arr[j] > copy)
                {
                    arr[j + step] = arr[j];
                    ind = j;
                }
                else
                {
                    break;
                }
            }
            arr[ind] = copy;
        }
    }
    for (int k = 0;k < len_arr;k++)
    {
        cout << arr[k] << " ";
    }
}
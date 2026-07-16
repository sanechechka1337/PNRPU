#include <iostream>

using namespace std;

int main()
{
    int c, mini, ind;
    int arr[] = { 7,8,3,4,1,2 };
    int len_arr = sizeof(arr) / 4;
    for (int i = 0; i < len_arr - 1; i++)
    {
        mini = arr[i];
        ind = i;
        for (int j = i + 1; j < len_arr; j++)
        {
            if (mini > arr[j])
            {
                mini = arr[j];
                ind = j;
            }
        }
        c = arr[i];
        arr[i] = mini;
        arr[ind] = c;
    }
    for (int k = 0;k < len_arr;k++)
    {
        cout << arr[k] << " ";
    }
}
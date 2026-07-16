#include <iostream>
using namespace std;

int main()
{
    const int len_arr = 7;
    int arr[len_arr] = { 20, 23, 30, 22, 44, 34, 1 };

    int biggest = arr[0];
    int lowest = arr[0];
    for (int i = 0; i < len_arr; i++)
    {
        if (arr[i] > biggest)
        {
            biggest = arr[i];
        }
        else if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }

    int buckets = biggest / 10 - lowest / 10 + 1;
    int** new_arr = new int* [buckets] {};

    for (int i = 0; i < buckets; i++)
    {
        new_arr[i] = new int[len_arr] {};
    }

    int* bucket_size = new int[buckets] {};
    for (int i = 0; i < len_arr; i++)
    {
        int ind = arr[i] / 10 - lowest / 10;
        new_arr[ind][bucket_size[ind]++] = arr[i];
    }

    for (int i = 0; i < buckets; i++)
    {
        for (int j = 0; j < bucket_size[i] - 1; j++)
        {
            for (int r = 0; r < bucket_size[i] - j - 1; r++)
            {
                if (new_arr[i][r] > new_arr[i][r + 1])
                {
                    int swap = new_arr[i][r];
                    new_arr[i][r] = new_arr[i][r + 1];
                    new_arr[i][r + 1] = swap;
                }
            }
        }
    }

    int ind = 0;
    for (int i = 0; i < buckets; i++)
    {
        for (int j = 0; j < bucket_size[i]; j++)
        {
            arr[ind++] = new_arr[i][j];
        }
    }

    for (int i = 0; i < len_arr; i++) {
        cout << arr[i] << ' ';
    }

    delete[] bucket_size;
    for (int i = 0; i < buckets;i++)
    {
        delete[] new_arr[i];
    }
    delete[] new_arr;
}
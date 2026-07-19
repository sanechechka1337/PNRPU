#include <iostream>
using namespace std;

const int len_arr = 8;
int arr[len_arr] = { 1, 3, 9, 6, 7, 10, 9, 9 };

void HoareSort(int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int right_index = end;
    int left_index = begin;
    int pivot = arr[(begin + end) / 2];

    while (left_index <= right_index)
    {
        while (arr[left_index] < pivot)
        {
            left_index++;
        }

        while (arr[right_index] > pivot)
        {
            right_index--;
        }

        if (left_index <= right_index)
        {
            int swap = arr[right_index];
            arr[right_index] = arr[left_index];
            arr[left_index] = swap;
            left_index++;
            right_index--;
        }
    }

    HoareSort(begin, right_index);
    HoareSort(left_index, end);
}

int main()
{
    HoareSort(0, len_arr - 1);
    cout << arr[0];
    for (int i = 1; i < len_arr; i++)
    {
        cout << ' ' << arr[i];
    }
}
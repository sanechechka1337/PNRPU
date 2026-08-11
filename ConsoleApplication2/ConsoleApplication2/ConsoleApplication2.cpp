#include <iostream>
using namespace std;

const int len_arr = 6;
int arr[len_arr] = { 7, 3, 8, 9, 2, 5 };

void QuickSort(int begin, int pivot_index)
{
    if (begin >= pivot_index)
    {
        return; 
    }

    int current_index = begin;
    for (int i = begin; i < pivot_index; i++)
    {
        if (arr[i] < arr[pivot_index])
        {
            int swap_element = arr[i];
            arr[i] = arr[current_index];
            arr[current_index] = swap_element;

            current_index += 1; 
        }
    }

    int swap_element = arr[current_index];
    arr[current_index] = arr[pivot_index];
    arr[pivot_index] = swap_element;

    QuickSort(begin, current_index - 1);
    QuickSort(current_index + 1, pivot_index);
}

int main()
{
    QuickSort(0, len_arr - 1);
    for (int i = 0; i < len_arr; i++)
    {
        cout << arr[i] << ' ';
    }
}

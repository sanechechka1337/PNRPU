#include <iostream>
using namespace std;

const int len_arr = 8;
int arr[len_arr] = {7, 3, 8, 9, 2, 4, 6, 1};

void Merge(int begin, int end, int mid)
{
	int begin_a = begin;
	int end_a = mid;
	int begin_b = mid + 1;
	int ind = begin;
	int new_arr[len_arr]{};

	while ((begin_a <= end_a) and (begin_b <= end))
	{
		if (arr[begin_a] < arr[begin_b])
		{
			new_arr[ind] = arr[begin_a];
			begin_a++;
		}
		else
		{
			new_arr[ind] = arr[begin_b];
			begin_b++;
		}
		ind++;
	}

	while (begin_a <= end_a)
	{
		new_arr[ind] = arr[begin_a];
		begin_a++;
		ind++;
	}

	while (begin_b <= end)
	{
		new_arr[ind] = arr[begin_b];
		begin_b++;
		ind++;
	}

	for (int j = begin; j < ind; j++)
	{
		arr[j] = new_arr[j];
	}
}

void Slice(int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		Slice(begin, mid);
		Slice(mid + 1, end);
		Merge(begin, end, mid);
	}
}

int main()
{
	Slice(0, len_arr - 1);

	for (int i = 0;i < len_arr;i++)
	{
		cout << arr[i] << ' ';
	}
}
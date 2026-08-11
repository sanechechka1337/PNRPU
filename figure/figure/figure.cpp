#include <iostream>
using namespace std;

void Raw_star(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << '*';
	}
	cout << endl;
}

int main()
{
	system("chcp 1251>NULL");

	int n;
	cin >> n;

	Raw_star(n);

	for (int i = 0; i < n - 2; i++)
	{
		cout << '*';
		for (int j = 0; j < n - 2; j++)
		{
			cout << ' ';
		}
		cout << '*' << endl;
	}

	Raw_star(n);
}
#include <iostream>
using namespace std;

bool arr[10001];

int sum1(int n)
{
	int sum = n;
	while (n != 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int main()
{
	for (int i = 1; i < 10001; i++)
	{
		int idx = sum1(i);

		if (idx < 10001)
		{
			arr[idx] = true;
		}
	}
	for (int i = 1; i < 10001; i++)
	{
		if (!arr[i])
			cout << i << endl;
	}

	return 0;
}
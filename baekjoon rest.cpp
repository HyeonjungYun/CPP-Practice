#include <iostream>
using namespace std;

int main()
{
	int input = 0;
	int arr[10] = {};
	int asr = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> input;
		arr[i] = input % 42;
	}
	for (int j = 0; j < 10; j++)
	{
		asr += 1;
		for (int k = 0; k < j; k++)
		{
			if (arr[j] == arr[k])
			{
				asr -= 1;
				break;
			}
		}
	}

	cout << asr << endl;

	return 0;
}
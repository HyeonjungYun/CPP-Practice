#include <iostream>

using namespace std;

int main()
{
	int arr[10] = {};
	int Num1 = 0;
	int Num2 = 0;
	int Num3 = 0;
	int Asr = 0;

	cin >> Num1 >> Num2 >> Num3;

	Asr = Num1 * Num2 * Num3;

	while (Asr != 0)
	{
		arr[Asr % 10] += 1;
		Asr /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] <<  endl;
	}

	return 0;
}
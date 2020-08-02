#include <iostream>
using namespace std;

int hansoo = 0;

bool proof(int n)
{
	if (n < 100)
		return true;
	int n1, n2, n3;

	n3 = n / 100;
	n2 = n % 100 / 10;
	n1 = n % 10;

	if ((n3 - n2) == (n2 - n1))
		return true;
	return false;
}

int main()
{
	int iInput = 0;
	cin >> iInput;

	
	for (int i = 1; i <= iInput; i++)
	{
		if (proof(i))
			++hansoo;
	}
	cout << hansoo << endl;
	return 0;
}
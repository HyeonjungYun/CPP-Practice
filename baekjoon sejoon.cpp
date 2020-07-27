#include <iostream>

using namespace std;

int main()
{
	int iSub = 0;
	double iScore[1000] = {};
	int max = 0;
	double dNScore[1000] = {};
	double dTotal = 0;
	

	cin >> iSub;
	for (int i = 1; i <= iSub; i++)
	{
		cin >> iScore[i];

		if (max < iScore[i])
		{
			max = iScore[i];
		}
	}
	for (int j = 1; j <= iSub; j++)
	{
		dNScore[j] = iScore[j] / max * 100;
	}
	for (int i = 1; i <= iSub; i++)
	{
		dTotal += dNScore[i];
	}
	cout.precision(8);
	cout << dTotal / iSub << endl;


	return 0;
}
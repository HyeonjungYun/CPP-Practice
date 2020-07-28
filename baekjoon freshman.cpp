#include <iostream>
using namespace std;

int main()
{
	int iN = 0;
	double dNumber;
	int iTotal;
	double diAvgUp;
	double dAvg;
    double dAvgUp;

	cin >> iN;
	for (int i = 0; i < iN; i++)
	{
		iTotal = 0;
		dNumber = 0;
		int iScore[999] = {};
		diAvgUp = 0;
		dAvg = 0;
		dAvgUp = 0;

		cin >> dNumber;
		for (int j = 0; j < dNumber; j++)
		{
			cin >> iScore[j];
			iTotal += iScore[j];
		}
		dAvg = iTotal / dNumber;

		for (int j = 0; j < dNumber; j++)
		{
			if (iScore[j] > dAvg)
			{
				++diAvgUp;
			}
		}
		dAvgUp = (diAvgUp / dNumber) * 100;
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << dAvgUp << "%" << endl;
	}

	return 0;
}
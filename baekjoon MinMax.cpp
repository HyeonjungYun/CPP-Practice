#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int input;
	int min = 0;
	int max = 0;


	
	for (int i = 1; i <= N; i++)
	{
		cin >> input;

		if (i == 1)
		{
			min = input;
			max = input;
			
		}

		else
		{
			if (min > input)
				min = input;

			if (max < input)
				max = input;
		}
	}
	cout << min << " " << max;

	return 0;
	

	


}
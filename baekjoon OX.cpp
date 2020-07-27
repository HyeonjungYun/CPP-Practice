#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char input[80] = {}; // 문자열이 차례대로 입력될 배열
	int N = 0;			 // 입력될 문자열의 갯수
	int correct = 0;	 // 맞췄을 때 증가되는 점수
	int iScore = 0;		 // 출력되는 점수
	int time = 0;		 //반복 횟수

	cin >> N;

	while (N > time)
	{
		cin >> input;

		for (int i = 0; i < strlen(input); i++)
		{
			if (input[i] == 'O')
			{
				correct = correct + 1;  // 맞출 때마다 점수를 증가시킴
				iScore += correct;
			}
			if(input[i] == 'X')
			{
				correct = 0;			// 틀릴 때 증가된 점수를 다시 초기화 시킴
			}
		}
		cout << iScore << endl;
		iScore = 0;						// 위에서 입력된 점수 초기화
		correct = 0;					// 위에서 증가된 +점수 초기화
		time++;
	}

	return 0;
}
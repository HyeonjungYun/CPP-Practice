#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char input[80] = {}; // ���ڿ��� ���ʴ�� �Էµ� �迭
	int N = 0;			 // �Էµ� ���ڿ��� ����
	int correct = 0;	 // ������ �� �����Ǵ� ����
	int iScore = 0;		 // ��µǴ� ����
	int time = 0;		 //�ݺ� Ƚ��

	cin >> N;

	while (N > time)
	{
		cin >> input;

		for (int i = 0; i < strlen(input); i++)
		{
			if (input[i] == 'O')
			{
				correct = correct + 1;  // ���� ������ ������ ������Ŵ
				iScore += correct;
			}
			if(input[i] == 'X')
			{
				correct = 0;			// Ʋ�� �� ������ ������ �ٽ� �ʱ�ȭ ��Ŵ
			}
		}
		cout << iScore << endl;
		iScore = 0;						// ������ �Էµ� ���� �ʱ�ȭ
		correct = 0;					// ������ ������ +���� �ʱ�ȭ
		time++;
	}

	return 0;
}
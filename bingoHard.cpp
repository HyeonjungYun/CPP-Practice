#include<iostream>
#include<ctime>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT

};

int main()
{
	srand(time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};
	//1~25���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	//���ڸ� �����ش�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		//AI���ڵ� �����ش�.

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

	}

	int iBingo = 0;
	int	iAIBingo = 0;

	//AI ���̵��� �����Ѵ�.
	int iAIMode;

	while (true)
	{
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "3. AI ��带 �����ϼ���. : " << endl;

		cin >> iAIMode;

		if (iAIMode >= AM_EASY || iAIMode > AM_HARD)
			break;
	}

	/*
	AI Easy���� ���� AI�� ���� ����� *�� �ٲ��� ���� ���� ����� ���� �� ��� ��
	�ϳ��� �����ϰ� �ȴ�.(�����ϰ�)
	*/
	//���� �� �� ��� �迭�� ������ش�.

	int iNoneSelect[25] = {};
	// ���� �� �� ���� ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		cout << "================ Player ===================" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";   //�迭 �ȿ� 25������ ���ڸ� ��� ���
			}

			cout << endl;
		}

		//AI�������� ����Ѵ�.
		cout << "================ AI===================" << endl;

		switch (iAIMode)
		{
		case AM_EASY:
			cout << "AlMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iAINumber[i * 5 + j] << "\t";   //�迭 �ȿ� 25������ ���ڸ� ��� ���
			}

			cout << endl;
		}

		//AI ���� �� ���� ����Ѵ�.

		cout << "AIBingo Line : " << iAIBingo << endl;

		cout << "Bingo Line : " << iBingo << "\n" << endl;

		// �ټ��� 5�̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
		{
			cout << "�÷��̾� �¸�!" << endl;
			break;
		}

		else if (iAIBingo >= 5)
		{
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;


		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		//continue�� ���ؼ� �ٽ� while������ �ö󰡰� �Ѵ�.

		bool bAcc = true;
		//�ߺ��� üũ�ϱ� ���� �����̴�. �⺻������
		//�ߺ��� �Ǿ��ٶ�� �ϱ� ���� true��� ����־���.

		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ������
		//�ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i)
		{
			//���� ���ڰ� ���� ���
			if (iInput == iNumber[i])
			{
				//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				//bAcc������ false�� ������ش�.
				bAcc = false;

				//���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				// ���̻� �ٸ� ���ڸ� ã�� �� �ʿ䰡 �����Ƿ�
				// for���� ����������.
				break;
			}
		}

		// bAcc������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *�� 
		// �ٲ��� �� �����Ƿ� �ٽ� �Է� �ް� continue���ش�.
		if (bAcc)
			continue;

		//�ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		//AI�� �����Ѵ�. AI�� �����ϴ� ���� AI��忡 ���� �޶�����.

		iNoneSelectCount = 0;
		switch (iAIMode)
		{
			/*
	AI Easy���� ���� AI�� ���� ����� *�� �ٲ��� ���� ���� ����� ���� �� ��� ��
	�ϳ��� �����ϰ� �ȴ�.(�����ϰ�)
	*/
		case AM_EASY:
			//���� �� �� ���� ����� ������ش�
			//���� �� �� ���� ������ ����� ���� �� ī���� ���ش�.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; ++i)
			{


				//���� ���ڰ� *�� �ƴ� ���
				if (iAINumber[i] != INT_MAX)
				{
					// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ���Ѵ�.
					// ���� �� �� ��Ͽ� �߰��� ������ ������ 1�� �������Ѽ�
					// �� ���� �� �� ������ �����ش�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1��
					// �߰��Ǿ��ٶ�� ���ش�.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
					// iNoneSelectCount�� Ȱ���Ͽ� iNoneSelect�� �迭�� �÷��̾��� ���忡��
					// ���õ� ���ڸ� �־��ش�.
				}
			}
			// for���� ���������� �Ǹ� ���� �� �� ����� ���������
				// ���� �� �� ����� ������ ��������� �ȴ�.
				// ���� �� �� ����� ���� �� ������ �ϳ��� ���ڸ� ������ ���ؼ�
				// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];

			break;
		case AM_HARD:
			// �ϵ� ���� ���� ���� �� ���� �� �ϼ� ���ɼ��� ���� ���� ���� 
			// ã�Ƽ� �� �ٿ� �ִ� ���� �� �ϳ��� *�� ������ش�.
			int iLine;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� ���� �� ���� *�� ���� ������ ã�Ƴ���.
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}

				// ���� 5�� �̸��̾�� ���� ���� �ƴϰ� ������ ���� ���� ������ 
				// ������ Ŀ�� ���� ���� ���� �����̹Ƿ� ������ ��ü ���ְ�
				// ����� �� ���� ��ü�Ѵ�.
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			// ���� ���� �� ���� ���� ���� ������ �̹� ���ߴ�.
			// �� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
				// ���ζ����� 5 ~ 9�� �ǹ̸� �ο��ߴ�.
				iLine = i + 5;
				iSaveCount = iStarCount;
				}
				
			}

			// ���� ������ �밢�� üũ
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			// ������ -> ���� �밢�� üũ
			iStarCount = 0;
			for (int i = 4; i < 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}
			// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ��
			//���� �Ǿ���.
			//�� �ٿ� �ִ� *�� �ƴ� ���� �� �ϳ��� �����ϰ� �Ѵ�.
			// �������� ���
			if (iLine <= LN_H5)
			{
				// �������� ��� iLIne�� 0~ 4 ������ ���̴�.
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			
			else if (iLine <= LN_V5)
			{
				// ���� ���� ��� iLIne�� 5 ~ 9 ������ ���̴�.
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; ++i)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 4; i < 20; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}

		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		// AI ���ڸ� �ٲ��ش�.
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� ������ ó������
		//���� ī��Ʈ�� �� ���̴�. �׷��Ƿ� iBingo ������ 0���� �Ź� 
		//�ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;
		iAIBingo = 0;

		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			//�� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			//���θ��� üũ�� ����� �ϱ⶧��
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				//���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				//���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				// AI �� üũ 
				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;

				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}

			// j for���� ���������� ���� ���� ���� ���� �� ������ ����� 
			// iStar1������ ���� �ȴ�. iStar1�� ���� 5�̸� ������ 
			// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
			if (iStar1 == 5)
				++iBingo;

			if (iAIStar1 == 5)
				++iAIBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAIStar2 == 5)
				++iAIBingo;
		}

		// ���� ��ܿ��� ->������ �ϴ� �밢�� üũ
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		if (iAIStar1 == 5)
			++iAIBingo;

		// ������ ��� -> ���� �ϴ� üũ
		iStar2 = 0;
		iAIStar2 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar2;

			if (iAINumber[i] == INT_MAX)
				++iAIStar2;
		}
		if (iStar2 == 5)
			++iBingo;

		if (iAIStar2 == 5)
			++iAIBingo;
	}

	return 0;
}
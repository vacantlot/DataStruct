#include<iostream>
#include<random>
#pragma region 递归二分方法



	/*const size_t MAXLEN = 10;
	const char TestArr[MAXLEN] = { 'A','B','C','D','E','F','G','H','I','J' };

	static char RecurArr[MAXLEN] = { 0 };
	static int cnt = 0;
	void ShuffleArray_Recursive_Tmp(char* arr, int len)
	{
		if (cnt > MAXLEN || len <= 0) {
			return;
		}

		int pos = rand() % len;
		RecurArr[cnt++] = arr[pos];
		if (len == 1) return;
		ShuffleArray_Recursive_Tmp(arr, pos);
		ShuffleArray_Recursive_Tmp(arr + pos + 1, len - pos - 1);
	}

	void ShuffleArray_Recursive(char* arr, int len)
	{
		memset(RecurArr, 0, sizeof(RecurArr));
		cnt = 0;
		ShuffleArray_Recursive_Tmp(arr, len);
		memcpy(arr, RecurArr, len);
	}

	void main()
	{
		char temp[MAXLEN] = { 0 };
		for (int i = 0; i<5; i++)
		{
			strncpy_s(temp, TestArr, MAXLEN);
			ShuffleArray_Recursive((char*)temp, MAXLEN);
		}
	}*/
#pragma endregion

#pragma region Fisher_Yates算法
void ShuffleArray_Fisher_Yates(char* arr, int len , int* rember)
{
	int i = len, j;
	//char temp;

	//if (i == 0) return;
	//while (--i) {
		j = rand() % (i + 1);
		//temp = arr[i];
		//arr[i] = arr[j];
		//arr[j] = temp;
		switch (arr[j])
		{
		case 'A':rember[0] += 1; break;
		case 'B':rember[1] += 1; break;
		case 'C':rember[2] += 1; break;
		case 'D':rember[3] += 1; break;
		case 'E':rember[4] += 1; break;
		case 'F':rember[5] += 1; break;
		case 'G':rember[6] += 1; break;
		case 'H':rember[7] += 1; break;
		case 'I':rember[8] += 1; break;
		case 'J':rember[9] += 1; break;
		default:
			break;
		}
	//}
}

void main()
{
	int rember[10] = { 0 ,0, 0 ,0, 0 ,0, 0 ,0, 0 ,0 };
	char TestArr[] = { 'A','B','C','D','E','F','G','H','I','J' };
	for (int i = 0; i < 100000; i++)
	{	
	ShuffleArray_Fisher_Yates(TestArr, 10,rember);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << rember[i] << std::endl;
	}
}
#pragma endregion

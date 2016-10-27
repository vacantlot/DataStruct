#include<iostream>
#include"seqStack.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{


#pragma endregion

	try {
#pragma region ����ƥ��
		/*SeqStack<char> seqstack;
		char r[] = { '{' , '}' , '{' , '{' , '{' , '}' , '(' , ')' , '}' , '}' };
		for (int i = 0; r[i] != '\0'; i++)
		{
			if (r[i] == '{' || r[i] == '}' || r[i] == '(' || r[i] == ')')
			{
				if (seqstack.Empty())
				{
					seqstack.Push(r[i]);
					continue;
				}
				if (seqstack.GetTop() == '{' && r[i] == '}')
				{
					seqstack.Pop(); continue;
				}
				if (seqstack.GetTop() == '(' && r[i] == ')')
				{
					seqstack.Pop(); continue;
				}
				seqstack.Push(r[i]);
			}
		}

		if (seqstack.Empty())
			cout << "1 ��������ƥ��ɹ���" << endl;
		else
			cout << "0 ����������Ҫƥ�䣡" << endl;*/

#pragma endregion

#pragma region ��������
		SeqStack<int> seqstack;
		int maxPackWeight = 10;
		int packageWeight = 0;
		int r[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
		int strLength = sizeof(r)/4;  //���鳤��
		
		/*for (int j = 0; r[j] != '\0'; j++)
		{
			seqstack.Clear();
			packageWeight = 0;
			for (int i = j; r[i] != '\0'; i++)
			{
				packageWeight += r[i];
				seqstack.Push(r[i]);
				if (packageWeight > maxPackWeight)
				{
					packageWeight -= r[i];
					seqstack.Pop();
					continue;
				}
				if (packageWeight == maxPackWeight)
				{
					cout << "�õ����������Ľ⡣";
					seqstack.PrintStack();
					cout << endl;
					seqstack.Pop();
				}
			}
		}*/
		int j = 1 ,i = 0;
		while (j <= strLength)
		{
			while (i <= strLength)
			{
				packageWeight += r[i];
				seqstack.Push(r[i]);
				if (packageWeight > maxPackWeight)
				{
					packageWeight -= r[i];
					seqstack.Pop();
					continue;
				}
				if (packageWeight == maxPackWeight)
				{
					cout << "�õ����������Ľ⡣";
					seqstack.PrintStack();
					cout << endl;
					seqstack.Pop();
				}
				i+=j;
			}
			j++;

		}

#pragma endregion

	}
	catch (char *S)
	{
		cout << S;
	}
	return 0;
}

//void KnapsackProblem(char r[],int maxPackWeight)
//{
//	int packageWeight = 0;
//	SeqStack<int> seqstack;
//	
//	for (int i = 0; r[i] != '\0'; i++)
//	{
//		packageWeight += r[i];
//		seqstack.Push(r[i]);
//		if (packageWeight>maxPackWeight)
//		{
//			packageWeight -= r[i];
//			seqstack.Pop();
//			continue;
//		}
//		if (packageWeight == maxPackWeight)
//		{
//			cout << "�õ����������Ľ⡣" << endl;
//			seqstack.PrintStack();
//			KnapsackProblem(r, maxPackWeight);
//		}
//	}
//}
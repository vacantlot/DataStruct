#include<iostream>
#include"seqStack.h"
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
int main()
{


#pragma endregion

	try {
#pragma region 括号匹配
		SeqStack<char> seqstack;
		//char r[] = { '{' , '}' , '{' , '{' , '{' , '}' , '(' , ')' , '}' , '}' };
		string r;
		cout<<"请输入欲匹配括号的字符："<<endl;
		cin >> r;
		/*char r[100];
		for (int i = 0; i < 100; i++)
		{
		cin>>r[i];
		}*/
		cout <<"你输入的是："<< r <<endl;
		for (int i = 0; i<r.length(); i++)
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
			cout << "1 所有括号匹配成功！" << endl;
		else
			cout << "0 还有括号需要匹配！" << endl;

#pragma endregion

#pragma region 背包问题
		//SeqStack<int> seqstack, order;
		//int T = 20;
		//int packageWeight = 0;
		//int r[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
		////int r[] = {1,2,1,2,3,4,6,7,8,5,6,7,8,9,10};
		//int strLength = sizeof(r) / 4;  //数组长度

		//for (int i = 0; i <= strLength; i++)
		//{

		//	if (i == strLength)
		//	{
		//		packageWeight -= seqstack.Pop();
		//		i = order.Pop() + 1;
		//		if (i == strLength && packageWeight != 0)
		//		{
		//			packageWeight -= seqstack.Pop();
		//			i = order.Pop() + 1;
		//		}
		//	}

		//	if (packageWeight + r[i] == T)
		//	{
		//		seqstack.Push(r[i]);
		//		seqstack.PrintStack();
		//		seqstack.Pop();
		//	}

		//	if (packageWeight + r[i] < T)
		//	{
		//		seqstack.Push(r[i]);
		//		order.Push(i);
		//		packageWeight += r[i];
		//	}
		//}

#pragma endregion
	}
	catch (char *S)
	{
		cout << S;
	}
	return 0;
}

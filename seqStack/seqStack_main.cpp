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
//#pragma region 括号匹配
//		SeqStack<char> seqstack;
//		string r;
//		cout<<"请输入欲匹配括号的字符："<<endl;
//		cin >> r;
//		cout <<"你输入的是："<< r <<endl;
//		for (int i = 0; i<r.length(); i++)
//		{
//			if (r[i] == '{' || r[i] == '}' || r[i] == '(' || r[i] == ')')
//			{//过滤除括号之外的其它字符
//				if (seqstack.Empty())
//				{//如果栈为空则进栈
//					seqstack.Push(r[i]);
//					continue;
//				}
//				//取栈顶，如果匹配则出栈
//				if (seqstack.GetTop() == '{' && r[i] == '}')
//				{
//					seqstack.Pop(); continue;
//				}
//				if (seqstack.GetTop() == '(' && r[i] == ')')
//				{
//					seqstack.Pop(); continue;
//				}
//				seqstack.Push(r[i]);
//			}
//		}
//		if (seqstack.Empty())
//			cout << "1 所有括号匹配成功！" << endl;
//		else
//			cout << "0 还有括号需要匹配！" << endl;
//
//#pragma endregion

#pragma region 背包问题
		SeqStack<int> seqstack  //seqstack记录存入背包中物品重量
			        , order;     //order记录存入背包中的物品重量对应在数组的下标
		const int T = 15 ;//T背包总容量
		int packageWeight = 0;//背包目前的重量
		int r[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };//物品
		int strLength = sizeof(r) / 4;  //计算数组长度
		for (int i = 0; i <= strLength; i++)
		{
			if (i == strLength)//当一次循环到数组尾时
			{
				packageWeight -= seqstack.Pop();//背包目前的重量减去最后一次存入的重量
				i = order.Pop() + 1;//i变成最后一次存入背包个物品重量对应在数组的下标+1
				if (i == strLength && packageWeight != 0)
				{//当变动后的i == strLength时，但背包里还有物品则再执行上一步
					packageWeight -= seqstack.Pop();
					i = order.Pop() + 1;
				}
			}
			if (packageWeight + r[i] == T)
			{//找到满足的总量就输出
				seqstack.Push(r[i]);
				seqstack.PrintStack();
				seqstack.Pop();
			}

			if (packageWeight + r[i] < T)
			{//当不满足则再加
				seqstack.Push(r[i]);
				order.Push(i);			
				packageWeight += r[i];
			}
		}

#pragma endregion
	}
	catch (char *S)
	{
		cout << S;
	}
	return 0;
}

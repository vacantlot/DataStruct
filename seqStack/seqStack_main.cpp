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
//#pragma region ����ƥ��
//		SeqStack<char> seqstack;
//		string r;
//		cout<<"��������ƥ�����ŵ��ַ���"<<endl;
//		cin >> r;
//		cout <<"��������ǣ�"<< r <<endl;
//		for (int i = 0; i<r.length(); i++)
//		{
//			if (r[i] == '{' || r[i] == '}' || r[i] == '(' || r[i] == ')')
//			{//���˳�����֮��������ַ�
//				if (seqstack.Empty())
//				{//���ջΪ�����ջ
//					seqstack.Push(r[i]);
//					continue;
//				}
//				//ȡջ�������ƥ�����ջ
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
//			cout << "1 ��������ƥ��ɹ���" << endl;
//		else
//			cout << "0 ����������Ҫƥ�䣡" << endl;
//
//#pragma endregion

#pragma region ��������
		SeqStack<int> seqstack  //seqstack��¼���뱳������Ʒ����
			        , order;     //order��¼���뱳���е���Ʒ������Ӧ��������±�
		const int T = 15 ;//T����������
		int packageWeight = 0;//����Ŀǰ������
		int r[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };//��Ʒ
		int strLength = sizeof(r) / 4;  //�������鳤��
		for (int i = 0; i <= strLength; i++)
		{
			if (i == strLength)//��һ��ѭ��������βʱ
			{
				packageWeight -= seqstack.Pop();//����Ŀǰ��������ȥ���һ�δ��������
				i = order.Pop() + 1;//i������һ�δ��뱳������Ʒ������Ӧ��������±�+1
				if (i == strLength && packageWeight != 0)
				{//���䶯���i == strLengthʱ���������ﻹ����Ʒ����ִ����һ��
					packageWeight -= seqstack.Pop();
					i = order.Pop() + 1;
				}
			}
			if (packageWeight + r[i] == T)
			{//�ҵ���������������
				seqstack.Push(r[i]);
				seqstack.PrintStack();
				seqstack.Pop();
			}

			if (packageWeight + r[i] < T)
			{//�����������ټ�
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

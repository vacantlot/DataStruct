#include<iostream>
#include"Seqlist.h"
using namespace std;
void PrintYH();
int main(void)
{
	/*int a[9] = {1,2,3,4,5,6,7,8,9};
	SeqList<int> sqe(a,9);*/
	//SeqList<int> sqe = SeqList<int>(a,9);
#pragma region  ˳����������	
	//SeqList<int> seq;

	//int i, j, yh_array[10][10];
	//for (i = 0; i <= 9; i++)
	//	for (j = 0; j <= 9; j++)
	//	{
	//		yh_array[i][0] = 1;
	//		yh_array[i][i] = 1;
	//	}
	//for (i = 2; i <= 9; i++)
	//	for (j = 1; j <= i - 1; j++)
	//	{
	//		yh_array[i][j] = yh_array[i - 1][j - 1] + yh_array[i - 1][j];

	//	}
	//for (i = 0; i <= 9; i++)
	//{
	//	for (j = 0; j <= i; j++)
	//	{
	//		cout << yh_array[i][j] << "\t";

	//		//seq.Add(yh_array[i][j]);			

	//	}cout << endl;

	//}
	//seq.PrintList();
#pragma endregion
	cout << "������ʮ��������" << endl;
	int r[20];
	for (int i = 0; i < 10; i++)
	{
		cin >> r[i];
	}
	SeqList<int> seq(r,10);
	cout << "���ֵΪ��";
	seq.PrintList();
	cout << "\n***����***\n"<<"������Ҫ���ҵ�ֵ��";
	int key;
	cin >> key;
	cout << "����λ�ã�"<<seq.Locate(key);
	cout << "\n***����***\n" << "������Ҫ�����λ�ú�ֵ��";
	int loc = 0 , x;
	cin >> loc >> x;
	cout << "����ǰ��";
	seq.PrintList();
	seq.Insert(loc, x);
	cout << "\n�����";
	seq.PrintList();
	cout << "\n***ɾ��***\n" << "������Ҫɾ������λ�ã�";
	cin >> loc;
	cout << "ɾ��ǰ��";
	seq.PrintList();
	seq.Delete(loc);
	cout << "\nɾ����";
	seq.PrintList();


	return 0;
}


#include<iostream>
#include"Seqlist.h"
using namespace std;
void PrintYH();
int main(void)
{
	/*int a[9] = {1,2,3,4,5,6,7,8,9};
	SeqList<int> sqe(a,9);*/
	//SeqList<int> sqe = SeqList<int>(a,9);
#pragma region  顺序表杨辉三角	
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
	cout << "请输入十个整数：" << endl;
	int r[20];
	for (int i = 0; i < 10; i++)
	{
		cin >> r[i];
	}
	SeqList<int> seq(r,10);
	cout << "结点值为：";
	seq.PrintList();
	cout << "\n***查找***\n"<<"输入你要查找的值：";
	int key;
	cin >> key;
	cout << "结点的位置："<<seq.Locate(key);
	cout << "\n***插入***\n" << "输入你要插入的位置和值：";
	int loc = 0 , x;
	cin >> loc >> x;
	cout << "插入前：";
	seq.PrintList();
	seq.Insert(loc, x);
	cout << "\n插入后：";
	seq.PrintList();
	cout << "\n***删除***\n" << "输入你要删除结点的位置：";
	cin >> loc;
	cout << "删除前：";
	seq.PrintList();
	seq.Delete(loc);
	cout << "\n删除后：";
	seq.PrintList();


	return 0;
}


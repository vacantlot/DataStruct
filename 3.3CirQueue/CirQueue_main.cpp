#include "LinkedQueue.h"
#include <iostream>
using namespace std;



int main()
{
#pragma region 输出杨辉三角
	LinkQueue<int> YH;
	YH.EnQueue(1);
	int a;
	cout << "请输入要输出的行数";
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		YH.Show();//输出已存入队列的值
		for (int count = 1; count <= i - 1; count++)
		{
			YH.EnQueue(YH.DeQueue() + YH.GetQueue());
		}
		YH.EnQueue(1);
	}
	
	return 0;
#pragma endregion

}
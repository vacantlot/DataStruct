#include "LinkedQueue.h"
#include <iostream>
using namespace std;



int main()
{
#pragma region ����������
	LinkQueue<int> YH;
	YH.EnQueue(1);
	int a;
	cout << "������Ҫ���������";
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		YH.Show();//����Ѵ�����е�ֵ
		for (int count = 1; count <= i - 1; count++)
		{
			YH.EnQueue(YH.DeQueue() + YH.GetQueue());
		}
		YH.EnQueue(1);
	}
	
	return 0;
#pragma endregion

}
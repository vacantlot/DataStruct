#include "LinkedQueue.h"
#include <iostream>
using namespace std;
#pragma region ����������

#pragma endregion

int main()
{
	LinkQueue<int> PT;
	PT.EnQueue(1);
	int a;
	cout << "���������������";
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		PT.Show();
		for (int count = 1; count <= i - 1; count++)
		{
			PT.EnQueue(PT.DeQueue() + PT.GetQueue());
		}
		PT.EnQueue(1);
	}
	
	return 0;

}
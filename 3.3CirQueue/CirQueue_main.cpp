#include "CirQueue.h"
#include <iostream>
using namespace std;

int main()
{
	int r[] = { 1,2,3,4,5,6,7,8,9 };

	CirQueue<int> queue;

	for each (int num in r)
	{
		queue.EnQueue(num);
	}
	cout<< queue.DeQueue()<<endl;
	cout << queue.IsEmpty();
	return 0;

}
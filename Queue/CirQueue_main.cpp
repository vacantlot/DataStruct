#include "CirQueue.h"
using namespace std;
int main()
{
	int r[] = { 1,2,3,4,5,6,7,8,9 };
	CirQueue<int> queue;

	for each (int num in r)
	{
		queue.EnQueue(num);
	}
	queue.DeQueue();

}
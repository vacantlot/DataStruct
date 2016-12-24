#include<iostream>
#include "linkStack.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	try
	{
		int a[] = { 1,2,3,4,5,6,7,8,9,10 };

		//LinkStack<int>  *linkstack = new LinkStack<int>; 
		LinkStack<int> aa; 
		//linkstack->Push(3);
	    aa.Push(4); 
		aa.Push(5);
		aa.Push(6);
		aa.Push(7);
		for (int i = 0 ; i <  100; i++)
		{
			aa.Push(i);
		}
		cout << aa.GetTop()<<endl;
		cout << aa.Pop();	cout << endl;
		aa.PrintStack();
		cout << endl;
		cout << aa.GetTop();
	}
	catch (char* e)
	{
		cout << e<<endl;
	}
	cin.ignore();
}
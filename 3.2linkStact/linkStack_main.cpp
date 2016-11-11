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

		LinkStack<int>  *listack;
		LinkStack<int> *aa = new LinkStack<int>;
		listack.Push(3);
		//aa->Push(3);
		//cout << aa->Pop();
	}
	catch (char* e)
	{
		cout << e<<endl;
	}
	cin.ignore();
}
#include"staticLinkedList.h"
#include<iostream>
using namespace std;
int main()
{
	try
	{
		int r[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		StaticLinkedList<int> staticlinkedlist;
		staticlinkedlist.initList(r, 10);
		staticlinkedlist.PrintList();
		cout << endl;
		staticlinkedlist.Insert(90,4);
		staticlinkedlist.PrintList();
		cout << endl;
		staticlinkedlist.Delete(4);
		staticlinkedlist.PrintList();
		cout << endl;
	}
	catch (char *s)
	{
		cout << s;
	}
	
}
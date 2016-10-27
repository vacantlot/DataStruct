#include<iostream>
#include"seqStack.h"
using namespace std;
int main() {
	int r[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	SeqStack<int> seqstack;
	for (int i = 0; i < 10; i++)
	{
		seqstack.Push(r[i]);
	}
	cout<<seqstack.GetTop();
		
       
	
}
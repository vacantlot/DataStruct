#include <iostream>
#include <stdio.h>
#include <string>
#define MAXD 100
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Node
{
public:
	Node(int Length , char str[])
	{	
		for (int i = 0; i < 100 ; i++)
		{			
			if (str[i] == '\0')
			{
				while (i<100)
				{
					data[i++] = 0;
				}
				break;
			}
			data[i] = str[i] - '0';
		}
		length = Length;
	};
	Node() 
	{
		length = 0;
		for (int i = 0 ; i < 100; i++)
		{
			data[i] = 0;
		} 
	};
	int length;
	int data[100];
};


int main(int argc, char** argv) 
{
//	ANode A;
//	BNode B;
//	A.data[0] = 10;
//	for( int i = 0 ; i < 10 ; i++)
//	{
//		cout << A.data[i] <<" " << B.data[i];
//	}
//	

//for(i=1;(x%(int)(pow(10,i)))==0;)
//int k = 12345678;

char s1[100];
cout<<"input A:"<<endl;
cin >> s1;
cout<<"input B:"<<endl;
char s2[100];
cin >> s2;

Node A(strlen(s1) , s1);
Node B(strlen(s2) , s2);
Node C;

//sprintf(s, "%d", k); //产生"k"
//string str = s;
////	for( int i = 0 ; i < str.length() ; i++)
////	{
////		cout << str;
////	}
int flag = 0;//进位
int MINSIZE = A.length > B.length ? B.length : A.length;
int MAXSIZE = A.length > B.length ? A.length : B.length;
for(int i = MAXSIZE ;i >= 0 ; i--)
{
	C.data[i] += A.data[i] + B.data[i];
	if (C.data[i] >= 10) //如果某位的数大于9，则将这一位减10，然后将高位加1
	{
		C.data[i] -= 10;
		C.data[i + 1]++;
	}
	cout << C.data[i];
}
	return 0;
}

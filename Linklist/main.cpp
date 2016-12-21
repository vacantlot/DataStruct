#include<iostream>
#include"LinkList.h"
using namespace std;

int main()
{
	/*cout<<"请输入二十个整数："<<endl;
	int r[20];
	for (int i = 0; i < 20; i++)
	{
		cin>>r[i];
	}*/
	int r[20] = {1,2,3,4,5,7,7,8,9,10,11,12,14,14,15,16,17,19,19,20};
	try{
	LinkList<int> link(r,20);
	cout<<"链表结点的信息为：";
	link.PrintList();
		cout<<endl;
	cout<<"请输入你要查询的结点位置数："<<endl;
	int key = 0 ;
	cin>>key;
	cout<<"找到了  "<<endl<<"值为："<<link.Get(key)<<endl;
	cout<<"请输入2个整数，一个表示欲插入的位置，另一个表示欲插入的数值（空格隔开）："<<endl;
	int loaction = 0 , x = 0;
	cin>>loaction>>x;
	link.Insert(loaction,x);
	link.PrintList();
	cout<<endl;
	cout<<"请输入你要删除的结点位置："<<endl;
	int del = -1;
	cin>>del;
	link.Delete(del);
	link.PrintList();
	cout<<endl;
	cout<<"*删除重复的结点*"<<endl;
	cout<<"删除前："<<endl;
	link.PrintList();
	
	for (int i = 0; i < link.Length(); i++)
	{
		int del = -1;
		del = link.SearchRepeat();
		if(del != -1) link.Delete(del);		
	}
	cout << endl;
	cout<<"删除重复后："<<endl;
	link.PrintList();
	cout<<endl;
	cout<<"删除值为偶数的结点："<<endl;
	for (int i = 0; i < link.Length(); i += 2)
	{
		int del = -1;
		del = link.SearchEven();  //SearchEven查找奇数
		if(del != -1) link.Delete(del);		
	}
	cout<<"删除后："<<endl;
	link.PrintList();
	cout<<endl;
	}
	catch(char *S)
	{
		cout<<S<<endl;
	}

}
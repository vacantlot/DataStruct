#include<iostream>
#include"LinkList.h"
using namespace std;

int main()
{
	/*cout<<"�������ʮ��������"<<endl;
	int r[20];
	for (int i = 0; i < 20; i++)
	{
	cin>>r[i];
	}*/
	int r[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	try {
		LinkList<int> link(r, 20);
		cout << "���������ϢΪ��";
		link.PrintList();
		cout << endl;
		LinkList<int> linkA;
		LinkList<int> linkB;
		
		for (int i = 1; i <= link.Length(); i++)
		{
			if (i % 2 == 0)
				linkA.addListNode(link.Get(i));
			else
				linkB.addListNode(link.Get(i));
		}
		cout << "����A������ϢΪ��";
		linkA.PrintList();
		cout << endl;
		cout << "����B������ϢΪ��";
		linkB.PrintList();
		cout << endl;
		     
		/*cout<<"���Ϊż���Ľڵ�:";
		link.PrintList(doub);
		cout<<"���Ϊ�����Ľڵ�:";
		link.PrintList(single);*/

		/*cout<<"��������Ҫ��ѯ�Ľ��λ������"<<endl;
		int key = 0 ;
		cin>>key;
		cout<<"�ҵ���  "<<endl<<"ֵΪ��"<<link.Get(key)<<endl;
		cout<<"������2��������һ����ʾ�������λ�ã���һ����ʾ���������ֵ���ո��������"<<endl;
		int loaction = 0 , x = 0;
		cin>>loaction>>x;
		link.Insert(loaction,x);
		link.PrintList();
		cout<<endl;
		cout<<"��������Ҫɾ���Ľ��λ�ã�"<<endl;
		int del = -1;
		cin>>del;
		link.Delete(del);
		link.PrintList();
		cout<<endl;
		cout<<"*ɾ���ظ��Ľ��*"<<endl;
		cout<<"ɾ��ǰ��"<<endl;
		link.PrintList();

		for (int i = 0; i < link.Length(); i++)
		{
		int del = -1;
		del = link.SearchRepeat();
		if(del != -1) link.Delete(del);
		}
		cout<<"ɾ���ظ���"<<endl;
		link.PrintList();
		cout<<endl;
		cout<<"ɾ��ֵΪż���Ľ�㣺"<<endl;
		for (int i = 0; i < link.Length(); i += 2)
		{
		int del = -1;
		del = link.SearchEven();
		if(del != -1) link.Delete(del);
		}
		cout<<"ɾ����"<<endl;
		link.PrintList();
		cout<<endl;*/
	}
	catch (char *S)
	{
		cout << S << endl;
	}

}
#pragma once
/************************************************************************/
/* ��̬����                                                             */
/************************************************************************/

#include<iostream>
using namespace std;
const int MaxSize = 100;
template<typename DataType>
struct SNode
{
	DataType data;
	int next;
};

template<typename DataType>
class StaticLinkedList
{
public:
	StaticLinkedList();
	~StaticLinkedList();
	void initList(DataType a[] ,int n);
	void PrintList();
	void Insert(DataType x , int p);
	DataType Delete(DataType);
private:
	SNode<DataType> SList[MaxSize];
	DataType avail;
};



template<typename DataType>
StaticLinkedList<DataType>::StaticLinkedList()
{
	SNode<DataType> SList[MaxSize];
	
}

template<typename DataType>
inline StaticLinkedList<DataType>::~StaticLinkedList()
{
	delete[] SList;
}


template<typename DataType>
void StaticLinkedList<DataType>::initList(DataType a[], int n)
{
	for (int i = 0; i < MaxSize - 1; i++)
	{
		SList[i].next = i + 1;
		SList[i].data = 1;
	}
	SList[MaxSize-1].next = NULL;
	for ( int i = 0; i < n; i++)
	{
		SList[i].data = a[i];		
	}
	SList[n].next = NULL;
	avail = n+1;		
}

template<typename DataType>
void StaticLinkedList<DataType>::PrintList()
{
	int i = 0;
	while (SList[i].next != NULL)
	{
       
		cout << SList[i].data << " ";
		i = SList[i].next;
	}
}

template<typename DataType>
inline void StaticLinkedList<DataType>::Insert(DataType x ,int p)
{
	if (p>avail-1||p<0)
	{
		throw "λ�ô���";
	}
	p --;
	int s = avail;                   //���ÿ����ĵ�һ�����
	avail = SList[avail].next;       //��������ͷָ�����
	SList[s].data = x;
	SList[s].next = SList[p].next;
	SList[p].next = s;
	
	SList[avail].next = NULL;
}

template<typename DataType>
inline DataType StaticLinkedList<DataType>::Delete(DataType x)
{
	int p = --x;
	int q = SList[p].next;
	SList[p].next = SList[q].next;
	SList[q].next = avail;
	avail = q;
	return x;
}



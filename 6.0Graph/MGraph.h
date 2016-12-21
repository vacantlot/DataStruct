#pragma once
#include "..\3.3CirQueue\CirQueue.h"
const int MaxSize = 10;    // ��󶥵���

struct ArcNode
{
	int adjvex;        //��ӵ���
	ArcNode *next;
};

template<typename DataType>
struct VertexNode         // ���嶥�����
{
	DataType vertex;
	ArcNode *firstedge;
};

template<typename DataType>
class ALGraph
{
public:
	ALGraph(DataType a[] , int n , int e);        //����һ����n������e���ߵ�ͼ
	~ALGraph();
	void DFSTraverse(int v);    //������ȱ���ͼ
	void BFSTraverse(int v);    //������ȱ���ͼ

private:
	VertexNode<DataType> adjlist[MaxSize];   //��Ŷ��������
	int vertexNum, arcNum;  //ͼ�Ķ���ͱ���
	
};

template<typename DataType>
ALGraph<DataType>::ALGraph(DataType a[], int n, int e)
{
	ArcNode *s;
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	for ( i = 0; i < vertexNum; i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = nullptr;		
	}
	for ( k = 0 ; k < arcNum ; k++)
	{
		cout << "������ߵ������������:";
		cin >> i >> j;               //���������������������ı��
		 s = new ArcNode(); 
		s->next = adjlist[i].firstedge;   //�����s���뵽��i���߱�ı�ͷ
		adjlist[i].firstedge = s;
	}
}
template<typename DataType>
ALGraph<DataType>::~ALGraph()
{
	ArcNode *p = nullptr;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjlist[i].firstedge;
		while (p != nullptr)   //ɾ����i����
		{
			adjlist[i].firstedge = p->next;
			delete p;
			p = adjlist[i].firstedge;
		}
	}
}

template<typename DataType>
inline void ALGraph<DataType>::DFSTraverse(int v)
{
	ArcNode *p = nullptr;
	int j;
	cout << adjlist[v].vertex;
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p != nullptr)
	{
		j = p->adjvex;
		if (visited[j] == 0)
		{
			DFSTraverse(j);
		}
		p = p->next;
	}

}

template<typename DataType>
inline void ALGraph<DataType>::BFSTraverse(int v)
{
	int Q[MaxSize];    //������в���˳��洢
	int front = -1;    //��ʼ������
	int rear = -1;
	ArcNode *p = nullptr;
	cout << adjlist[v].vertex;
	visited[v] = 1;
	Q[++rear] = v;  //�����ʵĶ������
	while (front != rear)    //�����зǿ�ʱ
	{
		v = Q[++front];
		p = adjlist[v].firstedge;
		while (p != nullptr)
		{
			int j = p->adjvex;       //j�Ƕ���v����ӵ�
			if (visited[j] == 0)
			{
				cout << adjlist[j].vertex;
				visited[j] = 1;
				Q[++rear] = j;
			}
			p = p->next;
		}
	}
}

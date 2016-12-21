#pragma once
#include "..\3.3CirQueue\CirQueue.h"
const int MaxSize = 10;    // 最大顶点数

struct ArcNode
{
	int adjvex;        //领接点域
	ArcNode *next;
};

template<typename DataType>
struct VertexNode         // 定义顶点表结点
{
	DataType vertex;
	ArcNode *firstedge;
};

template<typename DataType>
class ALGraph
{
public:
	ALGraph(DataType a[] , int n , int e);        //构造一个有n个顶点e条边的图
	~ALGraph();
	void DFSTraverse(int v);    //深度优先遍历图
	void BFSTraverse(int v);    //广度优先遍历图

private:
	VertexNode<DataType> adjlist[MaxSize];   //存放顶点表数据
	int vertexNum, arcNum;  //图的顶点和边数
	
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
		cout << "请输入边的两个顶点序号:";
		cin >> i >> j;               //输入边所依附的两个顶点的编号
		 s = new ArcNode(); 
		s->next = adjlist[i].firstedge;   //将结点s插入到第i个边表的表头
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
		while (p != nullptr)   //删除第i个边
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
	int Q[MaxSize];    //假设队列采用顺序存储
	int front = -1;    //初始化队列
	int rear = -1;
	ArcNode *p = nullptr;
	cout << adjlist[v].vertex;
	visited[v] = 1;
	Q[++rear] = v;  //被访问的顶点入队
	while (front != rear)    //当队列非空时
	{
		v = Q[++front];
		p = adjlist[v].firstedge;
		while (p != nullptr)
		{
			int j = p->adjvex;       //j是顶点v的领接点
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

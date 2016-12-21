#ifndef LinkedList_H
#define LinkedList_H
#include<iostream>   //引用输入输出流库函数的头文件


// 链表的结点结构
template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType> *prior , *next;
};

template <typename DataType>
class LinkedList
{
public:
	LinkedList();					//无参构造函数，建立只有头结点的空链表
	LinkedList(DataType a[], int n);	//有参构造函数，建立有n个元素的单链表
	~LinkedList();					//析构函数
	int Length();					//线性表的长度
	DataType Get(int i);			//按位查找。
	int Locate(DataType x);			//按值查找。在单链表中查找值为x的元素序号
	void Insert(int i, DataType x);	//插入操作，第i个位置插入元素值为x的结点
	DataType Delete(int i);			//删除操作，在单链表中删除第i个结点
	void PrintList();				//遍历操作，按序号依次输出各元素
private:
	Node<DataType> *first;             //单链表的头指针
};

template <typename DataType>
LinkedList<DataType> ::LinkedList()
{
	first = new Node<DataType>;			//生成头结点
														
	first->next = ptrptr; //头结点后驱置为空
	first->prior = ptrptr;//头结点前驱置为空
}

template <typename DataType>
LinkedList<DataType> ::LinkedList(DataType a[], int n)
{
	Node<DataType> *r, *s;
	first = new Node<DataType>;		//生成头结点
	r = first;						//尾指针初始化
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; 
		s->data = a[i];        //为每个数组元素建立一个结点
		s->prior = r;
		r->next = s;
		
		r = s;                 //将结点s插入到终端结点之后
	}
	r->next = first;//链表建立完毕，将终端结点的指针域置空
	first->prior = r;//头结点prior指向最后一个结点
	first->data = nullptr; //头结点的数据域置为空
}

template <typename DataType>
LinkedList<DataType> :: ~LinkedList()
{
	Node<DataType> *q = first->next ,*s ;
	while (q != first)	// 释放单链表的每一个结点的存储空间
	{
		s = q;		// 暂存被释放结点
		q = q->next;	// first指向被释放结点的下一个结点
		delete s;
	}
	delete first;
}

template<typename DataType>
inline int LinkedList<DataType>::Length()
{
	int count = 0;	// 累加器count初始化
	Node<DataType> *p = first->next;	// 工作指针，初始指向第一个元素
	while (p != first)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<typename DataType>
inline DataType LinkedList<DataType>::Get(int i)
{
	int count = 1;	// 累加器count初始化
	Node<DataType> *p = first->next;	// 工作指针，初始指向第一个元素
	while (p != first && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == first)
		throw "位置异常";
	else
		return p->data;
}

template <typename DataType>
int LinkedList<DataType> ::Locate(DataType x)
{
	Node<DataType> *p = first->next;
	int count = 1;         //工作指针p和累加器count初始化
	while (p != first)
	{
		if (p->data == x) return count;     //查找成功，结束函数并返回序号
		p = p->next;
		count++;
	}
	return 0;                        //退出循环表明查找失败
}

template <typename DataType>
void LinkedList<DataType> ::Insert(int i, DataType x)
{
	Node<DataType> *p = first, *s;
	int count = 0;               //工作指针p应指向头结点
	while (count < i - 1)  //查找第i - 1个结点
	{
		p = p->next;                   //工作指针p后移
		count++;
	}
	if (p == first) throw "位置异常";      //没有找到第i - 1个结点
	else {
		s = new Node<DataType>; 
		s->data = x;   //申请一个结点s，其数据域为x
		s->next = p->next;
		s->prior = p;
		p->next->prior = s;
		p->next = s;   //将结点s插入到结点p之后
	}
}

template <typename DataType>
DataType LinkedList<DataType> ::Delete(int i)
{
	Node<DataType> *p, *q;
	DataType x;
	int count = 0;
	p = first;               // 注意工作指针p要指向头结点
	while (count < i - 1)  // 查找第i-1个结点
	{
		p = p->next;
		count++;
	}
	if (p == first)	// 结点p不存在
	{
		throw "位置异常";
	}
	else
	{
		q = p->next; 
		x = q->data;			// 暂存被删结点
		p->next = q->next;
		q->next->prior = p; //摘链
		delete q;
		return x;
	}
}

template <typename DataType>
void LinkedList<DataType> ::PrintList()
{
	using std::cout;
	using std::endl;
	Node<DataType> *p = first->next;	//工作指针p初始化
	while (p != first)
	{
		cout << p->data << "  ";
		p = p->next;	//工作指针p后移，注意不能写作p++
	}
	cout << endl;
}

#endif


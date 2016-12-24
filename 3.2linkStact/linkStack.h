#pragma once
template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template <class DataType>       //定义模板类LinkStack
class LinkStack
{
public:
	LinkStack() { top = nullptr; }            //构造函数，栈的初始化
	~LinkStack();            //析构函数
	void Push(DataType x);          //将元素x入栈
	DataType Pop();                //将栈顶元素弹出
	DataType GetTop() { if (top != nullptr) return top->data; }  //取栈顶元素（并不删除）
	int Empty() { return top == nullptr ? 1 : 0; }           //判断栈是否为空
	void PrintStack();
	void Inverse(Node<DataType> *p);//递归反向输出栈
private:
	Node<DataType> *top;                //栈顶指针，即链栈的头指针
};

template <class DataType>
LinkStack<DataType>::~LinkStack()
{
	Node<DataType> *q;
	while (top != nullptr)	// 释放单链表的每一个结点的存储空间
	{
		q = top;				// 暂存被释放结点
		top = top->next;	// first指向被释放结点的下一个结点
		delete q;
	}
}

// 入栈操作：链栈的插入操作只需处理栈顶即第一个位置的情况，而无需考虑其他位置的情况。
template <class DataType>
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType> *s = new Node<DataType>; s->data = x; //申请一个数据域为x的结点s
	s->next = top; top = s; //将结点s插入到栈顶
}

// 出栈操作：链栈的删除操作只需处理栈顶即第一个位置的情况，而无需考虑其他位置的情况。
template <class DataType>
DataType LinkStack<DataType>::Pop()
{
	Node<DataType> *p;
	if (top == nullptr)
		throw "下溢";
	DataType x = top->data;
	p = top;
	top = top->next;
	delete p;
	return x;
}

template<class DataType>
inline void LinkStack<DataType>::PrintStack()
{
	Node<DataType> *p = top;
	/*while (true)
	{
		if (p != nullptr)
			cout<<p->data;
		else
		{
			break;
		}
		p = p->next;
	}*/
	Inverse(p);
	
}

template<class DataType>
inline void LinkStack<DataType>::Inverse(Node<DataType>* p)
{
	if (p->next != nullptr)			
		Inverse(p->next);
	cout << p->data;
	
}



//template <typename DataType>
//struct Node
//{
//	DataType data;
//	Node<DataType> *next;
//};
//
//template <typename DataType>
//class LinkStack
//{
//public:
//	LinkStack() { top = nullptr; }
//	~LinkStack();
//	void Push(DataType x);
//	DataType Pop();
//	DataType GetTop() { if (top != nullptr) return top->data; }
//	int Empty() { top == nullptr ? return 1 : return 0; }
//private:
//
//	Node<DataType> *top;
//};
//
//
//template <typename DataType>
//LinkStack<DataType>::~LinkStack()
//{
//	Node<DataType> *p;
//	while (top != nullptr)
//	{
//		p = top;
//		top = top->next;
//		delete p;
//	}
//}
//
//template<typename DataType>
//inline void LinkStack<DataType>::Push(DataType x)
//{
//	Node<DataType> s;
//	s->data = x;
//	s->next = top;
//	top = s;
//}
//
//template<typename DataType>
//inline DataType LinkStack<DataType>::Pop()
//{
//	Node<DataType> *p;
//	if (top == nullptr)
//	{
//		throw "下溢";
//	}
//	DataType x = top->data;
//	p = top;
//	top = top->next;
//	delete p;
//	return x;
//}
//
//


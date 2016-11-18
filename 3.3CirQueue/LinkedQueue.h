#pragma once
template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template <typename DataType>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(DataType x);
	DataType DeQueue();
	DataType GetQueue();
	int IsEmpty() {return front == rear ? 1 : 0; }
	void Show();
private:
	Node<DataType> *front, *rear;
};

template <typename DataType>
LinkQueue<DataType>::LinkQueue()
{
	Node<DataType> *s = new Node<DataType>;
	s->next = nullptr;
	front = rear = s;     //将队头指针和队尾指针都指向头结点s
}

template<typename DataType>
inline LinkQueue<DataType>::~LinkQueue()
{
	Node<DataType> *p;
	while (front != nullptr)
	{
		p = front;
		front = front->next;
		delete p;
	}
}

template<typename DataType>
inline void LinkQueue<DataType>::EnQueue(DataType x)
{
	Node<DataType> *s = new Node<DataType>; //new一个新结点
	s->data = x;
	rear->next = s;  //将结点s插入到队尾
	rear = s;
	s->next = nullptr;
}

template<typename DataType>
inline DataType LinkQueue<DataType>::DeQueue() // 出队列操作：链队列的删除操作只需处理队列顶即第一个位置的情况，而无需考虑其他位置的情况
{
	Node<DataType> *p;
	if (rear == front)
	{
		throw "下溢";
	}
	p = front->next;
	DataType x = p->data;
	front->next = p->next;
	if (p->next == nullptr)
	{
		rear = front;
	}
	delete p;
	return x;
}

template<typename DataType>
inline DataType LinkQueue<DataType>::GetQueue() //取队头元素
{
	return front->next->data;
}

template <class DataType>
void LinkQueue<DataType>::Show()
{
	Node <DataType> *s;
	s = front->next;
	for (; s != nullptr; s = s->next)cout << s->data << "\t";
	cout << "\n";

}
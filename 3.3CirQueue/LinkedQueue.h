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
	front = rear = s;     //����ͷָ��Ͷ�βָ�붼ָ��ͷ���s
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
	Node<DataType> *s = new Node<DataType>; //newһ���½��
	s->data = x;
	rear->next = s;  //�����s���뵽��β
	rear = s;
	s->next = nullptr;
}

template<typename DataType>
inline DataType LinkQueue<DataType>::DeQueue() // �����в����������е�ɾ������ֻ�账����ж�����һ��λ�õ�����������迼������λ�õ����
{
	Node<DataType> *p;
	if (rear == front)
	{
		throw "����";
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
inline DataType LinkQueue<DataType>::GetQueue() //ȡ��ͷԪ��
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
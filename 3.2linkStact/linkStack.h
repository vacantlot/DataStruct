#pragma once
template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template <class DataType>       //����ģ����LinkStack
class LinkStack
{
public:
	LinkStack() { top = nullptr; }            //���캯����ջ�ĳ�ʼ��
	~LinkStack();            //��������
	void Push(DataType x);          //��Ԫ��x��ջ
	DataType Pop();                //��ջ��Ԫ�ص���
	DataType GetTop() { if (top != nullptr) return top->data; }  //ȡջ��Ԫ�أ�����ɾ����
	int Empty() { return top == nullptr ? 1 : 0; }           //�ж�ջ�Ƿ�Ϊ��
	void PrintStack();
	void Inverse(Node<DataType> *p);//�ݹ鷴�����ջ
private:
	Node<DataType> *top;                //ջ��ָ�룬����ջ��ͷָ��
};

template <class DataType>
LinkStack<DataType>::~LinkStack()
{
	Node<DataType> *q;
	while (top != nullptr)	// �ͷŵ������ÿһ�����Ĵ洢�ռ�
	{
		q = top;				// �ݴ汻�ͷŽ��
		top = top->next;	// firstָ���ͷŽ�����һ�����
		delete q;
	}
}

// ��ջ��������ջ�Ĳ������ֻ�账��ջ������һ��λ�õ�����������迼������λ�õ������
template <class DataType>
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType> *s = new Node<DataType>; s->data = x; //����һ��������Ϊx�Ľ��s
	s->next = top; top = s; //�����s���뵽ջ��
}

// ��ջ��������ջ��ɾ������ֻ�账��ջ������һ��λ�õ�����������迼������λ�õ������
template <class DataType>
DataType LinkStack<DataType>::Pop()
{
	Node<DataType> *p;
	if (top == nullptr)
		throw "����";
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
//		throw "����";
//	}
//	DataType x = top->data;
//	p = top;
//	top = top->next;
//	delete p;
//	return x;
//}
//
//


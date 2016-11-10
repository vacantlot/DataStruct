#pragma once
template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template <typename DataType>
class LinkStack
{
public:
	LinkStack() { top = nullptr; }
	~LinkStack();
	void Push(DataType x);
	DataType Pop();
	DataType GetTop() { if (top != nullptr) return top->data; }
	int Empty() { top == nullptr ? return 1 : return 0; }

private:

	Node<DataType> *top;
};


template <typename DataType>
LinkStack::~LinkStack()
{
}

template<typename DataType>
inline void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType> s = new Node<DataType>;
	s->data = x;
	s->next = top;
	top = s;
}

template<typename DataType>
inline DataType LinkStack<DataType>::Pop()
{
	Node<DataType> *p = nullptr;
	if (top == nullptr)
	{
		throw "ÏÂÒç";
	}
	int x = top->data;
	p = top;
	top = top->next;
	delete p;
	return x;
}

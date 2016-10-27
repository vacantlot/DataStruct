#pragma once
const int StackSize = 100;
template<typename DataType>
class SeqStack
{
public:
	SeqStack() { top = -1; };
	//~SeqStack();
	void Push(DataType x);
	DataType Pop();
	DataType GetTop() { if (top != -1) return data[top]; }
	int Empty() { top == -1 ? return 1 : return 0; }
private:
	DataType data[StackSize];
	int top;
};





template<typename DataType>
inline void SeqStack<DataType>::Push(DataType x)
{
	if (top == StackSize - 1)throw "иорГ";
	data[++top] = x;
}

template<typename DataType>
inline DataType SeqStack<DataType>::Pop()
{
	if (top == -1) throw "обрГ";
	DataType x = data[top--];
	return x;
}

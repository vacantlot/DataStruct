#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

//定义顺序栈类模板
template <typename ElemType>//声明一个类模板
class SeqStack
{
public://顺序栈类的各成员函数
	SeqStack(int n = 100);
	~SeqStack();
	void Clear();
	bool Empty();
	int Length() const;
	ElemType & GetTop() const;
	void Push(const ElemType &e);
	ElemType Pop();
	void PrintStack();
private://顺序栈类的数据成员
	ElemType *m_base;			//基地址指针
	int m_top;					//栈顶指针
	int m_size;					 //向量空间大小
};

//构造函数，分配n个结点的顺序空间，构造一个空的顺序栈。
template <class ElemType>
SeqStack <ElemType>::SeqStack(int n)
{
	m_top = -1;
	m_base = new ElemType[n];
	m_size = n;
}//SqStack

 //析构函数，将栈结构销毁。
template <class ElemType>
SeqStack <ElemType>::~SeqStack()
{
	if (m_base != nullptr) delete[] m_base;
}//~SqStack

 //判栈是否为空，若为空，则返回true，否则返回false。
template <class ElemType>
bool SeqStack <ElemType>::Empty() 
{
	if(m_top == -1)
		return true;
	else
	{
		return false;
	}
}//Empty

 //清空栈。
template <class ElemType>
void SeqStack <ElemType>::Clear() 
{
	 m_top = -1;
}//Clear

 //求栈的长度。
template <class ElemType>
int SeqStack <ElemType>::Length() const
{
	return m_top + 1;
}//Length

 //取栈顶元素的值。先决条件是栈不空。
template <class ElemType>
ElemType & SeqStack <ElemType>::GetTop() const
{
	if (m_top == -1) throw "下溢";
	return m_base[m_top];
}//Top

 //入栈，若栈满，则先扩展空间。插入e到栈顶。
template <class ElemType>
void SeqStack <ElemType>::Push(const ElemType &e)
{
	//if (m_top >= m_size) {	//若栈满，则扩展空间。 
	//	ElemType *newbase;
	//	newbase = new ElemType[m_size * 2];
	//	for (int j = 0; j < m_top; j++)
	//		newbase[j] = m_base[j];
	//	delete[] m_base;
	//	m_base = newbase;
	//	m_size *= 2;
	//}
	m_base[++m_top] = e;
}//Push

 //出栈，弹出栈顶元素。先决条件是栈非空。
template <class ElemType>
ElemType SeqStack <ElemType>::Pop()
{
	if (m_top == -1) throw "下溢";
	return m_base[m_top--];
}//Pop

template <class ElemType>
void SeqStack <ElemType>::PrintStack()
{
	for (int i = 0; i < Length(); i++)
	{
		cout << m_base[i] << " ";
	}
	cout << endl;
}
#endif

#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

//����˳��ջ��ģ��
template <typename ElemType>//����һ����ģ��
class SeqStack
{
public://˳��ջ��ĸ���Ա����
	SeqStack(int n = 100);
	~SeqStack();
	void Clear();
	bool Empty();
	int Length() const;
	ElemType & GetTop() const;
	void Push(const ElemType &e);
	ElemType Pop();
	void PrintStack();
private://˳��ջ������ݳ�Ա
	ElemType *m_base;			//����ַָ��
	int m_top;					//ջ��ָ��
	int m_size;					 //�����ռ��С
};

//���캯��������n������˳��ռ䣬����һ���յ�˳��ջ��
template <class ElemType>
SeqStack <ElemType>::SeqStack(int n)
{
	m_top = -1;
	m_base = new ElemType[n];
	m_size = n;
}//SqStack

 //������������ջ�ṹ���١�
template <class ElemType>
SeqStack <ElemType>::~SeqStack()
{
	if (m_base != nullptr) delete[] m_base;
}//~SqStack

 //��ջ�Ƿ�Ϊ�գ���Ϊ�գ��򷵻�true�����򷵻�false��
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

 //���ջ��
template <class ElemType>
void SeqStack <ElemType>::Clear() 
{
	 m_top = -1;
}//Clear

 //��ջ�ĳ��ȡ�
template <class ElemType>
int SeqStack <ElemType>::Length() const
{
	return m_top + 1;
}//Length

 //ȡջ��Ԫ�ص�ֵ���Ⱦ�������ջ���ա�
template <class ElemType>
ElemType & SeqStack <ElemType>::GetTop() const
{
	if (m_top == -1) throw "����";
	return m_base[m_top];
}//Top

 //��ջ����ջ����������չ�ռ䡣����e��ջ����
template <class ElemType>
void SeqStack <ElemType>::Push(const ElemType &e)
{
	//if (m_top >= m_size) {	//��ջ��������չ�ռ䡣 
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

 //��ջ������ջ��Ԫ�ء��Ⱦ�������ջ�ǿա�
template <class ElemType>
ElemType SeqStack <ElemType>::Pop()
{
	if (m_top == -1) throw "����";
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

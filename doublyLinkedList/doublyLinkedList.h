#ifndef LinkedList_H
#define LinkedList_H
#include<iostream>   //��������������⺯����ͷ�ļ�


// ����Ľ��ṹ
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
	LinkedList();					//�޲ι��캯��������ֻ��ͷ���Ŀ�����
	LinkedList(DataType a[], int n);	//�вι��캯����������n��Ԫ�صĵ�����
	~LinkedList();					//��������
	int Length();					//���Ա�ĳ���
	DataType Get(int i);			//��λ���ҡ�
	int Locate(DataType x);			//��ֵ���ҡ��ڵ������в���ֵΪx��Ԫ�����
	void Insert(int i, DataType x);	//�����������i��λ�ò���Ԫ��ֵΪx�Ľ��
	DataType Delete(int i);			//ɾ���������ڵ�������ɾ����i�����
	void PrintList();				//������������������������Ԫ��
private:
	Node<DataType> *first;             //�������ͷָ��
};

template <typename DataType>
LinkedList<DataType> ::LinkedList()
{
	first = new Node<DataType>;			//����ͷ���
														
	first->next = ptrptr; //ͷ��������Ϊ��
	first->prior = ptrptr;//ͷ���ǰ����Ϊ��
}

template <typename DataType>
LinkedList<DataType> ::LinkedList(DataType a[], int n)
{
	Node<DataType> *r, *s;
	first = new Node<DataType>;		//����ͷ���
	r = first;						//βָ���ʼ��
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>; 
		s->data = a[i];        //Ϊÿ������Ԫ�ؽ���һ�����
		s->prior = r;
		r->next = s;
		
		r = s;                 //�����s���뵽�ն˽��֮��
	}
	r->next = first;//��������ϣ����ն˽���ָ�����ÿ�
	first->prior = r;//ͷ���priorָ�����һ�����
	first->data = nullptr; //ͷ������������Ϊ��
}

template <typename DataType>
LinkedList<DataType> :: ~LinkedList()
{
	Node<DataType> *q = first->next ,*s ;
	while (q != first)	// �ͷŵ������ÿһ�����Ĵ洢�ռ�
	{
		s = q;		// �ݴ汻�ͷŽ��
		q = q->next;	// firstָ���ͷŽ�����һ�����
		delete s;
	}
	delete first;
}

template<typename DataType>
inline int LinkedList<DataType>::Length()
{
	int count = 0;	// �ۼ���count��ʼ��
	Node<DataType> *p = first->next;	// ����ָ�룬��ʼָ���һ��Ԫ��
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
	int count = 1;	// �ۼ���count��ʼ��
	Node<DataType> *p = first->next;	// ����ָ�룬��ʼָ���һ��Ԫ��
	while (p != first && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == first)
		throw "λ���쳣";
	else
		return p->data;
}

template <typename DataType>
int LinkedList<DataType> ::Locate(DataType x)
{
	Node<DataType> *p = first->next;
	int count = 1;         //����ָ��p���ۼ���count��ʼ��
	while (p != first)
	{
		if (p->data == x) return count;     //���ҳɹ��������������������
		p = p->next;
		count++;
	}
	return 0;                        //�˳�ѭ����������ʧ��
}

template <typename DataType>
void LinkedList<DataType> ::Insert(int i, DataType x)
{
	Node<DataType> *p = first, *s;
	int count = 0;               //����ָ��pӦָ��ͷ���
	while (count < i - 1)  //���ҵ�i - 1�����
	{
		p = p->next;                   //����ָ��p����
		count++;
	}
	if (p == first) throw "λ���쳣";      //û���ҵ���i - 1�����
	else {
		s = new Node<DataType>; 
		s->data = x;   //����һ�����s����������Ϊx
		s->next = p->next;
		s->prior = p;
		p->next->prior = s;
		p->next = s;   //�����s���뵽���p֮��
	}
}

template <typename DataType>
DataType LinkedList<DataType> ::Delete(int i)
{
	Node<DataType> *p, *q;
	DataType x;
	int count = 0;
	p = first;               // ע�⹤��ָ��pҪָ��ͷ���
	while (count < i - 1)  // ���ҵ�i-1�����
	{
		p = p->next;
		count++;
	}
	if (p == first)	// ���p������
	{
		throw "λ���쳣";
	}
	else
	{
		q = p->next; 
		x = q->data;			// �ݴ汻ɾ���
		p->next = q->next;
		q->next->prior = p; //ժ��
		delete q;
		return x;
	}
}

template <typename DataType>
void LinkedList<DataType> ::PrintList()
{
	using std::cout;
	using std::endl;
	Node<DataType> *p = first->next;	//����ָ��p��ʼ��
	while (p != first)
	{
		cout << p->data << "  ";
		p = p->next;	//����ָ��p���ƣ�ע�ⲻ��д��p++
	}
	cout << endl;
}

#endif


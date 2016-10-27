template<typename DataType>
struct Node
{
	DataType data;
	Node<DataType> * next;
};

template<typename DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();
	int Length();
	DataType Get(int i);//链表按位置查找
	int locate(DataType x);//按值查找
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();//遍历
	void PrintList(Node<DataType> *p);
	int count;
	int SearchRepeat();
	int SearchEven();
	//void judgeNum();
	void addListNode(int x);
	Node<DataType> *r;
private:
	Node<DataType> *first;
	
};

template<typename DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p;
	p = first->next;
	while (p != NULL)
	{

		cout << p->data << " ";
		p = p->next;
	}

}

template<typename DataType>
void LinkList<DataType>::PrintList(Node<DataType> *demo)
{
	Node<DataType> *p;
	p = demo->next;
	while (p != NULL)
	{

		cout << p->data << " ";
		p = p->next;
	}

}

template<typename DataType>
int LinkList<DataType>::Length()
{
	Node<DataType> *p;
	p = first->next;
	count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<typename DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType> *p;
	p = first->next; count = 1;
	while (p != NULL && count<i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)throw"找不到！！";
	else return p->data;
}

template<typename DataType>
int LinkList<DataType>::locate(DataType x)
{
	Node<DataType> *p = first->next;
	count = 1;
	while (p != NULL)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	return -1;
}

template<typename DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType> *p, *s;
	p = first;
	count = 0;
	while (p != first && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == first) throw "位置";
	else {
		s = new Node<DataType>; s->data = x;
		s->next = p->next; p->next = s;
	}
}

template <typename DataType>
LinkList<DataType>::LinkList()
{
	first = new Node<DataType>;
	first->next = NULL;
}

//头插法建立单链表
//template<typename DataType>
//LinkList<DataType>::LinkList(DataType a[] , int n)
//{
//	first = new Node;
//	first->next = s;
//
//	for(int i = 0; i < n; i++)
//	{   Node<DataType> *s;
//		s = new Node<DataType>;
//		s->data = a[i];
//		s->next = first->next; 
//		first->next = s ;
//	}
//}

template<typename DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	Node<DataType> *r, *s;
	first = new Node<DataType>;
	r = first;
	for (int i = 0; i < n; i++)
	{
		s = new Node<DataType>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template<typename DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType> *p, *q;
	p = first->next; count = 0;
	while (p != first && count<i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == first || p->next == first)
	{
		throw "位置错误";
	}
	else
	{
		q = p->next;
		DataType x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template<typename DataType>
LinkList<DataType>::~LinkList()
{
	Node<DataType> *q;
	while (first != NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

template<typename DataType>
int LinkList<DataType>::SearchRepeat()//查找有重复值的结点
{
	Node<DataType> *p = first->next;
	count = 0;
	while (p->next != NULL)
	{
		if (p->data == (p->next)->data)
		{
			return count;
		}
		count++;
		p = p->next;
	}
	return -1;

}

template<typename DataType>
int LinkList<DataType>::SearchEven()//查找值为偶数的结点
{
	Node<DataType> *p = first->next;
	count = 0;
	while (p->next != NULL)
	{
		if ((p->data) % 2 == 0) return count;
		count++;
		p = p->next;
	}
	return -1;
}


//template<typename DataType>
//void LinkList<DataType>::judgeNum()
//{
//	Node<DataType> *single = NULL;
//	 Node<DataType> *doub = NULL;
//	 single->data = NULL;
//	 doub->data = NULL;
//	Node<DataType>  *p , *s1,*d1,*s2,*d2;
//	p = first->next;
//	s1 = single;
//	d1 = doub;
//	int i = 0;
//	while (p->next != NULL)
//	{
//		
//		if (i % 2 == 0)
//		{
//			s2 = new Node<DataType>;
//			s2->data = p->data;
//			s1->next = s2;
//			s1 = s2;
//			
//		}
//		else
//		{
//			d2 = new Node<DataType>;
//			d2->data = p->data;
//			d1->next = d2;
//			d1 = d2;
//			
//		}
//		s1->next = NULL;
//		d1->next = NULL;
//		p = p->next;
//		i++;
//	}
//	PrintList(doub);
//	PrintList(single);
//}

template<typename datatype>
void LinkList<datatype>::addListNode(int x ) 
{
	Node<datatype> *s;
	
	if (first->next == NULL)
	{
		first = new Node<datatype>;
		r = first;
	}							//查找头结点是否有后续结点，无新建结点，链在表后
		s = new Node<datatype>;
		s->data = x;
		r->next = s;
		r = s;
	r->next = NULL;
}

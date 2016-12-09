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
	LinkList(DataType a[] , int n);
	~LinkList();
	int Length();
	DataType Get(int i);//链表按位置查找
	int locate(DataType x);//按值查找
	void Insert(int i , DataType x);
	DataType Delete(int i);
	void PrintList();//遍历	
	int SearchRepeat();//查找重复的数
	int SearchEven();//查找奇数
	void Reverse();//将带头结点的单链表逆置
	int count;
private:
	Node<DataType> *first;
};

template<typename DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p;
	p = first->next;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}

}

template<typename DataType>
int LinkList<DataType>::Length()
{
	Node<DataType> *p;
	p = first->next;
	count=0;
	while (p!=NULL)
	{
		p=p->next;
		count++;
	}
	return count;
}

template<typename DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType> *p;
	p=first->next;count = 1;
	while(p!=NULL && count<i)
	{
		p = p->next;
		count++;
	}
	if(p==NULL)throw"找不到！！";
	else return p->data;
}

template<typename DataType>
int LinkList<DataType>::locate(DataType x)
{
	Node<DataType> *p = first->next;
	count = 1;
	while (p!=NULL)
	{
		if(p->data == x) return count;
		p = p->next;
		count++;
	}
	return -1;
}

template<typename DataType>
void LinkList<DataType>::Insert(int i , DataType x)
{
	Node<DataType> *p , *s;
	p = first;
	count = 0;
	while (p!=NULL && count < i-1)
	{
		p = p->next;
		count++;
	}
	if(p == NULL) throw "位置";
	else{
		s= new Node<DataType>; s->data = x;
	s->next = p->next; p->next = s; }
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
LinkList<DataType>::LinkList(DataType a[],int n)
{
	Node<DataType> *r,*s;
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
	Node<DataType> *p,*q;
	p = first->next; count = 0;
	while (p!=NULL && count<i-1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p -> next == NULL)
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
	while (first!=NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

template<typename DataType>
int LinkList<DataType>::SearchRepeat()
{
	Node<DataType> *p = first->next;
		 count = 0;
		 while (p->next!=NULL)
	{
		if(p->data == (p->next)->data) 
			{	
				return count;
			}
		count++;
		p = p->next;
	}
	return -1;
}

template<typename DataType>
int LinkList<DataType>::SearchEven()
{
	Node<DataType> *p = first->next;
	count = 0;
	while(p->next != NULL)
	{
		if((p->data)%2 == 0) return count;
		count++;
		p = p->next;
	} 
	return -1;
}

template<typename DataType>
void LinkList<DataType>::Reverse()
{
	Node<DataType> *p = first->next;
	Node<DataType> *pre = NULL;
	while (p != NULL)
	{
		Node<DataType> *r = p->next;
		p->next = pre;
		pre = p;
		p = r;
	}
	first->next = pre;
}
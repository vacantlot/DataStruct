const int MaxSize = 100;
#include<math.h>
template<class DataType>
class SeqList
{
public:
	SeqList(){length = 0;}
	SeqList(DataType a[] , int n);
	~SeqList(){}
	int Length(){ return length;}
	DataType Get(int);
	int Locate(DataType x);
	void Insert(int i ,DataType x);
	DataType Delete(int i);
	void PrintList();
	int x;
	void Add(int x);
private:
	DataType data[MaxSize];
	int length;
};


template<class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
	if(n>MaxSize)throw"�����Ƿ�";
	for(int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

template<class DataType>
void SeqList<DataType>::Insert(int i ,DataType x)
{
	if(length >= MaxSize) throw "����";
	if(i<1||i>length+1)throw"λ��";
	for(int j=length;j>=i;j--)
		data[j] = data[j-1];
		data[i-1] = x;
		length++;
}


template<class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if(i<1&&i>length)throw"����λ�÷Ƿ�";
	else return data[i-1];
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for(int i = 1; i < length ; i++)
		if(data[i] == x)return i+1;
	return 0;
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if(length == 0)throw"����";
	if(i<1||i>length)throw"λ��";
 	x = data[i-1];
	for (int j = i; j < length; j++)
	{
		data[j-1] = data[j];
	}
	length--;
	return x;
}

template<class DataType>
void SeqList<DataType>::PrintList()
{
	int n = 1;
	for (int i = 0; i < length; i++)
	{
		cout<<data[i]<<" ";
		if (i+1 == (pow(2,n) - 1)) 
		{
			cout << endl;
			n++;
		}
	}
}

template<class DataType>
inline void SeqList<DataType>::Add(int x)
{
	if (length >= MaxSize) throw "����";
	data[length++] = x;
}


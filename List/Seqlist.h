const int MaxSize = 100;
#include<math.h>
template<class DataType>
class SeqList
{
public:
	int x;
	void PrintListYH();	
	void Add(int x);  //在表尾加一个值
	inline SeqList() { length = 0; }            //无参构造函数，建立一个空的顺序表
	SeqList(DataType a[], int n);       //有参构造函数，建立一个长度为n的顺序表
	~SeqList() { }                   //析构函数为空
	inline int Length() { return length; }        //求线性表的长度
	DataType Get(int i);               //按位查找，在线性表中查找第i个元素
	int Locate(DataType x);           //按值查找，在线性表中查找值为x的元素序号
	void Insert(int i, DataType x);       //插入操作，在线性表中第i个位置插入值为x的元素
	DataType Delete(int i);              //删除操作，删除线性表的第i个元素
	void PrintList();                     //遍历操作，按序号依次输出各元素
private:
	DataType data[MaxSize];           //存放数据元素的数组
	int length;                        //线性表的长度
};


template<class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
	if(n>MaxSize)throw"参数非法";
	for(int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

template<class DataType>
void SeqList<DataType>::Insert(int i ,DataType x)
{
	if(length >= MaxSize) throw "上溢";
	if(i<1||i>length+1)throw"位置";
	for(int j=length;j>=i;j--)
		data[j] = data[j-1];
		data[i-1] = x;
		length++;
}


template<class DataType>
DataType SeqList<DataType>::Get(int i)
{
	if(i<1&&i>length)throw"查找位置非法";
	else return data[i-1];
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for (int i = 1; i < length; i++)
		if (data[i] == x)
		{
			cout << "找到了";
			return i + 1;
		}
	cout << "没找到";
	return 0;
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if(length == 0)throw"下溢";
	if(i<1||i>length)throw"位置";
 	x = data[i-1];
	for (int j = i; j < length; j++)
	{
		data[j-1] = data[j];
	}
	length--;
	return x;
}

template<class DataType>
void SeqList<DataType>::PrintListYH()
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
inline void SeqList<DataType>::PrintList()
{
	int n = 1;
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";		
	}
}

template<class DataType>
inline void SeqList<DataType>::Add(int x)
{
	if (length >= MaxSize) throw "上溢";
	data[length++] = x;
}


const int MaxSize = 100;
#include<math.h>
template<class DataType>
class SeqList
{
public:
	int x;
	void PrintListYH();	
	void Add(int x);  //�ڱ�β��һ��ֵ
	inline SeqList() { length = 0; }            //�޲ι��캯��������һ���յ�˳���
	SeqList(DataType a[], int n);       //�вι��캯��������һ������Ϊn��˳���
	~SeqList() { }                   //��������Ϊ��
	inline int Length() { return length; }        //�����Ա�ĳ���
	DataType Get(int i);               //��λ���ң������Ա��в��ҵ�i��Ԫ��
	int Locate(DataType x);           //��ֵ���ң������Ա��в���ֵΪx��Ԫ�����
	void Insert(int i, DataType x);       //��������������Ա��е�i��λ�ò���ֵΪx��Ԫ��
	DataType Delete(int i);              //ɾ��������ɾ�����Ա�ĵ�i��Ԫ��
	void PrintList();                     //������������������������Ԫ��
private:
	DataType data[MaxSize];           //�������Ԫ�ص�����
	int length;                        //���Ա�ĳ���
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
	for (int i = 1; i < length; i++)
		if (data[i] == x)
		{
			cout << "�ҵ���";
			return i + 1;
		}
	cout << "û�ҵ�";
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
	if (length >= MaxSize) throw "����";
	data[length++] = x;
}


#pragma once
const int QueueSize = 100;
template<typename DataType>
class CirQueue
{
public:
	CirQueue() { front = rear = QueueSize - 1; }
	~CirQueue();
	void EnQueue(DataType x);  //x���
	DataType DeQueue();        //���ж�Ԫ�ص�����ɾ����
	DataType GetQueue();       //ȡ�����ж�Ԫ�أ���ɾ����
	bool IsEmpty() { return front == rear ? 1 : 0; } // �п�

private:
	DataType data[QueueSize];
	int front, rear;
};

template<typename DataType>
CirQueue<DataType>::~CirQueue()
{
	delete[] data;
}

template<typename DataType>
inline void CirQueue<DataType>::EnQueue(DataType x)
{
	if ((rear + 1) % QueueSize == front)
	{
		throw "����";
	}
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<typename DataType>
inline DataType CirQueue<DataType>::DeQueue()
{
	if (rear == front)
	{
		throw "����";
	}
	front = (front + 1) % QueueSize;

	return data[front];
}

template<typename DataType>
inline DataType CirQueue<DataType>::GetQueue()
{
	if (rear == front)
	{
		throw "����";
	}
	DataType i = (front + 1) % QueueSize;

	return data[i];
}


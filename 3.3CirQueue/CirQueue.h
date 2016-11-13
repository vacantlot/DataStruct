#pragma once
const int QueueSize = 100;
template<typename DataType>
class CirQueue
{
public:
	CirQueue() { front = rear = QueueSize - 1; }
	
	void EnQueue(DataType x);
	DataType DeQueue();
	DataType GetQueue();
	bool IsEmpty() { return front == rear ? 1 : 0; }

private:
	DataType data[QueueSize];
	int front, rear;
};



template<typename DataType>
inline void CirQueue<DataType>::EnQueue(DataType x)
{
	if ((rear+1)%QueueSize == front)
	{
		throw "иорГ";
	}
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<typename DataType>
inline DataType CirQueue<DataType>::DeQueue()
{
	if (rear == front)
	{
		throw "обрГ";
	}
	front = (front + 1) % QueueSize;

	return data[front];
}

template<typename DataType>
inline DataType CirQueue<DataType>::GetQueue()
{
	if (rear == front)
	{
		throw "обрГ";
	}
	DataType i = (front + 1) % QueueSize;

	return data[i];
}



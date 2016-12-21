#pragma once
const int QueueSize = 100;
template<typename DataType>
class CirQueue
{
public:
	CirQueue() { front = rear = QueueSize - 1; }
	
	void EnQueue(DataType x); //入队
	DataType DeQueue();   //出队
	DataType GetQueue();  //获取队首
	bool IsEmpty() { return front == rear ? 0 : 1; }
private:
	DataType data[QueueSize];
	int front, rear;
};



template<typename DataType>
inline void CirQueue<DataType>::EnQueue(DataType x)
{
	if ((rear+1)%QueueSize == front)
	{
		throw "上溢";
	}
	rear = (rear + 1) % QueueSize;
	data[rear] = x;
}

template<typename DataType>
inline DataType CirQueue<DataType>::DeQueue()
{
	if (rear == front)
	{
		throw "下溢";
	}
	front = (front + 1) % QueueSize;
	return data[front];
}

template<typename DataType>
inline DataType CirQueue<DataType>::GetQueue()
{
	if (rear == front)
	{
		throw "下溢";
	}
	DataType i = (front + 1) % QueueSize;

	return data[i];
}




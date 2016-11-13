#pragma once
const int QueueSize = 100;
template<typename DataType>
class CirQueue
{
public:
	CirQueue() { front = rear = QueueSize - 1; }
	~CirQueue();
	void EnQueue(DataType x);
	DataType DeQueue();
	DataType GetQueue();
	bool Empty() { return front == rear ? 1 : 0; }
	
private:
	DataType data[QueueSize];
	int front, rear;
};

template<typename DataType>
CirQueue<DataType>::~CirQueue()
{

}



enum ErrorCode

{

         success,

         underflow,

         overflow

};

 

const int maxQueue = 100;

 

template <class QueueEntry>

class MyQueue

{

public:

         MyQueue();

 

         // �ж϶����Ƿ�Ϊ��

         bool empty() const;

         // ��Ӳ���

         ErrorCode append(const QueueEntry &item);

         // ���Ӳ���

         ErrorCode serve();

         // ��ȡ��ͷԪ��

         ErrorCode retrieve(QueueEntry &item) const;

         // �ж϶����Ƿ�����

         bool full() const;

         // ��ȡ��������Ԫ�ظ���

         int size() const;

         // �����������Ԫ��

         void clear();

         // ��ȡ��ͷԪ�ز�����

         ErrorCode retrieve_and_serve(QueueEntry &item);

 

private:

         int front;                             // ��ͷ�±�

         int rear;                              // ��β�±�

         QueueEntry entry[100];       // ��������

};

template <class QueueEntry>

MyQueue<QueueEntry>::MyQueue()
{
	rear = -1;
	front = 0;
}

 

         // �ж϶����Ƿ�Ϊ��

template <class QueueEntry>

bool MyQueue<QueueEntry>::empty() const
{
return (maxQueue + rear - front + 1) % maxQueue == 0;
}

         // ��Ӳ���

template <class QueueEntry>

ErrorCode MyQueue<QueueEntry>::append(const QueueEntry &item)
{
	if (full()) return overflow;
	rear = (rear + 1 == maxQueue)?0:(rear+1);
	entry[rear] = item;
	return success;
}

template <class QueueEntry>

ErrorCode MyQueue<QueueEntry>::serve()
{
	if (empty()) return underflow;
	front = ((front + 1) == maxQueue)?0:(front+1);
	return success;
}


template <class QueueEntry>

ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry &item) const
{
	if (empty()) return underflow;
	item = entry[front];
	return success;
}

template <class QueueEntry>

bool MyQueue<QueueEntry>::full() const
{
	return (maxQueue + rear - front + 1) % maxQueue == maxQueue - 1;
}

         // ��ȡ��������Ԫ�ظ���

template <class QueueEntry>

int MyQueue<QueueEntry>::size() const
{
	return (maxQueue + rear - front + 1) % maxQueue;
}


template <class QueueEntry>
void MyQueue<QueueEntry>::clear()
{
	rear = -1;
	front = 0;
}

template <class QueueEntry>

ErrorCode MyQueue<QueueEntry>::retrieve_and_serve(QueueEntry &item)
{
	if (empty()) return underflow;
	item = entry[front];
	front = ((front + 1) == maxQueue)?0:(front+1);
	return success;
}



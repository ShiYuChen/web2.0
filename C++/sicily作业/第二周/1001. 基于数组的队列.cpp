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

 

         // 判断队列是否为空

         bool empty() const;

         // 入队操作

         ErrorCode append(const QueueEntry &item);

         // 出队操作

         ErrorCode serve();

         // 获取队头元素

         ErrorCode retrieve(QueueEntry &item) const;

         // 判断队列是否已满

         bool full() const;

         // 获取队列已有元素个数

         int size() const;

         // 清除队列所有元素

         void clear();

         // 获取队头元素并出队

         ErrorCode retrieve_and_serve(QueueEntry &item);

 

private:

         int front;                             // 队头下标

         int rear;                              // 队尾下标

         QueueEntry entry[100];       // 队列容器

};

template <class QueueEntry>

MyQueue<QueueEntry>::MyQueue()
{
	rear = -1;
	front = 0;
}

 

         // 判断队列是否为空

template <class QueueEntry>

bool MyQueue<QueueEntry>::empty() const
{
return (maxQueue + rear - front + 1) % maxQueue == 0;
}

         // 入队操作

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

         // 获取队列已有元素个数

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



#include <cstdlib>
enum ErrorCode
{
         success,
         underflow,
         overflow
};


template <class QueueEntry>
struct Node
{
         QueueEntry data;
         Node<QueueEntry> *next;
};

 

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

         // 获取队列已有元素个数

         int size() const;

         // 清除队列所有元素

         void clear();

         // 获取队头元素并出队

         ErrorCode retrieve_and_serve(QueueEntry &item);

 

private:

         Node<QueueEntry> *front;                           // 队头指针

         Node<QueueEntry> *rear;                             // 队尾指针

};

template <class QueueEntry>
MyQueue<QueueEntry>::MyQueue() {front = rear = NULL;}

 

         // 判断队列是否为空

template <class QueueEntry>
bool MyQueue<QueueEntry>::empty() const
{
	return front == NULL;
}

         // 入队操作

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::append(const QueueEntry &item)
{
	Node<QueueEntry> *new_node = new Node<QueueEntry>();
	new_node->next = NULL;
	new_node->data = item; 
	if (empty())
	{
		front = rear = new_node;
	}
	else
	{
		rear->next = new_node;
		rear = new_node;
	}
	return success;
}

         // 出队操作

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::serve()
{
	if (empty()) return underflow;
	Node<QueueEntry> *old = front;
	front = front->next;
	if (front == NULL) rear = NULL;
	delete old;
	return success;
}

         // 获取队头元素

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry &item) const
{
	if (empty()) return underflow;
	item = front->data;
	return success;
}

         // 获取队列已有元素个数

template <class QueueEntry>
int MyQueue<QueueEntry>::size() const
{
	Node<QueueEntry> *temp = front;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;	
	}
	return count;
}

         // 清除队列所有元素

template <class QueueEntry>
void MyQueue<QueueEntry>::clear()
{
	while (front != NULL)
	{
		serve();	
	}
	front = rear = NULL;
}

         // 获取队头元素并出队

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve_and_serve(QueueEntry &item)
{
	if (empty()) return underflow;
	item = front->data;
	Node<QueueEntry> *old = front;
	front = front->next;
	if (front == NULL) rear = NULL;
	delete old;
	return success;
}



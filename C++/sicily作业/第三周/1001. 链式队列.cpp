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

 

         // �ж϶����Ƿ�Ϊ��

         bool empty() const;

         // ��Ӳ���

         ErrorCode append(const QueueEntry &item);

         // ���Ӳ���

         ErrorCode serve();

         // ��ȡ��ͷԪ��

         ErrorCode retrieve(QueueEntry &item) const;

         // ��ȡ��������Ԫ�ظ���

         int size() const;

         // �����������Ԫ��

         void clear();

         // ��ȡ��ͷԪ�ز�����

         ErrorCode retrieve_and_serve(QueueEntry &item);

 

private:

         Node<QueueEntry> *front;                           // ��ͷָ��

         Node<QueueEntry> *rear;                             // ��βָ��

};

template <class QueueEntry>
MyQueue<QueueEntry>::MyQueue() {front = rear = NULL;}

 

         // �ж϶����Ƿ�Ϊ��

template <class QueueEntry>
bool MyQueue<QueueEntry>::empty() const
{
	return front == NULL;
}

         // ��Ӳ���

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

         // ���Ӳ���

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

         // ��ȡ��ͷԪ��

template <class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry &item) const
{
	if (empty()) return underflow;
	item = front->data;
	return success;
}

         // ��ȡ��������Ԫ�ظ���

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

         // �����������Ԫ��

template <class QueueEntry>
void MyQueue<QueueEntry>::clear()
{
	while (front != NULL)
	{
		serve();	
	}
	front = rear = NULL;
}

         // ��ȡ��ͷԪ�ز�����

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



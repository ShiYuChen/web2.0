enum ErrorCode{success,underflow,overflow};

const int maxqueue = 100;

typedef int queue_entry;

class queue
{
	public:
         queue();
         bool empty() const;
         ErrorCode append(const queue_entry &item);
         ErrorCode serve();
         ErrorCode retrieve(queue_entry &item) const;
         bool full() const;
         int size() const;
         void clear();
         ErrorCode retrieve_and_serve(queue_entry &item);
	private:
         int front;                             // 队头下标
         int rear;                              // 队尾下标
         queue_entry entry[maxqueue];       // 队列容器

};

queue::queue()
{
	rear = -1;
	front = 0;
}


bool queue::empty() const
{
	return (maxqueue + rear - front + 1) % maxqueue == 0;
}


ErrorCode queue::append(const queue_entry &item)
{
	if (full()) return overflow;
	rear = (rear + 1 == maxqueue)?0:(rear+1);
	entry[rear] = item;
	return success;
}

ErrorCode queue::serve()
{
	if (empty()) return underflow;
	front = ((front + 1) == maxqueue)?0:(front+1);
	return success;
}


ErrorCode queue::retrieve(queue_entry &item) const
{
	if (empty()) return underflow;
	item = entry[front];
	return success;
}

bool queue::full() const
{
	return (maxqueue + rear - front + 1) % maxqueue == maxqueue - 1;
}


int queue::size() const
{
	return (maxqueue + rear - front + 1) % maxqueue;
}


void queue::clear()
{
	rear = -1;
	front = 0;
}

ErrorCode queue::retrieve_and_serve(queue_entry &item)
{
	if (empty()) return underflow;
	item = entry[front];
	front = ((front + 1) == maxqueue)?0:(front+1);
	return success;
}

#include <iostream>
using namespace std;
int main()
{
	queue q;
	int i;
	q.append(12);
	q.append(1111);
	cout << q.size() << endl;
	cout << q.empty() << endl;
	cout << q.full() << endl;
	q.retrieve_and_serve(i);
	cout << i << endl;
	q.retrieve(i);
	cout << i << endl;
	return 0;
} 

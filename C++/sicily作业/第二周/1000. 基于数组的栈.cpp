#include <iostream>
using namespace std;

enum ErrorCode

{

         success,

         underflow,

         overflow

};

 

const int maxStack = 100;             // 栈的最大容量

 

template <class StackEntry>

class MyStack

{

public:

         MyStack();

         /*

                   判断栈是否为空，若为空则返回true，非空则返回false

          */

         bool empty() const;

         /*

                   出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow

          */

         ErrorCode pop();

         /*

                   获取栈顶元素，若正常出栈则返回success，若栈内无元素则返回underflow

                   元素内容保存在引用参数item中

          */

         ErrorCode top(StackEntry &item) const;

         /*

                   入栈操作，若正常入栈则返回success，若栈满则返回overflow

          */

         ErrorCode push(const StackEntry &item);

 

private:

         int size;

         StackEntry entry[maxStack];

};


template <class StackEntry>
MyStack<StackEntry>::MyStack()
         {
         	size = -1;
         }

template <class StackEntry>
bool MyStack<StackEntry>::empty() const
         {
         	return size == -1;
         }


template <class StackEntry>
ErrorCode MyStack<StackEntry>::pop()
         {
         	if (size == -1) return underflow;
         	size--;
         	return success;
         }



template <class StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry &item) const
         {
         	if (empty()) return underflow;
         	item = entry[size];
         	return success;
         }


template <class StackEntry>
ErrorCode MyStack<StackEntry>::push(const StackEntry &item)
         {
         	if (size == maxStack - 1) return overflow;
         	entry[++size] = item;
         	return success;
         }

int main()
{
	int i;
	MyStack<int> s;
	s.push(12);
	s.top(i);
	cout << i << endl;
	return 0;
}

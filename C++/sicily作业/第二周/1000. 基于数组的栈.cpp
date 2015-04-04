#include <iostream>
using namespace std;

enum ErrorCode

{

         success,

         underflow,

         overflow

};

 

const int maxStack = 100;             // ջ���������

 

template <class StackEntry>

class MyStack

{

public:

         MyStack();

         /*

                   �ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�true���ǿ��򷵻�false

          */

         bool empty() const;

         /*

                   ��ջ��������������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow

          */

         ErrorCode pop();

         /*

                   ��ȡջ��Ԫ�أ���������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow

                   Ԫ�����ݱ��������ò���item��

          */

         ErrorCode top(StackEntry &item) const;

         /*

                   ��ջ��������������ջ�򷵻�success����ջ���򷵻�overflow

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

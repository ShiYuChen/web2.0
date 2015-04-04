#include <cstdlib> 
#include <iostream>
using namespace std;

enum ErrorCode{
         success,
         underflow,
         overflow
};

template <class StackEntry>
struct Node
{
         StackEntry data;
         Node *next;
};


template <class StackEntry>
class MyStack
{

public:

         MyStack();

         /*

                   �ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�true���ǿ��򷵻�false

          */

         bool empty() const;

         int size() const;

         /*

                   ��ջ��������������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow

          */

         ErrorCode pop();

         /*

                   ��ȡջ��Ԫ�أ���������ȡ��ջ��Ԫ���򷵻�success����ջ����Ԫ���򷵻�underflow

                   Ԫ�����ݱ��������ò���item��

          */

         ErrorCode top(StackEntry &item) const;

         /*

                   ��ջ��������������ջ�򷵻�success������ջʧ���򷵻�overflow

          */

         ErrorCode push(const StackEntry &item);

         /*

                   ���ջ

          */

         void clear();

private:

         Node<StackEntry> *Top;

};

 


template <class StackEntry>
MyStack<StackEntry>::MyStack(){Top = NULL;} 

         /*

                   �ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�true���ǿ��򷵻�false

          */
template <class StackEntry>
bool MyStack<StackEntry>::empty() const {return Top == NULL;} 

template <class StackEntry>
int MyStack<StackEntry>::size() const
{
	Node<StackEntry> *temp = Top;
	int count = 0;
	while (temp)
	{
		count += 1;
		temp = temp->next;
	}
	return count;
}

         /*

                   ��ջ��������������ջ�򷵻�success����ջ����Ԫ���򷵻�underflow

          */

template <class StackEntry>
ErrorCode MyStack<StackEntry>::pop()
{
	if (empty()) return underflow;
	Node<StackEntry> *temp = Top;
  Top = Top->next;
	delete temp;
	return success;
}

         /*

                   ��ȡջ��Ԫ�أ���������ȡ��ջ��Ԫ���򷵻�success����ջ����Ԫ���򷵻�underflow

                   Ԫ�����ݱ��������ò���item��

          */
template <class StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry &item) const
{
	if (empty()) return underflow;
	item = Top->data;
	return success;
}

         /*

                   ��ջ��������������ջ�򷵻�success������ջʧ���򷵻�overflow

          */
template <class StackEntry>
ErrorCode MyStack<StackEntry>::push(const StackEntry &item)
{
	Node<StackEntry> *new_node = new Node<StackEntry>();
	new_node->data = item;
	new_node->next = NULL;
	if (Top == NULL)
	{
		Top = new_node;
	}
	else
	{
		new_node->next = Top;
		Top = new_node;
	}

	return success; 
}

         /*

                   ���ջ

          */
template <class StackEntry>
void MyStack<StackEntry>::clear()
{
	while (Top!=NULL)
	{
		pop();
	}
}


int main()
{
 MyStack<int> s;
 int item;
 s.push(12);
 s.push(111);
 s.push(222);
 cout << s.size() << endl;



 return 0;
}


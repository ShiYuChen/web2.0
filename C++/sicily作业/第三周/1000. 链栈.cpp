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

                   判断栈是否为空，若为空则返回true，非空则返回false

          */

         bool empty() const;

         int size() const;

         /*

                   出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow

          */

         ErrorCode pop();

         /*

                   获取栈顶元素，若正常获取到栈顶元素则返回success，若栈内无元素则返回underflow

                   元素内容保存在引用参数item中

          */

         ErrorCode top(StackEntry &item) const;

         /*

                   入栈操作，若正常入栈则返回success，若入栈失败则返回overflow

          */

         ErrorCode push(const StackEntry &item);

         /*

                   清空栈

          */

         void clear();

private:

         Node<StackEntry> *Top;

};

 


template <class StackEntry>
MyStack<StackEntry>::MyStack(){Top = NULL;} 

         /*

                   判断栈是否为空，若为空则返回true，非空则返回false

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

                   出栈操作，若正常出栈则返回success，若栈内无元素则返回underflow

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

                   获取栈顶元素，若正常获取到栈顶元素则返回success，若栈内无元素则返回underflow

                   元素内容保存在引用参数item中

          */
template <class StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry &item) const
{
	if (empty()) return underflow;
	item = Top->data;
	return success;
}

         /*

                   入栈操作，若正常入栈则返回success，若入栈失败则返回overflow

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

                   清空栈

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


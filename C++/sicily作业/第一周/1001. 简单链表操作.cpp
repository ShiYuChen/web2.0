#include <iostream>
using namespace std;

struct Node

{
         int data;

         Node *next;
};

 

class LinkedList

{

public:

         LinkedList();

         void insert(int position, int content);

         void deleteByPosition(int position);

         void print();

private:

         Node *head;                               // 链表头指针

         int size;                                        // 链表内元素个数

};


         LinkedList::LinkedList()
				 {
				 	head = NULL;
				 	size = 0;
         } 


         void LinkedList::insert(int position, int content)
         {
         	if (position >= 0)
         	{
         	  Node *temp = head,*new_node = new Node();
         	  new_node->data = content;
         	  new_node->next = NULL;

         	  if (position == 0 || (position >= 0 && size == 0))
         	  {
         	  	if (size != 0)
         	  	{
         	  	head = new_node;
         	  	new_node->next = temp;         	  		
         	  	}
         	  	else
         	  	{
         	  		head = new_node; 
         	  	}

         	  }
         		else if (position >= size)
						 {
						 	while (temp->next != NULL)
						 		temp = temp->next;
						 	temp->next = new_node;
						 }
						 else
						 {
						 	while (--position)
						 		temp = temp->next;
						 	new_node->next = temp->next;
						 	temp->next = new_node;
						 }
						 size++;
         	}
         }


         void LinkedList::deleteByPosition(int position)
         {
         	Node *temp = head, *old;
         	if (position < size)
         	{
         		if (position == 0)
         		{
         			old = head;
         			if (size == 1) head = NULL;
         			else head = head->next;
         		}
         		else
         		{
						while (--position)
						 	temp = temp->next;
						old = temp->next;
						temp->next = old->next;         			
         		}
         		delete old;
         		size--;
         	}
         }


         void LinkedList::print()
         {
         	Node *temp = head;
         	while (temp != 0)
         	{
					 cout << temp->data << '\t';
					 temp = temp->next;
         	}
        		cout << endl;
         }

int main()
{
	LinkedList a;
	a.insert(1,12);
	a.insert(2,34);
	a.deleteByPosition(0);
	a.insert(0,111);
	a.insert(1,222);
	a.deleteByPosition(1);
	a.print();
	return 0;
}


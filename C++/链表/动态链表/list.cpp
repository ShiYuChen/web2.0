#include "list.h"
#include <cstdlib>
#include <iostream>
using namespace std;

		list::list()
		{
			count = 0;
			current_position = -1;
			current = NULL;
		}

		void list::clear()
		{
			List_entry temp;
			while (!empty())
			remove(0, temp);
		}

		bool list::empty(){return count == 0;}

		int list::size(){return count;}

		void list::set_position(int position)
		{
			if (position <= current_position)
			{
				for (;current_position != position; current_position--)
					current = current->back;
			}
			else
			{
				for (;current_position != position; current_position++)
					current = current->next;
			}
		}

		Error_code list::insert(int position, const List_entry&x)
		{
			if (position < 0 || position > count) return range_error;
			Node *new_node = new Node(x), *pre, *post;
			if (position == 0)                                           //把位置0单独拿出来考虑 
			{
				if (count == 0) post = NULL;
				else
				{
					set_position(0);
					post = current;
				}
				pre = NULL;
			}
			else
			{
				set_position(position - 1);
				pre = current;
				post = pre->next;
			}
			if (pre != NULL) pre->next = new_node;
			if (post != NULL) post->back = new_node;
			new_node->back = pre;
			new_node->next = post;
			current = new_node;
			current_position = position;
			count++;
			return success;
		}

    //分3种情况，头删除，尾删除，中间删除 
		Error_code list::remove(int position, List_entry&x)
		{
			if (position < 0 || position >= count) return range_error;
			if (count == 0) return underflow;
			Node *temp = current, *pre, *post;
			if (position == 0)
			{
				if (count == 1)
				{
					set_position(0);
					temp = current;
					current = NULL;
					current_position = -1;
				}
				else
				{
					set_position(position + 1);
					temp = current->back;
					current->back = NULL;
					current_position -= 1;
				}
			}
			else if (position == count - 1)
			{
				set_position(position - 1);
				temp = current->next;
				current->next = NULL;
			}
			else
			{
				set_position(position);
				temp = current;
				pre = current->back;
				post = current->next;
				pre->next = post;
				post->back = pre;
				current = pre;
				current_position -= 1;
			}
			x = temp->entry;
			delete temp;
			count--;
			return success;
		}
		
		Error_code list::retrieve(int position, List_entry&x)
		{
			if (position < 0 || position >= count) return range_error;
			if (count == 0) return underflow;
			set_position(position);
			x = current->entry;
			return success;
		}
		
		Error_code list::replace(int position, const List_entry&x)
		{
			if (position < 0 || position >= count) return range_error;
			if (count == 0) return underflow;
			set_position(position);
			current->entry = x;
			return success;
		}
		
		void list::display()
		{
			if (count != 0)
			{
				Node *head;
				set_position(0);
				head = current;
				while (head != NULL)
				{
					cout << head->entry << "  " << endl;
					head = head->next;
				}
			} 
		}

#include "stack.h"

		stack::stack(){Top = NULL;}

		stack::~stack(){while (!empty()) pop();}

		bool stack::empty()const{return Top == NULL;}

		Error_code stack::push(const stack_entry&item)
		{
			Node *new_top = new Node(item, Top);
			Top = new_top;
			return success;
		}

		Error_code stack::pop()
		{
			if (empty()) return underflow;
			Node *old_top = Top;
			Top = Top->next;
			delete old_top;
			return success;
		}

		Error_code stack::pop(stack_entry&item)
		{
			if (empty()) return underflow;
			Node *old_top = Top;
			item = Top->entry;
			Top = Top->next;
			delete old_top;
			return success;
		}

		Error_code stack::top(stack_entry&item)
		{
			if (empty()) return underflow;
			item = Top->entry;
			return success;
		}

		stack::stack(const stack&origin)
		{
			Node *copy, *onode = origin.Top;
			if (onode == NULL) Top = NULL;
			else
			{
				copy = Top = new Node(onode->entry);
				while (onode->next != NULL)
				{
					onode = onode->next;
					copy->next = new Node(onode->entry);
					copy = copy->next;
				}
			}
		}

		void stack::operator=(const stack&origin)
		{
			Node *new_top, *copy, *onode = origin.Top;
			if (onode == NULL) new_top = NULL;
			else
			{
				copy = new_top = new Node(onode->entry);
				while (onode->next != NULL)
				{
					onode = onode->next;
					copy->next = new Node(onode->entry);
					copy = copy->next;
				}
			}
			while (!empty()) pop();
			Top = new_top;
		}

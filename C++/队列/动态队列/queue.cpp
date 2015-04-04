#include "queue.h"

		queue::queue() {front = rear = NULL;}

		queue::~queue() {while(!empty()) serve();}

		bool queue::empty()const {return front == NULL;}

		Error_code queue::append(const queue_entry&item)
		{
			Node *new_rear = new Node(item);
			if (front == NULL) front = rear = new_rear;
			else
			{
				rear->next = new_rear;
				rear = new_rear; 
			}
			return success;
		}

		Error_code queue::serve()
		{
			if (front == NULL) return underflow;
			Node *old = front;
			front = front->next;
			if (front == NULL) rear = NULL;
			delete old;
			return success;
		}

		Error_code queue::retrieve(queue_entry&item)
		{
			if (front == NULL) return underflow;
			item = front->entry;
			return success;
		}

		Error_code queue::retrieve_and_serve(queue_entry&item)
		{
			if (front == NULL) return underflow;
			item = front->entry;
			Node *old = front;
			front = front->next;
			if (front == NULL) rear = NULL;
			delete old;
			return success;
		}

		queue::queue(const queue&origin)
		{
			Node *onode = origin.front;
			if (onode == NULL) front = rear = NULL;
			else
			{
				front = rear = new Node(onode->entry);
				while (onode->next != NULL)
				{
					onode = onode->next;
					rear->next = new Node(onode->entry);
					rear = rear->next; 
				}
			}
		}

		void queue::operator=(const queue&origin)
		{
			Node *new_top, *copy/*³äµ±rear*/, *onode = origin.front;
			if (onode == NULL) new_top = copy = NULL;
			else
			{
				 new_top = copy = new Node(onode->entry);
				 while (onode->next != NULL)
				 {
				 	onode = onode->next;
				 	copy->next = new Node(onode->entry);
				 	copy = copy->next;
				 }
			}
			while (!empty())
			{
				serve();
			}
			front = new_top;
			rear = copy;
		}

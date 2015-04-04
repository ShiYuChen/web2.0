#include "queue.h"

		queue::queue() {rear = -1;}

		bool queue::empty()const {return rear == -1;}

		Error_code queue::append(const queue_entry&item)
		{
			if (rear == maxsize - 1) return overflow;
			entry[++rear] = item;
			return success;
		}

		Error_code queue::serve()
		{
			if (empty()) return underflow;
			rear--;
			for (int i = 0; i <= rear; i++) entry[i] = entry[i+1];
			return success;
		}

		Error_code queue::retrieve(queue_entry&item)
		{
			if (empty()) return underflow;
			item = entry[0];
			return success;
		}

		Error_code queue::retrieve_and_serve(queue_entry&item)
		{
			if (empty()) return underflow;
			item = entry[0];
			rear--;
			for (int i = 0; i <= rear; i++) entry[i] = entry[i+1];
			return success;
		}

#include "stack.h"

	stack::stack() {Top = -1;}

	Error_code stack::push(const stack_entry&item)
	{
		if (Top == maxsize - 1) return overflow;
		entry[++Top] = item;
		return success;
	}

	Error_code stack::pop()
	{
		if (empty()) return underflow;
		Top--;
		return success;
	}

	Error_code stack::pop(stack_entry&item)
	{
		if (empty()) return underflow;
		item = entry[Top--];
		return success;
	}

	Error_code stack::top(stack_entry&item)
	{
		if (empty()) return underflow;
		item = entry[Top];
		return success;
	}

	bool stack::empty()const {return Top == -1;}

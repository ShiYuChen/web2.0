#include "list.h"

		list::list() {count = 0;}

		bool list::empty()const {return count == 0;}

		bool list::full()const {return count == maxsize;}

		Error_code list::insert(int pos, const List_entry&x)
		{
			if (full()) return overflow;
			if (pos < 0 || pos > count) return range_error;
			for (int i = count - 1; i >= pos; i--) entry[i+1] = entry[i];
			entry[pos] = x;
			count++;
			return success;
		}
		
		Error_code list::remove(int pos, List_entry&x)
		{
			if (empty()) return underflow;
			if (pos < 0 || pos >= count) return range_error;
			x = entry[pos];
			for (int i = pos; i < count - 1; i++) entry[i] = entry[i+1];
			count--;
			return success;
		}

		Error_code list::retrieve(int pos, List_entry&x)
		{
			if (empty()) return underflow;
			if (pos < 0 || pos >= count) return range_error;
			x = entry[pos];
			return success;
		}

		Error_code list::replace(int pos, const List_entry&x)
		{
			if (empty()) return underflow;
			if (pos < 0 || pos >= count) return range_error;
			entry[pos] = x;
			return success;
		}

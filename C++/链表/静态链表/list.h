enum Error_code {success, underflow, overflow, range_error};

typedef int List_entry;

const int maxsize = 5;

class list {
	public:
		list();
		bool empty()const;
		bool full()const;
		Error_code insert(int pos, const List_entry&x);
		Error_code remove(int pos, List_entry&x);
		Error_code retrieve(int pos, List_entry&x);
		Error_code replace(int pos, const List_entry&x);
	private:
		int count;
		List_entry entry[maxsize];
};

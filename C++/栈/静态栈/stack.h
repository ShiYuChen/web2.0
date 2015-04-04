enum Error_code{success, underflow, overflow};
typedef int stack_entry;
const int maxsize = 5;

class stack
{
	public:
		stack();
		Error_code push(const stack_entry&item);
		Error_code pop();
		Error_code pop(stack_entry&item);
		Error_code top(stack_entry&item);
		bool empty()const;
	private:
		int Top;
		stack_entry entry[maxsize];
};


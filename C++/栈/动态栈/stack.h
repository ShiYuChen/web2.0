#include <cstdlib>
enum Error_code{success, underflow, overflow};

typedef int Node_entry;
typedef int stack_entry;

struct Node
{
	Node_entry entry;
	Node *next;
	
	Node(){next = NULL;}
	Node(Node_entry item, Node *old = NULL)
	{
		entry = item;
		next = old;
	}
};

class stack {
	public:
		stack();
		~stack();
		bool empty()const;
		Error_code push(const stack_entry&item);
		Error_code pop();
		Error_code pop(stack_entry&item);
		Error_code top(stack_entry&item);
		
		stack(const stack&origin);
		void operator=(const stack&origin);
	private:
		Node *Top;
}; 

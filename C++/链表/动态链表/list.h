#include <cstdlib>

typedef int Node_entry;
typedef int List_entry;

enum Error_code {success, underflow, range_error};

struct Node {
	Node_entry entry;
	Node *next, *back;
	
	Node(){next = back = NULL;}
	
	Node(Node_entry entr, Node *link_back = NULL, Node *link_next = NULL)
	{
		entry = entr;
		back = link_back;
		next = link_next;
	}
};


class list {
	public:
		list();
		void clear();
		bool empty();
		int size();
		Error_code insert(int position, const List_entry&x);
		Error_code remove(int position, List_entry&x);
		Error_code retrieve(int position, List_entry&x);
		Error_code replace(int position, const List_entry&x);
		void display();
	private:
		int count;
		int current_position;
		Node *current;
		void set_position(int position);
};

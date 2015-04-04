#include <cstdlib>
enum Error_code{success,underflow,overflow};

typedef int queue_entry;
typedef int Node_entry;

struct Node {
	Node_entry entry;
	Node *next;
	
	Node(){next == NULL;}
	Node(Node_entry item, Node *old = NULL)
	{
		entry = item;
		next = old;
	}
};


class queue {
	public:
		queue();
		~queue();
		bool empty()const;
		Error_code append(const queue_entry&item);
		Error_code serve();
		Error_code retrieve(queue_entry&item);
		Error_code retrieve_and_serve(queue_entry&item);
		
		queue(const queue&origin);
		void operator=(const queue&origin);
	private:
		Node *front, *rear;
};


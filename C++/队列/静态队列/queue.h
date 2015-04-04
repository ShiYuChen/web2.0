enum Error_code{success, underflow, overflow};

typedef int queue_entry;
const int maxsize = 5;

class queue{
	public:
		queue();
		bool empty()const;
		Error_code append(const queue_entry&item);
		Error_code serve();
		Error_code retrieve(queue_entry&item);
		Error_code retrieve_and_serve(queue_entry&item);
	private:
		int rear;
		queue_entry entry[maxsize];
};

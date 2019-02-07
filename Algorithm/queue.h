#include<assert.h>
template<class T>
class queue
{
	struct listnode {
		listnode* next;
		T value;
		listnode(listnode* node, T v): next(node), value(v) {}
	};
public:
	queue(): size(0) {}
	~queue() = default;

	void enqueue(const T& value)
	{
		if (size == 0)
		{
			begin = new listnode(nullptr, value);
			end = begin;
		}
		else
		{
			end->next = new listnode(nullptr, value);
			end = end->next;
		}
		size++;
	}

	void dequeue()
	{
		assert(size > 0);
		listnode* temp = begin;
		begin = begin->next;
		delete temp;
		size--;
	}

	T front()
	{
		return begin->value;
	}

	int length()
	{
		return size;
	}


private:
	listnode* begin;
	listnode* end;
	int size;
};
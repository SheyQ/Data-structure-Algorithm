#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
using namespace std;

class Heap
{

	typedef function<bool(int, int)> compare;

private:
	vector<int> _vec;
	int heapsize;
	compare comp;
public:
	Heap() = delete;
	~Heap() = default;

	//default minheap
	//c++11 construct with list
	//such as Heap{4,3,2,1}
	Heap(initializer_list<int> list, compare c = less<int>()): _vec(list.begin(), list.end()), heapsize(list.size()), comp(c)
	{
		for (int i = heapsize / 2 - 1; i >= 0; --i)
			siftdown(i, comp);
	}

	//construct with vector
	Heap(vector<int> vec, compare c = less<int>()): _vec(vec.begin(), vec.end()), heapsize(vec.size()), comp(c)
	{
		for (int i = heapsize / 2 - 1; i >= 0; --i)
			siftdown(i, comp);
	}
	void siftdown(int pos, compare comp);
	void insert(int value);
	int remove(int pos);
	int removeroot();

	int size()
	{
		return heapsize;
	}

	bool isLeaf(int pos) const
	{
		return pos >= heapsize / 2 && pos < heapsize;
	}

	int parent(int pos) const
	{
		return (pos - 1) / 2;
	}

	int leftchild(int pos) const
	{
		return pos * 2 + 1;
	}

	int rightchild(int pos) const
	{
		return pos * 2 + 2;
	}

	void printHeap()
	{
		for (int i = 0; i < heapsize; i++)
		{
			cout << _vec[i] << " ";
		}
		cout << endl;
	}
};

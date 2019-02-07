#include"heap.h"
void Heap::siftdown(int pos, compare comp)
{
	while (!isLeaf(pos))
	{
		int temp, temppos;
		if (rightchild(pos) < heapsize && !comp(_vec[leftchild(pos)] , _vec[rightchild(pos)]))
		{
			temppos = rightchild(pos);
			temp = _vec[temppos];
		}
		else
		{
			temppos = leftchild(pos);
			temp = _vec[temppos];
		}
		if (!comp(_vec[pos] , temp))
		{
			swap(_vec[pos], _vec[temppos]);
			pos = temppos;
		}
		else return;
	}
}

void Heap::insert(int value)
{
	int curr = heapsize++;
	_vec.push_back(value);
	while (curr != 0)
	{
		if (comp(_vec[curr] , _vec[parent(curr)]))
		{
			swap(_vec[curr], _vec[parent(curr)]);
			curr = parent(curr);
		}
		else break;
	}
}

int Heap::remove(int pos)
{
	if (pos == heapsize - 1)
	{
		_vec.pop_back();
		heapsize--;
	}
	else
	{
		swap(_vec[pos], _vec[--heapsize]);
		_vec.pop_back();
		while (pos != 0 && _vec[pos] < _vec[parent(pos)])
		{
			swap(_vec[pos], _vec[parent(pos)]);
			pos = parent(pos);
		}
		if (heapsize != 0) siftdown(pos, comp);
	}
	return _vec[heapsize];
}

int Heap::removeroot()
{
	if (heapsize == 0) return -1;
	int res = _vec[0];
	swap(_vec[0], _vec[--heapsize]);
	_vec.pop_back();
	if (heapsize != 0) siftdown(0, comp);
	return res;
}


// int main(int argc, char const *argv[])
// {
// 	//test
// 	Heap MinHeapDefault;
// 	MinHeapDefault.insert(1);
// 	MinHeapDefault.insert(6);
// 	MinHeapDefault.insert(10);
// 	MinHeapDefault.insert(14);
// 	MinHeapDefault.printHeap();
// 	Heap MaxHeapDefault([](int a, int b) {return a > b;});
// 	MaxHeapDefault.insert(6);
// 	MaxHeapDefault.insert(10);
// 	MaxHeapDefault.insert(14);
// 	MaxHeapDefault.printHeap();
// 	Heap MinHeapByList{1, 2, 4, 3, 4, 6, 8, 1, 6, 4, 2};
// 	Heap MaxHeapByList({1, 2, 4, 3, 4, 6, 8, 1, 6, 4, 2}, greater<int>());
// 	vector<int> vec{3, 3, 6, 6, 7, 3, 5, 7, 1, 6};
// 	Heap MinHeapByvector(vec);
// 	Heap MaxHeapByvector(vec, greater<int>());
// 	MinHeapByList.printHeap();
// 	MaxHeapByList.printHeap();
// 	MinHeapByvector.printHeap();
// 	MaxHeapByvector.printHeap();
// 	cout << MinHeapByvector.remove(1) << MaxHeapByvector.remove(1) << MinHeapByList.remove(1) << MaxHeapByList.remove(1);
// 	return 0;
// }
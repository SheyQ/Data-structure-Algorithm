#include"heap.h"

typedef function<bool(int, int)> compare;

void heapsort(vector<int>& vec, compare comp = less<int>()) //只接受vector容器,默认从小到大排序
{
	Heap myheap(vec, comp);
	vec.clear();
	while (myheap.size() > 0)
	{
		vec.push_back(myheap.removeroot());
	}
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	vector<int> myvec = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	heapsort(myvec);
	for (auto i : myvec)
	{
		std::cout << i << " ";
	}
	std::cout << endl;

	//8 7 5 5 3 3 2 2 1
	heapsort(myvec, greater<int>());
	for (auto i : myvec)
	{
		std::cout << i << " ";
	}
	std::cout << endl;
	return 0;
}
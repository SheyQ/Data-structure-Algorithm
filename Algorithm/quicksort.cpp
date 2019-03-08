#include<algorithm>
#include<iostream>

template<class T>
void quicksort(T* arr, int start, int end)
{
	if (start >= end) return;
	int i = start + 1, j = end, pivot = arr[start]; //轴值的选择多种多样，最稳当的方式是三点中值法(Median-of-Three)，这里简单的选择数组第一个值arr[start]为轴值
	while (i < j)
	{
		while (j != 0 && arr[j] > pivot) j--;
		while (i != j && arr[i] < pivot) i++;
		if (i < j)
			std::swap(arr[i++], arr[j--]);
	}
	std::swap(arr[j], arr[start]);
	quicksort(arr, start, j - 1);
	quicksort(arr, j + 1, end);
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	int arr[] = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	quicksort(arr, 0, 8);
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	return 0;
}

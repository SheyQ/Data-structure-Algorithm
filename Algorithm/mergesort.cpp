#include<iostream>
#include<algorithm>

template<class T>
void mergesort(T* arr, T* temp, int start, int end)
{
	int mid = (start + end) / 2;
	if (start == end) return;
	mergesort(arr, temp, start, mid);
	mergesort(arr, temp, mid + 1, end);
	for (int i = start; i <= end; ++i)
	{
		temp[i] = arr[i];
	}
	int i1 = start, i2 = mid + 1;
	for (int i = start; i <= end; i++)
	{
		if (i1 == mid + 1)
			arr[i] = temp[i2++];
		else if (i2 == end + 1)
			arr[i] = temp[i1++];
		else if (temp[i1] < temp[i2])
			arr[i] = temp[i1++];
		else
			arr[i] = temp[i2++];
	}
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	int arr[] = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	int temp[9] = {0};
	mergesort(arr, temp, 0, 8);
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	return 0;
}

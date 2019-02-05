#include<algorithm>
#include<iostream>
template<class T>
void bubblesort(T* arr, int length)
{
	if (length <= 1) return;
	for (int i = 0; i < length; ++i)
	{
		for (int j = length - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
		}
	}
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	int arr[] = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	bubblesort(arr, 9);
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	return 0;
}
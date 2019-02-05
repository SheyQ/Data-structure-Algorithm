#include<algorithm>
#include<iostream>
template<class T>
void selectsort(T* arr, int length)
{
	if (length <= 1) return;
	int minpos;
	for (int i = 0; i < length - 1; i++)
	{
		minpos = i;
		for (int j = length - 1; j > i; j--)
		{
			if (arr[j] < arr[minpos])
			{
				minpos = j;
			}
		}
		std::swap(arr[i], arr[minpos]);
	}
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	int arr[] = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	selectsort(arr, 9);
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	return 0;
}
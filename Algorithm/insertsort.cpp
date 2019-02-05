#include<algorithm>
#include<iostream>
template<class T>
void insertsort(T* arr, int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	int arr[] = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	insertsort(arr, 9);
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	return 0;
}
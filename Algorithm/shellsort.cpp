#include<algorithm>
#include<iostream>
template<class T>
void shellsort(T* arr, int length)
{
	for (int gap = length / 2; gap >= 1; gap = gap / 2)
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = gap; j < length; j += gap) //每组使用直接插入排序算法排序
			{
				for (int k = j; k >= gap; k -= gap)
				{
					if (arr[k] < arr[k - gap])
						std::swap(arr[k], arr[k - gap]);
					else
						break;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	//1 2 2 3 3 5 5 7 8
	int arr[] = {8, 5, 3, 2, 1, 5, 7, 2, 3};
	shellsort(arr, 9);
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	return 0;
}
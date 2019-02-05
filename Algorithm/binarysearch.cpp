template<class T>
int binarysearch(T* arr, int length, int target)
{
	int left = 0, right = length - 1;
	int mid = 0;
	if (length == 0) return -1;
	while (left <= right)
	{
		//mid=(left+right)/2;
		//防止溢出
		mid = left + (right - left) / 2;
		if (target > arr[mid])
		{
			left = mid + 1;
		}
		else if (target < arr[mid])
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}

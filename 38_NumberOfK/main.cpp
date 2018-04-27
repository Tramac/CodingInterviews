#include <iostream>

using namespace std;

int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	int midvalue = data[mid];

	if (midvalue == k)
	{
		if ((mid > 0 && data[mid - 1] != k) || mid == 0)
			return mid;
		else
			end -= 1;
	}
	else if (midvalue < k)
		start = mid + 1;
	else
		end = mid - 1;
	return GetFirstK(data, length, k, start, end);
}

int GetLastK(int* data, int length, int k, int start, int end)
{
	if (end < start)
		return -1;
	int mid = (start + end) / 2;
	int midvalue = data[mid];

	if (midvalue == k)
	{
		if ((mid < length - 1 && data[mid + 1] != k) || mid == length - 1)
			return mid;
		else
			start += 1;
	}
	else if (midvalue < k)
		start = mid + 1;
	else
		end = mid - 1;
	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int* data, int length, int k)
{
	if (data == NULL || length <= 0)
		return -1;
	int count = 0;
	int firstindex = GetFirstK(data, length, k, 0, length - 1);
	int lastindex = GetLastK(data, length, k, 0, length - 1);
	
	if (firstindex > -1 && lastindex > -1)
		count = lastindex - firstindex + 1;
	return count;
}

int main()
{
	int data[8] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	int n = GetNumberOfK(data, 8, 3);
	cout << n << endl;
	return 0;
}

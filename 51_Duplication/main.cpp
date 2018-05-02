#include <iostream>

using namespace std;

bool duplicate(int arr[], int length, int* duplication)
{
	if (arr == NULL || length <= 0)
		return false;
	
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < 0 || arr[i] > length - 1)
			return false;
	}
	
	for (int i = 0; i < length; ++i)
	{
		while (arr[i] != i)
		{
			if (arr[arr[i]] == arr[i])
			{
				*duplication = arr[i];
				return true;
			}
			else
			{
				int temp = arr[arr[i]];
				arr[arr[i]] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return false;
}

int main()
{
	int arr[7] = { 2, 3, 1, 0, 2, 5, 3 };
	int duplication;
	bool result = duplicate(arr, 7, &duplication);
	if (result)
		cout << duplication << endl;
	return 0;
}

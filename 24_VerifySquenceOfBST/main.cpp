#include<iostream>

using namespace std;

bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
		return false;
	int root = sequence[length - 1];
	int i;
	for (i = 0; i < length - 1; ++i)
	{
		if (sequence[i] > root)
			break;
	}
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}

	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBST(sequence, i);
	bool right = true;
	if (j < length - 1)
		right = VerifySquenceOfBST(sequence + i, length - i - 1);

	return (left && right);
}

int main()
{
	int arr[7] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << VerifySquenceOfBST(arr, 7) << endl;
	return 0;
}

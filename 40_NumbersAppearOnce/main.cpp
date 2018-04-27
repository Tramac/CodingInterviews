#include <iostream>

using namespace std;

int FindFirstBit1(int n)
{
	int index = 0;
	while (((n & 1) == 0) && (index < 8 * sizeof(int)))
	{
		n = n >> 1;
		++index;
	}
	return index;
}

bool isBit1(int num, int index)
{
	num = num >> index;
	return (num & 1);
}

void FindNumsAppearOnce(int* data, int length, int* num1, int* num2)
{
	if (data == NULL || length < 2)
		return;
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
	{
		resultExclusiveOR ^= data[i];
	}
	int fisrt1 = FindFirstBit1(resultExclusiveOR);
	*num1 = *num2 = 0;
	for (int i = 0; i < length; ++i)
	{
		if (isBit1(data[i], fisrt1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}

int main()
{
	int data[8] = {2, 4, 3, 6, 3, 2, 5, 5};
	int num1, num2;
	FindNumsAppearOnce(data, 8, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}

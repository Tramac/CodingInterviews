#include <iostream>

using namespace std;

bool FindNumbersWithSum(int* data, int length, int s, int* num1, int* num2)
{
	bool found = false;
	if (data == NULL || length <2)
		return false;
	int start = 0;
	int end = length - 1;
	while (start < end)
	{
		if (data[start] + data[end] == s)
		{
			*num1 = data[start];
			*num2 = data[end];
			found = true;
			break;
		}
		else if (data[start] + data[end] < s)
			start++;
		else
			end--;
	}
	return found;
}

int main()
{
	int data[6] = { 1, 2, 4, 7, 11, 15 };
	int s = 15;
	int num1, num2;
	bool found = FindNumbersWithSum(data, 6, s, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}

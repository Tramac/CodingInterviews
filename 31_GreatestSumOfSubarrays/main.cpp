#include <iostream>

using namespace std;

bool g_bInvalidInput = false;
int FindGreatestSumOfArray(int* data, int length)
{
	if (data == NULL || length <= 0)
	{
		g_bInvalidInput = true;
		return 0;
	}
	g_bInvalidInput = false;
	int currentSum = 0;
	int GreatestSum = 0x80000000;
	for (int i = 0; i < length; ++i)
	{
		if (currentSum <= 0)
		{
			currentSum = data[i];
		}
		else
			currentSum += data[i];
		GreatestSum = GreatestSum > currentSum ? GreatestSum : currentSum;
	}
	return GreatestSum;
}
int main()
{
	int data[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int result = FindGreatestSumOfArray(data, 8);
	cout << result << endl;
	return 0;
}

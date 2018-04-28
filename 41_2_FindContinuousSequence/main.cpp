#include <iostream>

using namespace std;

void FindContinuousSequence(int s)
{
	if (s < 3)
		return;
	int start = 1, end = 2;
	int currentSum = 3;
	while (start <= ((1 + s) / 2) && end < s)
	{
		if (currentSum == s)
		{
			for (int i = start; i <= end; i++)
			{
				cout << i << " ";
			}
			cout << endl;
			end++;
			currentSum += end;
		}
		else if (currentSum < s)
		{
			end++;
			currentSum += end;
		}
		else
		{
			currentSum -= start;
			start++;
		}
	}
	return;
}
int main()
{
	int s = 15;
	FindContinuousSequence(s);
	return 0;
}

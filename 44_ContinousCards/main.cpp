#include <iostream>

using namespace std;

int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}

bool IsContinuous(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		return false;
	qsort(numbers, length, sizeof(int), compare);

	int numberOfzero = 0;
	int numberOfGap = 0;

	for (int i = 0; i < length && numbers[i] == 0; ++i)
	{
		numberOfzero++;
	}
	for (int i = numberOfzero; i < length - 1; ++i)
	{
		if (numbers[i + 1] == numbers[i])
			return false;
		else
			numberOfGap += (numbers[i + 1] - numbers[i] - 1);
	}
	return (numberOfGap > numberOfzero) ? false : true;
}

int main()
{
	int data[6] = { 0, 1, 2, 5, 6, 7 };
	bool result = IsContinuous(data, 6);
	cout << result << endl;
	return 0;
}

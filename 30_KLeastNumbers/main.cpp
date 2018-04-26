#include <iostream>

using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* numbers, int length, int start, int end)
{
	if (numbers == NULL || length <= 0)
		return 0;
	int index = (start + end) / 2;
	Swap(&numbers[index], &numbers[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (numbers[index] < numbers[end])
		{
			small++;
			if (small != index)
				Swap(&numbers[small], &numbers[index]);
		}
	}
	small++;
	Swap(&numbers[small], &numbers[end]);
	return small;
}

void GetLeastNumbers(int* numbers, int length, int k)
{
	if (numbers == NULL || length <= 0 || k <= 0 || k > length)
		return;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);

	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}
	for (int i = 0; i < k; ++i)
	{
		cout << numbers[i] << endl;
	}
}

int main()
{
	int data[8] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	GetLeastNumbers(data, 8, 4);
	return 0;
}

#include <iostream>

using namespace std;

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end) // 只有一个元素时，最小子问题
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + length); // 左侧逆序对数
	int right = InversePairsCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int copyindex = end;
	int count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			count += (j - start - length);
			copy[copyindex] = data[i];
			i--;
			copyindex--;
		}
		else
		{
			copy[copyindex] = data[j];
			j--;
			copyindex--;
		}
	}

	while (i >= start)
	{
		copy[copyindex] = data[i];
		i--;
		copyindex--;
	}
	while (j >= start + length + 1)
	{
		copy[copyindex] = data[j];
		j--;
		copyindex--;
	}
	return count + left + right;
}

int InversePairs(int* data, int length)
{
	if (data == NULL || length <= 0)
		return 0;
	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = data[i];
	}
	int result = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;
	return result;
}

int main()
{
	int data[4] = { 7, 5, 6, 4 };
	int result = InversePairs(data, 4);
	cout << result << endl;
	return 0;
}

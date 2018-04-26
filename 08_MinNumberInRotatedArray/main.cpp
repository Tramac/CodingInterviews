# include <stdio.h>
# include <exception>

int Min(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters.");
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1; // 如果把排序数组的前面0个元素搬到最后面，所以indexMid初始为index1
	while (numbers[index1] > numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[index1] <= numbers[indexMid])
			index1 = indexMid;
		else if (numbers[index2] >= numbers[indexMid])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

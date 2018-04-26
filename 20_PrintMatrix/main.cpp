# include <stdio.h>
# include <iostream>

void PrintMatrixInCircle(int ** numbers, int columns, int rows, int start)
{
	if (numbers == NULL || columns <= 0 || rows <= 0 || start > columns || start > rows)
		return;
	int endX = columns - start - 1;
	int endY = rows - start - 1;
	for (int i = start; i <= endX; ++i)
	{
		std::cout << numbers[start][i];
	}
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
			std::cout << numbers[i][endX];
	}
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
			std::cout << numbers[endY][i];
	}
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i > start; --i)
			std::cout << numbers[i][start];
	}
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	}
}

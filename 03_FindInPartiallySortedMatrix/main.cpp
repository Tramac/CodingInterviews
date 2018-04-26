#include <stdio.h>
#include <tchar.h>

bool Find(int* matrix, int rows, int columns, int number)
{
	if (matrix == NULL || rows <= 0 || columns <= 0)
		return false;
	int row_begin = 0;
	int column_begin = columns - 1;
	while (row_begin < rows && 0 <= column_begin)
	{
		if (matrix[row_begin*columns + column_begin] == number)
			return true;
		else if (matrix[row_begin*columns + column_begin] > number)
		    column_begin --;
		else
			row_begin++;
	}
	return false;
}

void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	bool result = Find(matrix, rows, columns, number);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();

	return 0;
}

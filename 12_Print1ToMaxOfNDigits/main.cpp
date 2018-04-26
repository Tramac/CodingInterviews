# include <string>

bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1) //末位加1
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break; //如果有一位加一后没有产生进位，则跳出循环
		}
	}
	return isOverflow;
}

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}

void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[]number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void Print1ToMaxOfNDigits_Recursively(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}


int main()
{
	int n = 2;
	Print1ToMaxOfNDigits_Recursively(n);
}

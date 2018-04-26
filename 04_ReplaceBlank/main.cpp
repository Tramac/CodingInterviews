#include <string>
#include <stdio.h>
#include <tchar.h>

void ReplaceBlank(char string[], int length)
{
	if (string == NULL || length <= 0)
		return;
	int originalLength = 0;
	int num_blank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++originalLength;
		if (string[i] == ' ')
			++num_blank;
		++i;
	}
	int newLength = originalLength + num_blank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
			string[indexOfNew--] = string[indexOfOriginal];
		--indexOfOriginal;
	}
}

void Test(char* testName, char string[], int length, char expected[])
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	ReplaceBlank(string, length);

	if (expected == NULL && string == NULL)
		printf("passed.\n");
	else if (expected == NULL && string != NULL)
		printf("failed.\n");
	else if (strcmp(string, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
	const int length = 100;

	char string[length] = "hello world";
	Test("Test1", string, length, "hello%20world");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();

	return 0;
}

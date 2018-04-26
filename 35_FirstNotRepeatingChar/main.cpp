#include <iostream>

using namespace std;

char FirstNotRepeatingChar(char* pString)
{
	if (pString == NULL)
		return '\0';
	int charNums[256] = {};
	char* currentChar = pString;
	while (*currentChar != '\0')
	{
		charNums[*currentChar] += 1;
		currentChar++;
	}
	currentChar = pString;
	char result;
	while (currentChar != '\0')
	{
		if (charNums[*currentChar] == 1)
		{
			result = *currentChar;
			break;
		}
		currentChar++;
	}
	return result;
}

int main()
{
	char s[] = "abaccdeff";
	char result = FirstNotRepeatingChar(s);
	cout << result << endl;
	return 0;
}

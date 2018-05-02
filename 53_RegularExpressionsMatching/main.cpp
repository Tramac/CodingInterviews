#include <iostream>

using namespace std;

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*str == *pattern || *pattern == '.')
			return matchCore(str + 1, pattern) || matchCore(str + 1, pattern + 2) || matchCore(str, pattern + 2);
		else
			return matchCore(str, pattern + 2);
	}
	if (*str == *pattern || *pattern == '.')
		return matchCore(str + 1, pattern + 1);
	return false;
}

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;
	return matchCore(str, pattern);
}

int main()
{
	char str[] = "aaa";
	char pattern[] = "ab*a";
	bool result = match(str, pattern);
	cout << result << endl;
	return 0;
}

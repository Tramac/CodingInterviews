#include <iostream>

using namespace std;

void Reverse(char* begin, char* end)
{
	if (begin == NULL || end == NULL)
		return;

	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}

char* LeftRotatesString(char* str, int n)
{
	if (str == NULL || n < 0)
		return NULL;
	char* start1 = str;
	char* end1 = str + n - 1;
	char* start2 = end1 + 1;
	char* end2 = str;
	while (*end2 != '\0')
		end2++;
	end2--;

	Reverse(start1, end1);
	Reverse(start2, end2);
	Reverse(start1, end2);
	return str;
}

int main()
{
	char str[] = "abcdefg";
	int n = 2;
	char* result = LeftRotatesString(str, n);
	cout << result << endl;
	return 0;
}

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

char* ReverseSentence(char* data)
{
	if (data == NULL)
		return NULL;
	char* start = data;
	char* end = data;
	while (*end != '\0')
		end++;
	end--;
	Reverse(start, end);
	end = data;
	while (*end != '\0')
	{
		if (*start == ' ')
		{
			start++;
			end++;
		}
		else if (*end == ' ' || *end == '\0')
		{
			end--;
			Reverse(start, end);
			end++;
			start = end;
		}
		else
			end++;
	}
}

int main()
{
	char s[] = "I am a student.";
	char* result = ReverseSentence(s);
	cout << s << endl;
	return 0;
}

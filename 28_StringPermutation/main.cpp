#include <iostream>
using namespace std;

void Permutation(char* str, char* begin)
{
	if (*begin == '\0')
		cout << endl;
	else
	{
		for (char* ch = begin; ch != '\0'; ++ch)
		{
			char temp = *begin;
			*begin = *ch;
			*ch = temp;

			Permutation(str, begin + 1);

			temp = *begin;
			*begin = *ch;
			*ch = temp;
		}
	}
}

void Permutation(char* str)
{
	if (str == NULL)
		return;
	Permutation(str, str);
}

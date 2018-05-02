#include <iostream>

using namespace std;

void scanDigits(char** str)
{
	while (**str != '\0' && (**str >= '0' && **str <= '9'))
		(*str)++;
}

bool isExponential(char** str)
{
	if (**str != 'e' && **str != 'E')
		return false;
	++(*str);
	if (**str == '+' || **str == '-')
		(*str)++;
	if (**str == '\0')
		return false;
	scanDigits(str);
	return (**str == '\0') ? true : false;
}

bool isNumeric(char* str)
{
	if (str == NULL)
		return false;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return false;

	bool numeric = true;
	scanDigits(&str);
	if (*str != '\0')
	{
		if (*str == '.')
		{
			++str;
			scanDigits(&str);
			if (*str == 'e' || *str == 'E')
				numeric = isExponential(&str);
		}
		else if (*str == 'e' || *str == 'E')
			numeric = isExponential(&str);
		else
			numeric = false;
	}
	return numeric && *str == '\0';
}

int main()
{
	char str[] = "-1.e+05";
	bool result = isNumeric(str);
	cout << result << endl;
	return 0;
}

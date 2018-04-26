#include <iostream>

using namespace std;

int Min(int number1, int number2, int number3)
{
	int min = number1 > number2 ? number1 : number2;
	min = min > number3 ? min : number3;
	return min;
}

int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	int* UglyNumbers = new int[index];
	UglyNumbers[0] = 1;
	int nextUglyindex = 1;

	int* Multiply2 = UglyNumbers;
	int* Multiply3 = UglyNumbers;
	int* Multiply5 = UglyNumbers;

	while (nextUglyindex < index)
	{
		int min = Min(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
		UglyNumbers[nextUglyindex] = min;

		if (min <= *Multiply2 * 2) Multiply2++;
		else if (min <= *Multiply3 * 3) Multiply3++;
		else Multiply5++;

		nextUglyindex++;
	}
	int result = UglyNumbers[index - 1];
	delete[] UglyNumbers;
	return result;
}

int main()
{
	int result = GetUglyNumber(1500);
	cout << result << endl;
	return 0;
}

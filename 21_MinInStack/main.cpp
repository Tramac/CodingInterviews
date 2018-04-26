#include<stdio.h>
int Dst(int n)
{
	int sum = n;
	n = n / 2;
	while (n > 0)
	{
		sum += n*2;
		n /= 2;
	}
	return sum;
}
void main()
{
	printf("%d", Dst(100)+Dst(90)+Dst(80)+Dst(70));
}

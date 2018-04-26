long long Fibonacci(unsigned n)
{
	int results[2] = { 0, 1 };
	if (n <2)
		return results[n];
	long long FibonacciOne = 0;
	long long FibonacciTwo = 1;
	long long FibN = 0;
	for (unsigned int i = 2; i < n; i++)
	{
		FibN = FibonacciOne + FibonacciTwo;
		FibonacciOne = FibonacciTwo;
		FibonacciTwo = FibN;
	}
	return FibN;
}

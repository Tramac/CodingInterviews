bool g_InvalidInput = false;

bool equal(double num1, double num2)
{
	if (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (unsigned int i = 1; i <= exponent; i++)
	{
		result = result * base;
	}
	return result;
}

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent<0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

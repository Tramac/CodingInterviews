# include <stdio.h>

void ReorderOddEven(int* pData, unsigned int length)
{
	if (pData == NULL || length == 0)
		return;
	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;
		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
			pEnd--;
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

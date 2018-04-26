#include <iostream>
#include <stack>

using namespace std;

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;
	if (pPush != NULL && pPop != NULL && nLength > 0)
	{
		stack<int> stackData;
		const int *pNextPush = pPush;
		const int *pNextPop = pPop;

		while (pNextPop - pPop < nLength)
		{
			while (stackData.empty() || *pNextPop != stackData.top())
			{
				if (pNextPush - pPush >= nLength)
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if (*pNextPop != stackData.top())
				break;
			stackData.pop();
			pNextPop++;
		}
		if (stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}
	return bPossible;
}

int main()
{
	int s1[5] = { 1, 2, 3, 4, 5 };
	int s2[5] = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder(s1, s2, 5) << endl;
	return 0;
}

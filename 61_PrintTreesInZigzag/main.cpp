#include <iostream>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Print(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	stack<BinaryTreeNode*> levels[2];
	int current = 0;
	int next = 1;
	levels[0].push(pRoot);
	while (!levels[current].empty() || !levels[next].empty())
	{
		BinaryTreeNode* pNode = levels[current].top();
		cout << pNode->m_nValue;
		levels[current].pop();

		if (current == 0)
		{
			if (pNode->m_pLeft)
				levels[next].push(pNode->m_pLeft);
			if (pNode->m_pRight)
				levels[next].push(pNode->m_pRight);
		}
		else
		{
			if (pNode->m_pRight)
				levels[next].push(pNode->m_pRight);
			if (pNode->m_pLeft)
				levels[next].push(pNode->m_pLeft);
		}
		if (levels[current].empty())
		{
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}

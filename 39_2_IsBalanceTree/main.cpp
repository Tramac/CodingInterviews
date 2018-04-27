#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool IsBalanceTree(BinaryTreeNode* pRoot, int* depth)
{
	if (pRoot == NULL)
	{
		*depth = 0;
		return true;
	}
	int left_depth, right_depth;
	if (IsBalanceTree(pRoot->m_pLeft, &left_depth) && IsBalanceTree(pRoot->m_pRight, &right_depth))
	{
		int diff = left_depth - right_depth;
		if (diff <= 1 && diff >= -1)
		{
			*depth = left_depth > right_depth ? (left_depth + 1) : (right_depth + 1);
			return true;
		}
	}
	return false;
}

bool IsBalanceTree(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanceTree(pRoot, &depth);
}

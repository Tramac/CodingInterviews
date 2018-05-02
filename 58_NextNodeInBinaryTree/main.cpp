#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
		return NULL;
	BinaryTreeNode* pNext = NULL;
	if (pNode->m_pRight != NULL)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != NULL)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	else if (pNode->m_pParent != NULL)
	{
		BinaryTreeNode* pParent = pNode->m_pParent;
		BinaryTreeNode* pCurrent = pNode;
		while (pParent != NULL && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pCurrent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

# include <stdio.h>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Mirror(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
		return;
	if (pNode->m_pLeft == NULL && pNode->m_pRight)
		return;
	BinaryTreeNode* temp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = temp;

	if (pNode->m_pLeft)
		Mirror(pNode->m_pLeft);
	if (pNode->m_pRight)
		Mirror(pNode->m_pRight);
}

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeOfList)
{
	if (pNode == NULL)
		return;
	if (pNode->m_pLeft)
	{
		ConvertNode(pNode->m_pLeft, pLastNodeOfList);
	}
	pNode->m_pLeft = *pLastNodeOfList;
	if (*pLastNodeOfList != NULL)
		(*pLastNodeOfList)->m_pRight = pNode;
	*pLastNodeOfList = pNode;
	if (pNode->m_pRight)
		ConvertNode(pNode->m_pRight, pLastNodeOfList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRoot, &pLastNodeInList);

	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList->m_pLeft)
		pHeadOfList = pHeadOfList->m_pLeft;
	return pHeadOfList;
}

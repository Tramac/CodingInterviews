#include <iostream>

using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibing;
};

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode* pClone = new ComplexListNode();
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;
		pClone->m_pSibing = NULL;

		pNode->m_pNext = pClone;
		pNode = pClone->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode* pClone = pNode->m_pNext;
		if (pNode->m_pSibing != NULL)
		{
			pClone->m_pSibing = pNode->m_pSibing->m_pNext;
		}
		pNode = pClone->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead;
	ComplexListNode* pClone;

	if (pNode != NULL)
	{
		pCloneHead = pClone = pNode->m_pNext;
		pNode = pClone->m_pNext;
	}
	while (pNode != NULL)
	{
		pClone->m_pNext = pNode->m_pNext;
		pClone = pClone->m_pNext;
		pNode->m_pNext = pClone->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pCloneHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

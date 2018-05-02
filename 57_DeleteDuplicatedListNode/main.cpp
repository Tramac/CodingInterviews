#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* deleteDuplication(ListNode** pHead)
{
	if (pHead == NULL || *pHead == NULL)
		return NULL;
	ListNode* pPreNode = NULL;
	ListNode* pNode = *pHead;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext->m_pNext != NULL && (pNext->m_nValue == pNode->m_nValue))
			needDelete = true;
		if (!needDelete)
		{
			pPredNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != NULL && (pToBeDel->m_nValue == value))
			{
				pNext = pToBeDel->m_pNext;
				delete pToBeDel;
				pToBeDel = NULL;

				pToBeDel = pNext;
			}
			if (pPreNode == NULL)
			{
				*pHead = pNext;
			}
			else
			{
				pPreNode->m_pNext = pNext;
			}
			pNode = pNext;
		}

	}
}

# include <stdio.h>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode->m_pNext != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL)
			pReversedHead = pNode;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}

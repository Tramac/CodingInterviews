# include <stdio.h>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pMergedHead = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergedHead->m_nValue = pHead1->m_nValue;
		pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergedHead->m_nValue = pHead2->m_nValue;
		pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	return pMergedHead;
}

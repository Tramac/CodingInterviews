#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == NULL)
		return NULL;
	ListNode* pFast = pSlow->m_pNext;
	while (pFast != NULL && pSlow != NULL)
	{
		if (pFast == pSlow)
			return pFast;
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast)
			pFast = pFast->m_pNext;
	}
	return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == NULL)
		return NULL;
	int count = 1;
	ListNode* pNode = meetingNode->m_pNext;
	while (pNode != meetingNode)
		count++;
	ListNode* pNode1 = pHead;
	ListNode* pNode2 = pHead;
	for (int i = 0; i < count; ++i)
		pNode2 = pNode2->m_pNext;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
}

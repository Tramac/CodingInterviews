#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

int GetListLength(ListNode* pHead)
{
	if (pHead == NULL)
		return 0;
	ListNode* pNode = pHead;
	int length = 0;
	while (pNode->m_pNext != NULL)
		length++;
	return length;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	int length1 = GetListLength(pHead1);
	int length2 = GetListLength(pHead2);

	ListNode* pLong;
	ListNode* pShort;
	int lengthDiff;

	if (length1 > length2)
	{
		pLong = pHead1;
		pShort = pHead2;
		lengthDiff = length1 - length2;
	}
	else
	{
		pLong = pHead2;
		pShort = pHead1;
		lengthDiff = length2 - length1;
	}
	for (int i = 0; i < lengthDiff; i++)
		pLong = pLong->m_pNext;
	while (pLong != NULL && pShort != NULL && pLong != pShort)
	{
		pLong = pLong->m_pNext;
		pShort = pShort->m_pNext;
	}
	ListNode* FirstCommonNode = pLong;
	return FirstCommonNode;
}

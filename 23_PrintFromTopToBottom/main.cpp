#include <iostream>
#include <deque>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != NULL)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if (pTreeRoot != NULL)
	{
		deque<BinaryTreeNode *> dequeTreeNode;
		dequeTreeNode.push_back(pTreeRoot);
		while (dequeTreeNode.size())
		{
			BinaryTreeNode* pNode = dequeTreeNode.front();
			dequeTreeNode.pop_front();

			printf("%d ", pNode->m_nValue);
			if (pNode->m_pLeft)
				dequeTreeNode.push_back(pNode->m_pLeft);
			if (pNode->m_pRight)
				dequeTreeNode.push_back(pNode->m_pRight);
		}
	}
}

void Test(char* testName, BinaryTreeNode* pRoot)
{
	if (testName != NULL)
	{
		printf("%s begins: \n", testName);
	}
	printf("The nodes from top to bottom, from left to right are: \n");
	PrintFromTopToBottom(pRoot);
	printf("\n\n");
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

int main()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	Test("Test1", pNode10);
	DestroyTree(pNode10);
	return 0;
}

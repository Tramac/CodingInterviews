#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void PrintTreesInLines(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);
	int numPrint = 1;
	int nextPrint = 0;
	while (!nodes.empty())
	{
		BinaryTreeNode* currentNode = nodes.front();
		cout << currentNode->m_nValue;
		if (currentNode->m_pLeft)
		{
			nodes.push(currentNode->m_pLeft);
			nextPrint++;
		}
		if (currentNode->m_pRight)
		{
			nodes.push(currentNode->m_pRight);
			nextPrint++;
		}
		nodes.pop();
		numPrint--;
		if (numPrint == 0)
		{
			cout << endl;
			numPrint = nextPrint;
			nextPrint = 0;
		}
	}

}

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot, int expectedsum)
{
	if (pRoot == NULL)
		return;
	int currentSum = 0;
	vector<int> path;
	FindPath(pRoot, currentSum, path, expectedsum);
}

void FindPath(BinaryTreeNode* pRoot, int currentSum, vector<int>& path, int expectedsum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isBeaf = (pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL);
	if (currentSum == expectedsum && isBeaf)
	{
		cout << "Find one path:" << endl;
		for (int i = 0; i < path.size(); ++i)
		{
			cout << path[i] << " ";
		}
		cout << endl;
	}
	if (pRoot->m_pLeft)
	{
		FindPath(pRoot->m_pLeft, currentSum, path, expectedsum);
	}
	if (pRoot->m_pRight)
		FindPath(pRoot->m_pRight, currentSum, path, expectedsum);
	path.pop_back();
}

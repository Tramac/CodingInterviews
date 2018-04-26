# include <stdio.h>

struct BinaryTreeNode
{
	int m_nKey;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	else
	{
		BinaryTreeNode* RootNode = NULL;
		BinaryTreeNode* LeftChildNode = NULL;
		BinaryTreeNode* pRightChildNode = NULL;
		RootNode->m_nKey = preorder[0];
		if (length == 1)
			return RootNode;
		else
		{
			int NumbersOfLeft = 0;
			int i = 0;
			while (inorder[i] != RootNode->m_nKey)
			{
				++NumbersOfLeft;
				++i;
			}
			left_preorder = preorder[1:NumbersOfLeft];
			left_inorder = inorder[0:NumbersOfLeft - 1];
			LeftChildNode = Construct(left_preorder, left_inorder, NumbersOfLeft);
			NumbersOfRight = length - NumbersOfLeft;
			right_preorder = preorder[NumbersOfLeft + 1:];
			right_inorder = inorder[NumbersOfLeft + 1:];
			RightChildNode = Construct(right_preorder, right_inorder, NumbersOfRight);
		}
	}
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode;
	root->m_nKey = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder) //只有一个元素
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

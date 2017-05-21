#include "Tree.h"


Tree::Tree()
{
	root = NULL;
	nodeNum = 0;
	lastErr = Default;
}

Tree::~Tree()
{
	DelTree(root);
}

node *Tree::CreateNode(int key, int val)
{
	node *pNode = new node;
	pNode->key = key;
	pNode->val = val;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}

tree_err Tree::DelLeaf(node *pLeaf)
{
	if (pLeaf->left != NULL || pLeaf->right != NULL)
		return lastErr = DelNotLeaf;
	if (pLeaf == NULL)
		return lastErr = NodeNotExist;
	if (nodeNum <= 0)
		return lastErr = TreeNotExist;
	delete(pLeaf);
	pLeaf = NULL;
	nodeNum--;
	return lastErr = Succeed;
}

tree_err Tree::DelTree(node *pNode)
{
	if (nodeNum <= 0)
		return lastErr = Succeed;
	if (pNode->left != NULL)
	if((lastErr = DelTree(pNode->left)) != Succeed)
			return lastErr;
	if (pNode->right != NULL)
	if ((lastErr = DelTree(pNode->right)) != Succeed)
		return lastErr;
	return lastErr = DelLeaf(pNode);
}

node *Tree::AddNode(node *pTree, node *pNode)
{
	if (pTree == NULL)
	{
		nodeNum++;
		lastErr = Succeed;
		return pNode;
	}
	if (pTree->val < pNode->val)	// 插入的结点堆更大
	{
		node *pn = pTree;
		if (pNode->key < pTree->key)
		{
			while (pn->left != NULL)
			{
				if (pNode->key < pn->left->key)
					pn = pn->left;
				else break;
			}
			pNode->left = pn->left;
			pNode->right = pTree;
			pn->left = NULL;
		}
		else
		{
			while (pn->right != NULL)
			{
				if (pNode->key > pn->right->key)
					pn = pn->right;
				else break;
			}
			pNode->right = pn->right;
			pNode->left = pTree;
			pn->right = NULL;
		}
		nodeNum++;
		lastErr = Succeed;
		return pNode;
	}
	else
	{
		if (pNode->key < pTree->key)
			pTree->left = AddNode(pTree->left, pNode);
		else
			pTree->right = AddNode(pTree->right, pNode);
		nodeNum++;
		lastErr = Succeed;
		return pTree;
	}
}

int Tree::TreeWidth(node *tree)
{
	if (tree == NULL)
		return 0;
	if (tree->left == NULL && tree->right == NULL)
		return 1;
	return TreeWidth(tree->left)+TreeWidth(tree->right);
}

int Tree::TreeDepth(node *tree)
{
	if (tree == NULL)
		return 0;
	int dep;
	MAX(TreeDepth(tree->left), TreeDepth(tree->right), &dep);
	return dep + 1;
}

tree_err Tree::PrintTree(node *tree, int dep)
{
	if (dep == 1) printf("  ");
	if (tree == NULL)
	{
		printf("NULL\n");
		return Succeed;
	}
	printf("(%3d,%3d)", tree->key, tree->val);
	if (tree->right == NULL)
	{
		printf("─");
		PrintTree(tree->left, dep + 1);
	}
	else
	{
		printf("┬");
		PrintTree(tree->left, dep + 1);
		PrintBland(dep);
		printf("└");
		PrintTree(tree->right, dep + 1);
	}
	return Succeed;
}

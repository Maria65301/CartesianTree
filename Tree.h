#pragma once
#include "afx.h"

typedef struct node_t{
	int key;
	int val;
	node_t *left;
	node_t *right;
}node;

enum tree_err{
	Default,
	Succeed,
	DelNotLeaf,		// 当前删除的结点不是叶子结点
	NodeNotExist,	// 当前指针所指的结点为空
	TreeNotExist	// 二叉树不存在
};

class Tree
{
public:
	Tree();
	virtual ~Tree();

private:
	node *root;
	int nodeNum;
	tree_err lastErr;
public:
	node *getRoot(){ return root; }
	void setRoot(node *ROOT){ root = ROOT; }
	int getNodeNum(){ return nodeNum; }
	tree_err getLastErr(){ return lastErr; }

	void PrintBland(int d){ for (int i = 0; i < d; i++) printf("           "); }

public:
	node *CreateNode(int, int);		// 创造一个结点
	tree_err DelLeaf(node *);		// 删除一个指定叶子结点
	tree_err DelTree(node *);		// 删除树
	node *AddNode(node *, node *);	// 插入一个结点
	int TreeWidth(node *);			// 计算宽度
	int TreeDepth(node *);			// 计算深度
	tree_err PrintTree(node *, int);// 打印树
};

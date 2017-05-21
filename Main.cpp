#include "Tree.h"

int main(int argv, char *argc[])
{
	int num;
	couple *arr;
	if (argv > 1)
		sscanf_s(argc[1], "%d", &num);
	else
	{
		printf("Please input number of couples.\n");
		scanf_s("%d", &num);
		getchar();
	}
	printf("The  number of couples is %d.\n", num);
	arr = new couple[num];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < num; i++)
	{
		arr[i].key = rand() % 199 - 100;
		arr[i].val = rand() % 199 - 100;
	}
	for (int i = 0; i < num; i++)
	{
		printf("[%2d] (%3d,%3d)\n", i + 1, arr[i].key, arr[i].val);
	}
	printf("====\n");
	Tree *tree = new Tree;
	for (int i = 0; i < num; i++)
	{
		node *pNode = tree->CreateNode(arr[i].key, arr[i].val);
		tree->setRoot(tree->AddNode(tree->getRoot(), pNode));
	}
	tree->PrintTree(tree->getRoot(), 1);
	getchar();
	delete(arr);
	arr = NULL;
	delete(tree);
	tree = NULL;
	return 0;
}

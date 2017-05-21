#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(a,b,c) int x=(a),y=(b);*(c)=x>y?x:y

typedef struct couple_t{
	int key;	// 二叉查找树
	int val;	// 最大堆
}couple;

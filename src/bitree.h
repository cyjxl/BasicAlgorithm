#ifndef _BITREE_H
#define _BITREE_H
#ifdef __cpluscplus
extern "C" {
#endif
#define MAX_BINODE_NUM	(100)

typedef char ElemType;

typedef struct BiNode{
	struct BiNode *lchild;
	struct BiNode *rchild;
	ElemType data;
}BiNode,*BiTree;


void CreateBiTree(BiTree *T,ElemType input[],int *pos);
void BiTreePreOrder(BiTree T,void(*visit)(BiNode *p));
void BiTreePreOrderTravse(BiTree T,void(*visit)(BiNode *p));

#ifdef __cpluscplus
}
#endif

#endif
#ifndef _BITREE_H
#define _BITREE_H


#ifdef __cplusplus
extern "C"{
#endif

#define MAX_BINODE_NUM	(100)
typedef char ElemType;
typedef struct BiNode{
	struct BiNode *lchild;
	struct BiNode *rchild;
	ElemType data;
}BiNode,*BiTree;

void Visit(BiNode *p);
void CreateBiTree(BiTree *T,ElemType input[],int *pos);
void BiTreePreOrder(BiTree bt,void(*visit)(BiNode *p));
void BiTreeInOrder(BiTree bt,void(*visit)(BiNode *p));
void BiTreePostOrder(BiTree bt,void(*visit)(BiNode *p));
void BiTreePreOrderTravse(BiTree bt,void(*visit)(BiNode *p));
void BiTreeInOrderTravse(BiTree bt,void(*visit)(BiNode *p));
#ifdef __cplusplus
}
#endif

#endif
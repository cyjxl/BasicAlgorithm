/********************************************************************
CopyRight：拿走不谢
Author：lvxulin
CreateTime：2019.8.20
Desc：此文件主要是实现二叉树相关的操作
*********************************************************************/


typedef char ElemType;
typedef struct BiNode{
	struct BiNode *lchild;
	struct BiNode *rchild;
	ElemType data;
}BiNode,*BiTree;


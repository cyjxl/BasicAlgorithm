/********************************************************************
CopyRight：拿走不谢
Author：lvxulin
CreateTime：2019.8.20
Desc：此文件主要是实现二叉树相关的操作
*********************************************************************/
#include <stdlib.h>
#include "bitree.h"

/**********************************************************************
函 数 名：CreateBiTree
函数功能：在单链表中插入元素x
参数说明：
	入参：
		input：建立二叉树的输入序列
		*pos：指示当前输入序列的位置
	出参：
		T：建立完成的二叉树
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void CreateBiTree(BiTree *T,ElemType input[],int *pos)
{
	if(input[*pos] == '#'){
		*T = NULL;
		return;
	}
	*T = (BiTree)malloc(sizeof(BiNode));
	(*T)->data = input[*pos];
	(*pos)++;
	CreateBiTree(&(*T)->lchild,input,pos);
	(*pos)++;
	CreateBiTree(&(*T)->rchild,input,pos);
}
/**********************************************************************
函 数 名：BiTreePreOrder
函数功能：二叉树的先序遍历
参数说明：
	入参：
		T：建立完成的二叉树
		visit：指示当前输入序列的位置
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreePreOrder(BiTree T,void(*visit)(BiNode *p))
{
	if(T == NULL){
		return;
	}
	visit(T);
	BiTreePreOrder(T->lchild,visit);
	BiTreePreOrder(T->rchild,visit);
}
/**********************************************************************
函 数 名：BiTreePreOrder
函数功能：二叉树的先序遍历
参数说明：
	入参：
		T：建立完成的二叉树
		visit：指示当前输入序列的位置
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreePreOrderTravse(BiTree T,void(*visit)(BiNode *p))
{
	BiNode *stack[MAX_BINODE_NUM];
	BiNode *p = NULL;
	int top = 0;
	if(T == NULL){
		return;
	}
}




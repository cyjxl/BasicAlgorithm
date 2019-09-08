/********************************************************************
CopyRight：拿走不谢
Author：lvxulin
CreateTime：2019.8.20
Desc：此文件主要是实现二叉树相关的操作
*********************************************************************/
#include "bitree.h"
#include <stdlib.h>
#include <stdio.h>

void Visit(BiNode *p)
{
    printf("%c ",p->data);
}
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
		bt：建立完成的二叉树
		visit：执行遍历的操作
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreePreOrder(BiTree bt,void(*visit)(BiNode *p))
{
	if (bt == NULL) {
		return;
	}
	visit(bt);
	BiTreePreOrder(bt->lchild,visit);
	BiTreePreOrder(bt->rchild,visit);
}
/**********************************************************************
函 数 名：BiTreeInOrder
函数功能：二叉树的中序遍历
参数说明：
	入参：
		bt：建立完成的二叉树
		visit：执行遍历的操作
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreeInOrder(BiTree bt,void(*visit)(BiNode *p))
{
	if (bt == NULL) {
		return;
	}
	BiTreeInOrder(bt->lchild,visit);
    visit(bt);
	BiTreeInOrder(bt->rchild,visit);
}
/**********************************************************************
函 数 名：BiTreePostOrder
函数功能：二叉树的后序遍历
参数说明：
	入参：
		bt：建立完成的二叉树
		visit：执行遍历的操作
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreePostOrder(BiTree bt,void(*visit)(BiNode *p))
{
	if (bt == NULL) {
		return;
	}
	BiTreePostOrder(bt->lchild,visit);
	BiTreePostOrder(bt->rchild,visit);
    visit(bt);
}

/**********************************************************************
函 数 名：BiTreePreOrderTravse
函数功能：二叉树的先序遍历,非递归实现
参数说明：
	入参：
		bt：建立完成的二叉树
		visit：执行遍历的操作
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreePreOrderTravse(BiTree bt,void(*visit)(BiNode *p))
{
	BiNode *stack[MAX_BINODE_NUM];
	BiNode *p = NULL;
	int top = 0;
	if (bt == NULL) {
		return;
	}
    stack[top++] = bt;
    while(top != 0){
        p = stack[--top];
        visit(p);
        if(p->rchild != NULL){
            stack[++top] = p->rchild;
        }
        if(p->lchild != NULL){

            stack[++top] = p->lchild;
        }
    }
}
/**********************************************************************
函 数 名：BiTreeInOrderTravse
函数功能：二叉树的中序遍历,非递归实现
参数说明：
	入参：
		bt：建立完成的二叉树
		visit：执行遍历的操作
作     者：lvxulin
创建时间：2019.8.30
**********************************************************************/
void BiTreeInOrderTravse(BiTree bt,void(*visit)(BiNode *p))
{
	BiNode *stack[MAX_BINODE_NUM];
	BiNode *p = NULL;
	int top = 0;
	if (bt == NULL) {
		return;
	}
    p = bt;
    while(top != 0 || p != NULL){
        if (p != NULL) {
            stack[top++] = p;
            p = p->lchild;
        } else {
            p = stack[--top];
            visit(p);
            p = p->rchild;
        }
    }
    return;
}




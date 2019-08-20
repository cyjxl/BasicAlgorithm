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


void CreateBiTree(BiTree *T,ElemType input[],int *pos)
{
	if(input[*pos] == '#'){
		*T = NULL;
	}
	*T = (BiTree)malloc(sizeof(BiNode));
	(*T)->data = input[*pos];
	*pos++;
	CreateBiTree(&(*T)->lchild,input,*pos);
	*pos++;
	CreateBiTree(&(*T)->lchild,input,*pos);
}


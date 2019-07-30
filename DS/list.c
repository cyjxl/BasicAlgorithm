/**********************************************************************
CopyRight：转载请注明出处
Author：lvxulin
CreateTime：2019.7.29
Desc：此文件为数据结构的线性表的实现文件
**********************************************************************/

/**********************数据类型定义*******************/
typedef uint32 ElemType;

/*******单链表的数据结构*********/
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;








/**********************************************************************
函 数 名：CreatLinkList
函数功能：参数创建单链表
参数说明：
	入参：
		seq：输入的数据元素序列
		len：输入的数据元素序列的长度
		type：链表建立采用方式指示 type=0:头插法 type=1:尾插法
	出参：
		LinkList类型的链表
作     者：lvxulin
**********************************************************************/
LinkList CreatLinkList(ElemType* seq,uint32 len,uint32 type)
{
	JUDGE_RETURN(type > 2 ||seq == NULL,FAILURE);
	return (type==0) ? CreatLinkListByFront(seq,len):CreatLinkListByRear(seq,len);
}

LinkList CreatLinkListByFront(ElemType* seq,uint32 len)
{
	uint32 i;
	LNode *elem = NULL;
	LinkList L = NULL;
	L = (LinkList)malloc(sizeof(LNode));
	L->data = len;
	L->next = NULL;
	
	for(i=0;i<len;i++){
		elem = (LNode *)malloc(sizeof(LNode));
		elem->data = seq[i];
		elem->next = L->next;
		L->next = elem;
	}
	return L;
}

LinkList CreatLinkListByRear(ElemType* seq,uint32 len)
{
	uint32 i;
	LNode *elem = NULL;
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LNode *r = L;
	L->data = len;
		
	for(i=0;i<len;i++){
		elem = (LNode *)malloc(sizeof(LNode));
		elem->data = seq[i];
		elem->next = r->next;
		r = elem;
	}
	r->next = NULL;
	return L;
}
/**********************************************************************
函 数 名：InsertNode
函数功能：在单链表中插入元素x
参数说明：
	入参：
		L：需插入元素的单链表
		p：元素插入的节点
		type：插入方式指示 type=0:在p节点之前插入 type=1:在节点之后插入
	出参：
		-1：失败 0：成功
作     者：lvxulin
**********************************************************************/
uint32 InsertNode(LinkList L,LNode *p,ElemType x,uint32 type)
{
	JUDGE_RETURN(type > 2 || L == NULL , FAILURE);
	return (type==0) ? InsertBeforeNode(L,p,x):InsertAfterNode(p,x);
}
uint32 InsertBeforeNode(LinkList L,LNode *p,ElemType x)
{
	LNode *q = L;
	LNode *elem = (LNode *)malloc(sizeof(LNode));
	elem->data = x;
	for(;q!= NULL && q->next != p;q=q->next);
	JUDGE_RETURN(q == NULL, FAILURE);
	elem->next = q->next;
	q->next = elem;
	return SUCCESS;
}
uint32 InsertAfterNode(LNode *p,ElemType x)
{
	LNode *elem = (LNode *)malloc(sizeof(LNode));
	elem->data = x;
	elem->next = p->next;
	p->next = elem;
	return SUCCESS;
}

/**********************************************************************
函 数 名：InsertNode
函数功能：在单链表中插入元素x
参数说明：
	入参：
		L：需插入元素的单链表
		p：元素插入的节点
		type：插入方式指示 type=0:删除p节点 type=1:删除所有元素数据为x的节点
	出参：
		-1：失败 0：成功
作     者：lvxulin
**********************************************************************/
uint32 DeleteLinkNode(LinkList L,LNode *p,ElemType x,uint32 type)
{
	JUDGE_RETURN(type > 2 || L == NULL , FAILURE);
	return (type==0) ? DeleteNode(L,p):DeleteValue(L,x);
}
uint32 DeleteNode(LinkList L,LNode *p)
{
	LNode *q = L;
	for(;q!= NULL && q->next != p;q=q->next);
	JUDGE_RETURN(q == NULL, FAILURE);
	q->next = p->next;
	free(p);
}
uint32 DeleteValue(LinkList L,ElemType x)
{
	LNode *q = L->next;
	LNode *pre = L;
	for(;q!= NULL;pre = q,q=q->next){
		if(q->data == x){
			pre->next=q->next;
			free(q);
			q = pre;
		}
	}
	return SUCCESS;
}

/**********************************************************************
函 数 名：SortList
函数功能：排序链表
参数说明：
	入参：
		L：需排序的单链表
		type：链表排序方式指示 type=0:交换数据域，指针域不做修改 type=1:数据域不动，指针域修改
	出参：
		-1：失败 0：成功
作     者：lvxulin
**********************************************************************/
uint32 SortList(LinkList L,uint32 type)
{
	JUDGE_RETURN(type > 2 || L == NULL , FAILURE);
	return (type==0) ? SortListByData(L):SortListByPtr(L);
}

uint32 SortListByData(LinkList L)
{
	LNode *p = L->next;
	LNode *q = L->next;
	ElemType tmp;
	uint32 flag;
	JUDGE_RETURN(p == NULL || p->next == NULL, SUCCESS);
	for(;p!=NULL;p=p->next){
		flag = 0;
		for(q=p->next;p!=NULL;q=q->next){
			if(p->data > q->data){
				tmp = p->data;
				p->data = q->data;
				q->data = tmp;
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
	}
	return SUCCESS;
}
uint32 SortListByPtr(LinkList L)
{
	LNode *r = L->next;
	LNode *q = L->next;
	LNode *p = NULL;
	LNode *pre = NULL;
	LNode *tmp = NULL;
	
	JUDGE_RETURN(r == NULL || r->next == NULL, SUCCESS);
	
	q=q->next;
	r->next = NULL;
	// 插入排序
	for(;q!=NULL;q=q->next){
		if(q->data<r->data){
			for(p=L->next,pre=L;p!=r;pre=p,p=p->next){
				if(p->data > q->data){
					tmp = q->next;
					q->next = pre->next;
					pre->next = q;
					q = tmp;
				}
			}
		}
	}
	return SUCCESS;
}















#define MAX_INPUT_CHAR_NUM	(4096)

typedef struct Node{
	char *data;
	int len;
	struct Node *next;
}Node;

typedef struct Table{
	char *data;
	int len;
	struct Node *first;
	struct Table *next;
}Table;

char* SplitStr(char *input)
{
	char *buf = input;
	while(*buf != '\0'){
		if(*buf == ' '){
			*buf = '\0';
			return buf;
		}
	}
	return NULL;
}
int StrCmp(char *c1,char* c2)
{
	if(c1 == NULL || c2 == NULL){
		return -1;
	}
	do{
		if(*c1 =='\0' && *c2 == '\0'){
			return 0;
		}
	}while(*c1++ == *c2++);
	return (*c1-*c2);
}
int SearchStr(Table* pMapTbl,char *seq)
{
	Table* p = pMapTbl->next;
	while(p != NULL){
		if(StrCmp(p->data,seq) == 0){
			return 1;
		}
	}
	return 0;
}

void InputProc(char *input,Table* pMapTbl)
{
	char *buf = NULL;
	char* token = NULL;
	Table* p = NULL;
	char seq[MAX_INPUT_CHAR_NUM];
	int n = 0;
	int isSave = 0;
	
	while((buf = gets(seq)) != NULL)
	{
		// 存储需查找的字串和编码结果
		if(n == 0){
			memcpy(input,seq,sizeof(char)*(strlen(seq)+1));
			input[strlen(seq)] = '\0';
		}else{
			token = SplitStr(seq);
			isSave = SearchStr(pMapTbl,seq);
			if(isSave == 0){
				p = (Table *)malloc(sizeof(Table));
				p->data = (char *)malloc(sizeof(char)*(strlen(seq)+1));
				p->first
				strcpy(p->data,seq);
				p->next = pMapTbl->next;
				pMapTbl->next = p;
			}
		}
		n++;
	}
	
}
void InitTbl(Table* pSrcTbl,Table* pMapTbl)
{
	pSrcTbl->next = NULL;
	pMapTbl->next = NULL;
	pSrcTbl->len = 0;
	pMapTbl->len = 0;
}

int main()
{
	/* 存储第一行的源串和编码结果*/
	char input[MAX_INPUT_CHAR_NUM];
	/* 源串解析的字串表*/
	Table* pSrcTbl = (Table*)malloc(sizeof(Table));
	/* 子串的编码表*/
	Table* pMapTbl = (Table*)malloc(sizeof(Table));
	/* 初始化2张表*/
	InitTbl(pSrcTbl,pMapTbl);
	
	InputProc(input,pMapTbl);


}



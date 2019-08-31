/********************************************************************
CopyRight：拿走不谢
Author：lvxulin
CreateTime：2019.8.3
Desc：此文件主要是实现用c语言字符串相关的操作
*********************************************************************/






/*************************************************************
函数名：SplitCharSeq
函数功能：将字符序列str按exp表达式进行分割
参数说明：
	入参：
		str->待提取的字符序列，以'\0'结尾
		exp->分割字符序列的表达式
		len->返回的子字符序列的个数
	出参：以子字符序列组成的数组，每个子字符序列以'\0'结束
作     者：lvxulin
创建时间：2019.8.3
*************************************************************/
char** SplitString(char *str,char* exp,uint32* len)
{
	char **out = NULL;
	char *buf = NULL;

	uint32 subLen = 0;
	
	if(str == NULL || exp == NULL){
		return  NULL;
	}
	buf = FindSubStr(str, exp);
	while(buf !=){
		s = FindSubStr(str,exp);
		subLen = MAX();
	}
}
char* FindSubStr(char *str,char* exp)
{
	char *p = str;
	char *s = str;
	char *e = exp;
	
	if( *exp == ''||
		*exp == '\0'){
		return NULL;
	}
	while(*p != '\0'){
		s = p;
		e = exp
		do{
			if(*e == '\0'){
				return p;
			}
		}while(*s++ == *e++);			
		p++;
	}
	return NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "bitree.h"

using testing::Test;

class TestBiTree :public Test
{
	void SetUp()
	{

	}
	void TearDown()
	{

	}
};
TEST(TestBiTreeCreate, BiTreeTest)
{
	BiTree bt = NULL;
	FILE *stream = NULL;
	errno_t err;
	ElemType input[MAX_BINODE_NUM+1];

	int pos = 0;
	err = freopen_s(&stream,"..\\data\\case0\\input.dat","r",stdin);

	if (err != 0) {
		printf("TestBiTreeCreate open file failed.\n");
		return;
	}
	if (fgets(input, MAX_BINODE_NUM, stream) == NULL) {
		printf("TestBiTreeCreate read input failed.\n");
		return;
	}
	CreateBiTree(&bt,input,&pos);
	printf("PreOrder:\n");
	BiTreePreOrder(bt,Visit);
	printf("\nInOrder:\n");
	BiTreeInOrder(bt, Visit);
	printf("\nPostOrder:\n");
	BiTreePostOrder(bt, Visit);
	printf("\n");
	BiTreeInOrderTravse(bt, Visit);
	fclose(stream);
	return;
}

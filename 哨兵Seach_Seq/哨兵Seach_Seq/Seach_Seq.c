#include "Search.h"
#define NOT_FOUND_404 0
typedef int KeyType;
typedef struct
{
	KeyType key;
	//也可以添加其他域
}ElemType;
typedef struct
{
	ElemType* R;
	int length;
}SSTable;
SSTable ST;
int Search_Bin(SSTable ST, int key,int* low,int* high)
{
	int mid = (*high + *low) / 2;
	if (key == ST.R[mid].key)
		return mid;
	else 
	{
		if (high > low)
		{
			if (key < ST.R[mid].key)
			{
				high = mid - 1;
				Search_Bin(ST, &key, &low, &high);
			}
			if (key > ST.R[mid].key)
			{
				low = mid + 1;
				Search_Bin(ST, &key, &low, &high);
			}
		}
		else
		{
			return NOT_FOUND_404;
		}
	}
}
void main()
{
	int key = 0;
	int n = 0;
	int low = 1;//表的起始位置
	int high = ST.length;
	int mid = 0;
	printf("You want what numbers:>");
	scanf_s("%d", &n);
	ST.R = (SSTable*)malloc(sizeof(SSTable));//给哨兵下标开辟空间
	for (int i = 1; i <= n; i++)
	{
		ST.R = (SSTable*)malloc(sizeof(SSTable));
		scanf_s("%d", &ST.R[i].key);
		ST.length++;
	}
	printf("please you input want to search of number:>");
	scanf_s("%d", &key);
	mid=Seach_Seq(ST, &key);
	printf("Your want numbers were found,is mid:>");
}
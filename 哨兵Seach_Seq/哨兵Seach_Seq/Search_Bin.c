#include "Search.h"
typedef int KeyType;
typedef struct
{
	KeyType key;
	//Ҳ�������������
}ElemType;
typedef struct
{
	ElemType* R;
	int length;
}SSTable;
SSTable ST;
void main()
{
	int key = 0;
	int n = 0;
	printf("You want what numbers:>");
	scanf_s("%d", &n);
	ST.R = (SSTable*)malloc(sizeof(SSTable));//���ڱ��±꿪�ٿռ�
	for (int i = 1; i <= n; i++)
	{
		ST.R = (SSTable*)malloc(sizeof(SSTable));
		scanf_s("%d", &ST.R[i].key);
		ST.length++;
	}
	printf("please you input want to search of number:>");
	scanf_s("%d", &key);
	Seach_Bin(ST, &key);
}
//最长递增子序列
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void sort(int a[],int n);
int max(int s,int t);
int e = 0, f = 0;

struct data
{
	int value = 0;
	int p = 0;
	int q = 0;
};

data table[80][80] = { 0 };

void main()
{
	
	int m = 0;
	printf("请输入测试例个数：");
	scanf("%d",&m);
	getchar();
	for (int r = 0; r < m; r++)
	{
		printf("第%d个测试例如下：\n",r+1);
		int a[80] = { 0 }, b[80] = { 0 }, arr[80] = { 0 };
		int L = 0, n = 0;

		printf("请输入数列长度：");		//1 3 9 5 2 6
		scanf("%d", &n);
		printf("请输入一个数列：");
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < n; i++)
			b[i] = a[i];			//复制数组a

		//冒泡排序
		int temp = 0;
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (b[j] > b[j + 1])
				{
					temp = b[j];
					b[j] = b[j + 1];
					b[j + 1] = temp;
				}
			}
		}							//得到b是正序

		//对table表进行赋值
		for (int s = 0; s < n; s++)				//第一行
		{
			for (int t = 0; t < n; t++)
			{
				if (b[s] != a[t])
					table[s][t].value = 0;
				else
					table[s][t].value = max(s, t) + 1;
			}
		}

		//至此，赋值成功
/*		printf("表格如下：\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("table[%d][%d]=%d\t", i, j, table[i][j]);
			printf("\n");
		}*/

		//打印长度
		L = max(n + 1, n + 1);
		printf("最长递增子序列长度为L=%d\n", L);

		//打印每个p,q,至此表格已经打好
/*		printf("打印痕迹：\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (table[i][j].value != 0)
					printf("table[%d][%d]=%d,上一个是table[%d,%d]\n", i, j, table[i][j].value, table[i][j].p, table[i][j].q);
		}
		printf("\n");*/

		int u = 0, v = 0;
//		printf("最后一个数的下标：(%d,%d)\n", e, f);

		for (int i = 1; i <= L; i++)
		{
			arr[L - i] = b[e];
			u = table[e][f].p;
			v = table[e][f].q;
			e = u;
			f = v;
			//		printf("(%d,%d)\n",e,f);
		}

		printf("最长递增子序列：");
		for (int i = 0; i < L; i++)
			printf("%d  ", arr[i]);

		printf("\n**************************\n");
	}

}


int max(int s, int t)
{	//传入s,t的值
	int m = 0;
	for (int i=0;i<=s-1;i++)
	{
		for (int j = 0; j <= t - 1; j++)
			if (m < table[i][j].value)
			{
				m = table[i][j].value;

				//可以记录最后一次更新的i,j
				table[s][t].p = i;
				table[s][t].q = j;

				e = i;
				f = j;
			}
	}
	return m;
}

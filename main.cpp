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
	printf("116132019188  ��˼��  ����\n");
	printf("**************************\n");
	int m = 0;
	printf("�����������������");
	scanf("%d",&m);
	getchar();
	for (int r = 0; r < m; r++)
	{
		printf("��%d�����������£�\n",r+1);
		int a[80] = { 0 }, b[80] = { 0 }, arr[80] = { 0 };
		int L = 0, n = 0;

		printf("���������г��ȣ�");		//1 3 9 5 2 6
		scanf("%d", &n);
		printf("������һ�����У�");
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < n; i++)
			b[i] = a[i];			//��������a

		//ð������
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
		}							//�õ�b������

		//��table����и�ֵ
		for (int s = 0; s < n; s++)				//��һ��
		{
			for (int t = 0; t < n; t++)
			{
				if (b[s] != a[t])
					table[s][t].value = 0;
				else
					table[s][t].value = max(s, t) + 1;
			}
		}

		//���ˣ���ֵ�ɹ�
/*		printf("������£�\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("table[%d][%d]=%d\t", i, j, table[i][j]);
			printf("\n");
		}*/

		//��ӡ����
		L = max(n + 1, n + 1);
		printf("����������г���ΪL=%d\n", L);

		//��ӡÿ��p,q,���˱���Ѿ����
/*		printf("��ӡ�ۼ���\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (table[i][j].value != 0)
					printf("table[%d][%d]=%d,��һ����table[%d,%d]\n", i, j, table[i][j].value, table[i][j].p, table[i][j].q);
		}
		printf("\n");*/

		int u = 0, v = 0;
//		printf("���һ�������±꣺(%d,%d)\n", e, f);

		for (int i = 1; i <= L; i++)
		{
			arr[L - i] = b[e];
			u = table[e][f].p;
			v = table[e][f].q;
			e = u;
			f = v;
			//		printf("(%d,%d)\n",e,f);
		}

		printf("����������У�");
		for (int i = 0; i < L; i++)
			printf("%d  ", arr[i]);

		printf("\n**************************\n");
	}

}


int max(int s, int t)
{	//����s,t��ֵ
	int m = 0;
	for (int i=0;i<=s-1;i++)
	{
		for (int j = 0; j <= t - 1; j++)
			if (m < table[i][j].value)
			{
				m = table[i][j].value;

				//���Լ�¼���һ�θ��µ�i,j
				table[s][t].p = i;
				table[s][t].q = j;

				e = i;
				f = j;
			}
	}
	return m;
}
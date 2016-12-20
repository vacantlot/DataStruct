#include <iostream>
using namespace std;

/*奇数幻方算法*/
//int main() {
//	cout << "Please input n:";
//	int n;
//	cin >> n;
//	int ** a;
//	a = new int *[n];
//	for (int i = 0; i < n; i++)
//		a[i] = new int[n];		//用n的大小初始化一个二维数组
//	if (n % 2 != 0)
//	{
//		int i = 0, j = n / 2;
//		a[i][j] = 1;      //将1存入第一排的中间
//		for (int k = 2; k <= n*n; k++)
//		{
//			int iTemp = i, jTemp = j; //暂存i和j的值
//			i = (i - 1 + n) % n;    //即i = i - 1 ；if（i < 0） i = n - 1;
//			j = (j - 1 + n) % n;    //即j = j - 1 ；if（j < 0） j = n - 1;
//			if (a[i][j] > 0)     //如果第i行j列已填数
//			{
//				i = (iTemp + 1) % n;  //即i = iTemp + 1 ; if(i == n) i = 0;
//				j = jTemp;       //原位置的同一列
//			}
//			a[i][j] = k;
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)  //输入排好的幻方
//			{
//				cout << a[i][j] << "\t";
//			}
//			cout << "\n";
//		}
//	}
//	else
//	{
//		int i, j;
//		magic_o(a , n/2); exchange(a, n);
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//				printf("%2d", a[i][j]);
//				printf("\n");
//		}
//		return 0;
//
//	}
//}

/*偶数幻方算法*/

#include<stdio.h> 
#include<stdlib.h>
#define N 6
#define SWAP(x, y) { int t; t = x; x = y; y = t; }
void magic_o(int[][N], int);
void exchange(int[][N], int);
int main(void)
	{
	cout << "Please input n:";
	int n;
	cin >> n;
	int square[N][N] = { 0 };
	int i, j;
	magic_o(square, N / 2);
	exchange(square, N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d\t", square[i][j]);
		printf("\n");
	}
	return 0;
	}
void magic_o(int square[][N], int n) {
	int count, row, column;
	row = 0; column = n / 2;
	for (count = 1; count <= n*n; count++)
	{
		square[row][column] = count; // 填A 
		square[row + n][column + n] = count + n*n; // 填B 
		square[row][column + n] = count + 2 * n*n; // 填C 
		square[row + n][column] = count + 3 * n*n; // 填D 
		if (count%n == 0) row++;
		else
		{
			row = (row == 0) ? n - 1 : row - 1;
			column = (column == n - 1) ? 0 : column + 1;
		}
	}
}
void exchange(int x[][N], int n)
{
	int i, j;
	int m = n / 4;
	int m1 = m - 1;
	for (i = 0; i < n / 2; i++)
	{
		if (i != m)
		{
			for (j = 0; j < m; j++) // 处理规则 1 
				SWAP(x[i][j], x[n / 2 + i][j]);
			for (j = 0; j < m1; j++) // 处理规则 2 
				SWAP(x[i][n - 1 - j], x[n / 2 + i][n - 1 - j]);
		}
		else
		{ // 处理规则 3 
			for (j = 1; j <= m; j++)
				SWAP(x[m][j], x[n / 2 + m][j]);
			for (j = 0; j < m1; j++)
				SWAP(x[m][n - 1 - j], x[n / 2 + m][n - 1 - j]);
		}
	}
}
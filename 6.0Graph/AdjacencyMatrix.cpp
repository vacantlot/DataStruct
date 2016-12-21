#include <iostream>
using namespace std;
#include "MGraph.h"
int visited[MaxSize] = { 0 };
int main()
{
	char ch[] = { 'A','B','C','D','E' };
	int i;
	ALGraph<char> ALG(ch, 5, 6);
	for (int i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}
	cout << "������ȱ������Ϊ��";
	ALG.DFSTraverse(0);
	cout << endl;
	for (int i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}
	cout << "������ȱ��������ǣ�";
	ALG.BFSTraverse(0);
	cout << endl;
	return 0;
}

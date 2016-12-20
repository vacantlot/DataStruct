#include <iostream>
#include "..\4.1BinaryTree\BinaryTree.h"
using namespace std;
int Count = 0;
void CountLeaf1(BTNode<char> *bt);
void CountLeaf(BTNode<char> *bt, int *Count);
int Leave(BTNode<char> *BT);
int main() 
{
	BinaryTree<char> *bintree = new BinaryTree<char>;
	//CountLeaf1(bintree->GetRoot());

	cout << "Ҷ������:" << Leave(bintree->GetRoot());
}

void CountLeaf1(BTNode<char> *bt ) 
{
	if (bt != nullptr)
	{
		if (bt->lchild == nullptr && bt->rchild == nullptr)
		{
			Count++;
		}
		CountLeaf(bt->lchild, &Count);
		CountLeaf(bt->lchild, &Count);
	}
}

void CountLeaf(BTNode<char> *bt , int *Count) {
	if (bt == nullptr)  return;
	else {
		if (bt->lchild == nullptr && bt->rchild == nullptr)
		{
			Count++;
		}
		CountLeaf(bt->lchild , Count);
		CountLeaf(bt->rchild , Count);
	}
}

//************************************
//���ض������е�Ҷ�ӽڵ���
// Method:    Leave
// FullName:  Leave
// Access:    public 
// Parameter: BTNode<char> * BT
//************************************
int Leave(BTNode<char> *BT) //��������е�Ҷ�ӽڵ���
{
	if (BT == nullptr)
		return 0;
	else 
	{
		if (BT->lchild == nullptr && BT->rchild == nullptr)
			return 1;
		else
			return(Leave(BT->lchild) + Leave(BT->rchild));//���������Ҷ�ӽڵ��+1��return 1��
	}
}
#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<char> *btree = new BinaryTree<char>;
	/*cout << "前序排列：";
	btree->PreOrder(btree->GetRoot());
	cout << endl;
	cout << "中序排列：";
	btree->InOrder(btree->GetRoot());
	cout << endl;
	cout << "后序排列：";
	btree->PostOrder(btree->GetRoot());
	cout << endl;
	cout << "层序排列：";
	btree->LeverOrder(btree->GetRoot());
	btree->~BinaryTree();*/
	//cout << btree->TreeHeight(btree->GetRoot());
	btree->FormatPrintTree(btree->GetRoot());

}
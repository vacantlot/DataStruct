#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<char> *btree = new BinaryTree<char>;
	/*cout << "ǰ�����У�";
	btree->PreOrder(btree->GetRoot());
	cout << endl;
	cout << "�������У�";
	btree->InOrder(btree->GetRoot());
	cout << endl;
	cout << "�������У�";
	btree->PostOrder(btree->GetRoot());
	cout << endl;
	cout << "�������У�";
	btree->LeverOrder(btree->GetRoot());
	btree->~BinaryTree();*/
	//cout << btree->TreeHeight(btree->GetRoot());
	btree->FormatPrintTree(btree->GetRoot());

}
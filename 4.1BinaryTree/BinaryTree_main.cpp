#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<char> *btree = new BinaryTree<char>;
	cout << "ǰ�����У�";
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
	btree->Print(btree->GetRoot() , btree->TreeHeight(btree->GetRoot()));
	//btree->~BinaryTree();
	//cout << btree->TreeHeight(btree->GetRoot());
	//btree->FormatPrintTree(btree->GetRoot());
	//cout << "�������Ϊ��" << btree->TreeHeight(btree->GetRoot())<<endl;
	//cout << "ɾ�����B֮ǰ:" << endl;

	//btree->Print(btree->GetRoot(), 0);

	//cout << "���ɾ�����B��:"<<endl;
	///*btree->Release(btree->GetRoot()->lchild);
	//btree->Print(btree->GetRoot(), 0);*/
	//
	////btree->Release(btree->search(btree->GetRoot(), 'A'));
	//btree->Release(btree->GetRoot());
	//btree->Print(btree->GetRoot() , 1);

}
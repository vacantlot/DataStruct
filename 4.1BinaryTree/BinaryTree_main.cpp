#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<char> *btree = new BinaryTree<char>;
	cout << "前序排列：";
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
	btree->Print(btree->GetRoot() , btree->TreeHeight(btree->GetRoot()));
	//btree->~BinaryTree();
	//cout << btree->TreeHeight(btree->GetRoot());
	//btree->FormatPrintTree(btree->GetRoot());
	//cout << "树的深度为：" << btree->TreeHeight(btree->GetRoot())<<endl;
	//cout << "删除结点B之前:" << endl;

	//btree->Print(btree->GetRoot(), 0);

	//cout << "输出删除结点B后:"<<endl;
	///*btree->Release(btree->GetRoot()->lchild);
	//btree->Print(btree->GetRoot(), 0);*/
	//
	////btree->Release(btree->search(btree->GetRoot(), 'A'));
	//btree->Release(btree->GetRoot());
	//btree->Print(btree->GetRoot() , 1);

}
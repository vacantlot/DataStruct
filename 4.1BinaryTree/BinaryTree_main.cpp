#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<char> *btree = new BinaryTree<char>;	
	btree->PreOrder(btree->GetRoot());
	btree->LeverOrder(btree->GetRoot());

}
#pragma once
#include "../3.3CirQueue/CirQueue.h"
#include <math.h>
#include <map>
#include <algorithm>
template<typename T>
struct BTNode
{
	T data;
	BTNode<T> *lchild, *rchild;
};

template<typename T>
class BinaryTree
{
public:
	BinaryTree();             //构造函数，初始化一棵二叉树，其前序序列由键盘输入
	~BinaryTree(void);        //析构函数，释放二叉链表中各结点的存储空间
	BTNode<T>* GetRoot();      //获得指向根结点的指针
	void PreOrder(BTNode<T> *root);     //前序遍历二叉树
	void InOrder(BTNode<T> *root);      //中序遍历二叉树
	void PostOrder(BTNode<T> *root);    //后序遍历二叉树
	void LeverOrder(BTNode<T> *root);   //层序遍历二叉树
	int TreeHeight(BTNode<T> *root);    //获取树的深度
	void FormatPrintTree(BTNode<T> *root);  //按照树的形状输出
	void Print(BTNode<T> *start, int n);
	BTNode<T>* Find(const T item) const;
	void Release(BTNode<T> *root);   //析构函数调用 
	BTNode<T>* search(BTNode<T> *B , T search_data);
	int Leave(BTNode<T>* BT);//返回二叉树中的叶子节点数
private:
	BTNode<T> *root;         //指向根结点的头指针
	BTNode<T> *Create();     //有参构造函数调用
	
};

/*
*前置条件：二叉树不存在
*输    入：无
*功    能：构造一棵二叉树
*输    出：无
*后置条件：产生一棵二叉树
*/
template<typename T>
BinaryTree<T>::BinaryTree()
{
	this->root = Create();
}

/*
*前置条件：二叉树已存在
*输    入：无
*功    能：释放二叉链表中各结点的存储空间
*输    出：无
*后置条件：二叉树不存在
*/

template<typename T>
BinaryTree<T>::~BinaryTree(void)
{
	Release(root);
}
/*
*前置条件：二叉树已存在
*输    入：无
*功    能：获取指向二叉树根结点的指针
*输    出：指向二叉树根结点的指针
*后置条件：二叉树不变
*/

template<typename T>
BTNode<T>* BinaryTree<T>::GetRoot()
{
	return root;
}
/*
*前置条件：二叉树已存在
*输    入：无
*功    能：前序遍历二叉树
*输    出：二叉树中结点的一个线性排列
*后置条件：二叉树不变
*/
template<typename T>
void BinaryTree<T>::PreOrder(BTNode<T> *root)
{
	if (root == nullptr)  return;
	else {
		cout << root->data << " ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

/*
*前置条件：二叉树已存在
*输    入：无
*功    能：中序遍历二叉树
*输    出：二叉树中结点的一个线性排列
*后置条件：二叉树不变
*/
template <typename T>
void BinaryTree<T>::InOrder(BTNode<T> *root)
{
	if (root == nullptr)  return;      //递归调用的结束条件	          
	else {
		InOrder(root->lchild);    //中序递归遍历root的左子树
		cout << root->data << " ";    //访问根结点的数据域
		InOrder(root->rchild);    //中序递归遍历root的右子树
	}
}
/*
*前置条件：二叉树已存在
*输    入：无
*功    能：后序遍历二叉树
*输    出：二叉树中结点的一个线性排列
*后置条件：二叉树不变
*/
template <typename T>
void BinaryTree<T>::PostOrder(BTNode<T> *root)
{
	if (root == nullptr)   return;       //递归调用的结束条件
	else {
		PostOrder(root->lchild);    //后序递归遍历root的左子树
		PostOrder(root->rchild);    //后序递归遍历root的右子树
		cout << root->data << " ";      //访问根结点的数据域
	}
}

/*
*前置条件：二叉树已存在
*输    入：无
*功    能：层序遍历二叉树
*输    出：二叉树中结点的一个线性排列
*后置条件：二叉树不变
*/
template <typename T>
void BinaryTree<T>::LeverOrder(BTNode<T> *root)
{
	/*
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //采用顺序队列，并假定不会发生上溢

	BTNode<T>* Q[MaxSize];
	BTNode<T>* q;

	if (root == nullptr) return;
	else {
	Q[rear++] = root;
	while (front != rear)
	{
	q = Q[front++];
	cout << q->data << " ";
	if (q->lchild != nullptr)    Q[rear++] = q->lchild;
	if (q->rchild != nullptr)    Q[rear++] = q->rchild;
	}
	}
	*/
	CirQueue<BTNode<T>*> q;
	if (root == nullptr)
	{
		return;
	}
	else
	{
		q.EnQueue(root);
		while (q.IsEmpty())
		{
			BTNode<T> *node = q.DeQueue();
			cout << node->data<<" ";
			if (node->lchild != nullptr)
			{
				q.EnQueue(node->lchild);
			}
			if (node->rchild != nullptr)
			{
				q.EnQueue(node->rchild);
			}
		}
	}
}

template<typename T>
inline int BinaryTree<T>::TreeHeight(BTNode<T>* root)
{
	int lHeight, rHeight;
	if (root == nullptr)
	{
		return 0;
	}
	else 	
	{
		lHeight =  TreeHeight(root->lchild);
		rHeight =  TreeHeight(root->rchild);
		return 1 + (lHeight > rHeight ? lHeight : rHeight);  //为什么可以有值?   lHeight   rHeight  递归:系统就会自动用栈帮你保存(栈的个数)
	}
}

/*
*前置条件：空二叉树
*输    入：数据ch;
*功    能：初始化一棵二叉树,构造函数调用
*输    出：无
*后置条件：产生一棵二叉树
*/
template <typename T>
BTNode<T>* BinaryTree<T>::Create()
{
	BTNode<T>* root;
	T ch;
	cout << "请输入创建一棵二叉树的结点数据" << endl;
	cin >> ch;
	if (ch == '#')
	{
		root = nullptr;
	}
	else
	{
		root = new BTNode<T>;       //生成一个结点
		root->data = ch;			//数据域为ch
		root->lchild = Create();    //递归建立左子树
		root->rchild = Create();    //递归建立右子树
	}
	return root;
}

/*
*前置条件：二叉树已经存在
*输    入：无
*功    能：释放二叉树的存储空间，析构函数调用
*输    出：无
*后置条件：二叉树不存在
*/
template<typename T>
void BinaryTree<T>::Release(BTNode<T>* root)
{
	if (root != nullptr) {
		Release(root->lchild);   //释放左子树
		Release(root->rchild);   //释放右子树
		delete root;
		//root = nullptr;
	}
}

template <typename T>
void BinaryTree<T>::FormatPrintTree(BTNode<T> *root)
{
	int i = 0 ,n = 1;
	CirQueue<BTNode<T>*> q;
	if (root == nullptr)
	{
		return;
	}
	else
	{
		q.EnQueue(root);
		while (q.IsEmpty())
		{
			BTNode<T> *node = q.DeQueue();
			for (int i = 0; i < TreeHeight(node); i++)
			{
				printf("     ");
			}
			cout << node->data << " ";
			i++;
			if (i == pow(2, n) - 1)
			{
				n++;
				printf("\n");
			}			
			if (node->lchild != nullptr)
			{
				q.EnQueue(node->lchild);				
			}
			if (node->rchild != nullptr)
			{
				q.EnQueue(node->rchild);
			}
			
		}
	}
}


template<typename T>
void BinaryTree<T>::Print(BTNode<T> *start, int n) 
{
	if (start == nullptr)
	{
		for (int i = 0; i < n; i++) 
		{
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	Print(start->rchild, n + 1);
	for (int i = 0; i < n; i++) 
	{	
		cout << "     ";      //打印出树深度个数的空白
	}
	if (n >= 0) 
	{
		cout << start->data << "--->" << endl;
	}
	Print(start->lchild, n + 1);
}


template<typename T> 
BTNode<T>* BinaryTree<T>::Find(const T item) const {
	BTNode<T> *pstart = root;
	while (pstart != nullptr ) {
		if (item == pstart->data) {
			return pstart;
		}
		if (item < pstart->data) {
			pstart = pstart->lchild;	//if less than the node then find in the left subtree
		}
		else {
			pstart = pstart->rchild;//if more than the node then find in the right subtree
		}
	}
	return NULL;
}

template<typename T>
BTNode<T>*  BinaryTree<T>::search(BTNode<T> *B , T search_data)
{
	cout << "search data: " << search_data << endl;
	BTNode<T> *backup = nullptr;
	while (B != nullptr && B->data != search_data) {
		 backup = B;
		if (search_data !=  B->data)
			B = B->lchild;
		else
			B = B->rchild;
	}
	return backup;
	//    if(B->data == search_data)
	//        return B;
	//    if(search_data < B->data) {
	//        if(! B->left_child)
	//            return B;
	//        B = search(B->left_child, search_data);
	//    }else {
	//        if(! B->right_child)
	//            return B;
	//        B = search(B->right_child, search_data);
	//    }
}

//************************************
//返回二叉树中的叶子节点数
// Method:    Leave
// FullName:  Leave
// Access:    public 
// Parameter: BTNode<char> * BT
//************************************
template<typename T>
int BinaryTree<T>::Leave(BTNode<T> *BT) //求二叉树中的叶子节点数
{
	if (BT == nullptr)
		return 0;
	else
	{
		if (BT->lchild == nullptr && BT->rchild == nullptr)
			return 1;
		else
			return(Leave(BT->lchild) + Leave(BT->rchild));
	}
}
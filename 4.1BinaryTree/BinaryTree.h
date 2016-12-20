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
	BinaryTree();             //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
	~BinaryTree(void);        //�����������ͷŶ��������и����Ĵ洢�ռ�
	BTNode<T>* GetRoot();      //���ָ�������ָ��
	void PreOrder(BTNode<T> *root);     //ǰ�����������
	void InOrder(BTNode<T> *root);      //�������������
	void PostOrder(BTNode<T> *root);    //�������������
	void LeverOrder(BTNode<T> *root);   //�������������
	int TreeHeight(BTNode<T> *root);    //��ȡ�������
	void FormatPrintTree(BTNode<T> *root);  //����������״���
	void Print(BTNode<T> *start, int n);
	BTNode<T>* Find(const T item) const;
	void Release(BTNode<T> *root);   //������������ 
	BTNode<T>* search(BTNode<T> *B , T search_data);
	int Leave(BTNode<T>* BT);//���ض������е�Ҷ�ӽڵ���
private:
	BTNode<T> *root;         //ָ�������ͷָ��
	BTNode<T> *Create();     //�вι��캯������
	
};

/*
*ǰ��������������������
*��    �룺��
*��    �ܣ�����һ�ö�����
*��    ������
*��������������һ�ö�����
*/
template<typename T>
BinaryTree<T>::BinaryTree()
{
	this->root = Create();
}

/*
*ǰ���������������Ѵ���
*��    �룺��
*��    �ܣ��ͷŶ��������и����Ĵ洢�ռ�
*��    ������
*����������������������
*/

template<typename T>
BinaryTree<T>::~BinaryTree(void)
{
	Release(root);
}
/*
*ǰ���������������Ѵ���
*��    �룺��
*��    �ܣ���ȡָ�������������ָ��
*��    ����ָ�������������ָ��
*��������������������
*/

template<typename T>
BTNode<T>* BinaryTree<T>::GetRoot()
{
	return root;
}
/*
*ǰ���������������Ѵ���
*��    �룺��
*��    �ܣ�ǰ�����������
*��    �����������н���һ����������
*��������������������
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
*ǰ���������������Ѵ���
*��    �룺��
*��    �ܣ��������������
*��    �����������н���һ����������
*��������������������
*/
template <typename T>
void BinaryTree<T>::InOrder(BTNode<T> *root)
{
	if (root == nullptr)  return;      //�ݹ���õĽ�������	          
	else {
		InOrder(root->lchild);    //����ݹ����root��������
		cout << root->data << " ";    //���ʸ�����������
		InOrder(root->rchild);    //����ݹ����root��������
	}
}
/*
*ǰ���������������Ѵ���
*��    �룺��
*��    �ܣ��������������
*��    �����������н���һ����������
*��������������������
*/
template <typename T>
void BinaryTree<T>::PostOrder(BTNode<T> *root)
{
	if (root == nullptr)   return;       //�ݹ���õĽ�������
	else {
		PostOrder(root->lchild);    //����ݹ����root��������
		PostOrder(root->rchild);    //����ݹ����root��������
		cout << root->data << " ";      //���ʸ�����������
	}
}

/*
*ǰ���������������Ѵ���
*��    �룺��
*��    �ܣ��������������
*��    �����������н���һ����������
*��������������������
*/
template <typename T>
void BinaryTree<T>::LeverOrder(BTNode<T> *root)
{
	/*
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //����˳����У����ٶ����ᷢ������

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
		return 1 + (lHeight > rHeight ? lHeight : rHeight);  //Ϊʲô������ֵ?   lHeight   rHeight  �ݹ�:ϵͳ�ͻ��Զ���ջ���㱣��(ջ�ĸ���)
	}
}

/*
*ǰ���������ն�����
*��    �룺����ch;
*��    �ܣ���ʼ��һ�ö�����,���캯������
*��    ������
*��������������һ�ö�����
*/
template <typename T>
BTNode<T>* BinaryTree<T>::Create()
{
	BTNode<T>* root;
	T ch;
	cout << "�����봴��һ�ö������Ľ������" << endl;
	cin >> ch;
	if (ch == '#')
	{
		root = nullptr;
	}
	else
	{
		root = new BTNode<T>;       //����һ�����
		root->data = ch;			//������Ϊch
		root->lchild = Create();    //�ݹ齨��������
		root->rchild = Create();    //�ݹ齨��������
	}
	return root;
}

/*
*ǰ���������������Ѿ�����
*��    �룺��
*��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
*��    ������
*����������������������
*/
template<typename T>
void BinaryTree<T>::Release(BTNode<T>* root)
{
	if (root != nullptr) {
		Release(root->lchild);   //�ͷ�������
		Release(root->rchild);   //�ͷ�������
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
		cout << "     ";      //��ӡ������ȸ����Ŀհ�
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
//���ض������е�Ҷ�ӽڵ���
// Method:    Leave
// FullName:  Leave
// Access:    public 
// Parameter: BTNode<char> * BT
//************************************
template<typename T>
int BinaryTree<T>::Leave(BTNode<T> *BT) //��������е�Ҷ�ӽڵ���
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
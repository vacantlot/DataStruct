#pragma once
#include "../3.3CirQueue/CirQueue.h"
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
private:
	BTNode<T> *root;         //ָ�������ͷָ��
	BTNode<T> *Create();     //�вι��캯������
	void Release(BTNode<T> *root);   //������������ 
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
	}
}


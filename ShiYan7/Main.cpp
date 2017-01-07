#include <iostream>
using namespace std;
template<typename T>
struct BiNode
{
	T data;
	BiNode<T> *lchild, *rchild;
};

class BiSortTree
{
public:
	BiSortTree(int a[] , int n);//�������Ҽ���a[]�Ķ���������
	~BiSortTree();
	void InsertBST(BiNode<int> *root , BiNode<int> *s);//����һ�����S
	void DeleteBST(BiNode<int> *p, BiNode<int> *f);    //ɾ�����f����p
	BiNode<int> *SearchBST(BiNode<int> *root, int k);   //����ֵΪk�Ľ��
	BiNode<int> *GetRoot() { return root; }
	void Print(BiNode<int> *root);
private:
	BiNode<int> *root = nullptr;
};

BiSortTree::BiSortTree(int r[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		BiNode<int> *s = new BiNode<int>;
		s->data = r[i];
		s->lchild = s->rchild = nullptr;
		InsertBST(root, s);
	}
}

BiSortTree::~BiSortTree()
{
}

void BiSortTree::InsertBST(BiNode<int> *root, BiNode<int> *s)
{
	if (root == nullptr)
	{
		root = s;
	}
	else if(s->data < root->data)
	{
		InsertBST(root->lchild, s);
	}
	else
	{
		InsertBST(root->rchild, s);
	}
}

void BiSortTree::DeleteBST(BiNode<int>* p, BiNode<int>* f)
{
	if ((p->lchild == nullptr)&&(p->rchild == nullptr))//pΪҶ��
	{
		f->lchild = nullptr;
		delete p;
	}
	else if (p->rchild == nullptr)   //pֻ��������
	{
		f->lchild = p->lchild;
		delete p;
	}
	else if (p->lchild == nullptr)  //pֻ��������
	{
		f->lchild = p->rchild;
		delete p;
	}
	else                //p��������������Ϊ��
	{
		BiNode<int> *par = p;
		BiNode<int> *s = p->rchild;
		while (s->lchild != nullptr)     //���������½��
		{
			par = s;
			s = s->lchild;
		}
		p->data = s->data;
		if (par == p)
		{
			par->rchild = s->rchild;     //�����������
		}
		else
		{
			par->lchild = s->rchild;    //����һ�����
		}
		delete s;
	}                           //���Ҿ���Ϊ�յ�����������
	

	
}

BiNode<int> *BiSortTree::SearchBST(BiNode<int>* root, int k)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else if(root->data == k)
	{
		return root;
	}
	else if(root->data < k)
	{
		return SearchBST(root->lchild, k);
	}
	else
	{
		return SearchBST(root->rchild, k);
	}
}

void BiSortTree::Print(BiNode<int>* root)
{
	if (root == nullptr)
	{
		return ;
	}
	cout << root->data<<" ";
	Print(root->lchild);
	Print(root->rchild);
}

int main() 
{
	int a[] = { 63,55,90,42,58,70,10,45,67,83 };
	BiSortTree BSTree(a, /*sizeof(a)/sizeof(a[0])*/10);
	BSTree.Print(BSTree.GetRoot());
	cout << "������Ҫ���ҵ�ֵ��" << endl;
	int aa;
	cin >> aa;
	cout<<"���ҵ���"<<aa;
}
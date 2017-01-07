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
	BiSortTree(int a[] , int n);//建立查找集合a[]的二叉排序树
	~BiSortTree();
	void InsertBST(BiNode<int> *root , BiNode<int> *s);//插入一个结点S
	void DeleteBST(BiNode<int> *p, BiNode<int> *f);    //删除结点f左孩子p
	BiNode<int> *SearchBST(BiNode<int> *root, int k);   //查找值为k的结点
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
	if ((p->lchild == nullptr)&&(p->rchild == nullptr))//p为叶子
	{
		f->lchild = nullptr;
		delete p;
	}
	else if (p->rchild == nullptr)   //p只有左子树
	{
		f->lchild = p->lchild;
		delete p;
	}
	else if (p->lchild == nullptr)  //p只有右子树
	{
		f->lchild = p->rchild;
		delete p;
	}
	else                //p的左右子树均不为空
	{
		BiNode<int> *par = p;
		BiNode<int> *s = p->rchild;
		while (s->lchild != nullptr)     //查找最左下结点
		{
			par = s;
			s = s->lchild;
		}
		p->data = s->data;
		if (par == p)
		{
			par->rchild = s->rchild;     //处理特殊情况
		}
		else
		{
			par->lchild = s->rchild;    //处理一般情况
		}
		delete s;
	}                           //左右均不为空的情况处理完毕
	

	
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
	cout << "输入你要查找的值：" << endl;
	int aa;
	cin >> aa;
	cout<<"查找到："<<aa;
}
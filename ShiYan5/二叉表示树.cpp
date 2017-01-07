///**
//* 假设输入的中缀表达式为：
//* （a+b)*((c+d)*e+f*h*g)
//*
//* 1）以二叉链表的存储结构创建一棵。
//* 2）先根遍历为：此中缀表达式的前缀表达式
//* 3）后根遍历为：此中缀表达式的后缀表达式
//*
//*
//*/
//#include<stack>  
//#include<iostream>  
//#include<stdio.h>  
//#include<ctype.h>  
//#include<string.h>  
//using   namespace   std;
//
////////////////////////////////////////////////////////////////////////////  
////   数据类型定义区  
////  
//typedef   struct nodeTag { /*   表达式二叉树结点类型   */
//	union {
//		int opnd;
//		char optr;
//	}val;
//	struct   nodeTag *left;
//	struct   nodeTag *right;
//}treeNode;
//
//typedef   struct pTag { /*   优先表结点类型   */
//	char op;
//	int f;
//	int g;
//}Prior;
//
////////////////////////////////////////////////////////////////////////////  
////   全局变量定义区  
////  
//Prior pList[] = { /*   优先表   */
//	'+',   2,   1,
//	'-',   2,   1,
//	'*',   4,   3,
//	'/',   4,   3,
//	'^',   4,   5,
//	'(',   0,   5,
//	')',   6,   0,
//	'$',   0,   0
//};
//stack<char> OptrStack; /*   操作符栈   */
//stack<treeNode*> ExprStack; /*   表达式栈   */
//const   int   NUM = 256;
//const   int   OPTR = 257;
//int tokenval; /*   下一输入值   */
//
//			  /**************************************************************************
//			  *   descr     :比较栈顶运算符与下一输入运算符优先关系
//			  *   param     :opf   栈顶运算符
//			  *   param     :opg   下一输入运算符
//			  *   return   :关系'>',   '=',   '<'
//			  **************************************************************************/
//char   Precede(char   opf, char   opg)
//{
//	int   op1 = -1, op2 = -1;
//	for (int i = 0; i < 8; i++)
//	{
//		if (pList[i].op == opf)
//			op1 = pList[i].f;
//		if (pList[i].op == opg)
//			op2 = pList[i].g;
//	}
//	if (op1 == -1 || op2 == -1)
//	{
//		cout << "oper   error!" << endl;
//		exit(1);
//	}
//	if (op1 > op2)
//		return   '>';
//	else   if (op1 == op2)
//		return   '=';
//	else
//		return   '<';
//}
//
///**************************************************************************
//*   descr     :
//*   return   :
//**************************************************************************/
//int   lexan()
//{
//	int   t;
//	while (1)
//	{
//		t = getchar();
//		if (t == '   ' || t == '/t' || t == '/n')
//			; //去掉空白字符  
//		else   if (isdigit(t))
//		{
//			ungetc(t, stdin);
//			cin >> tokenval;
//			return   NUM;
//		}
//		else
//		{
//			return   t;
//		}
//	}
//}
///**************************************************************************
//*   descr     :   建立二叉树数结点(叶结点)
//*   param     :   num   操作数
//*   return   :   二叉树叶结点指针   treeNode*
//**************************************************************************/
//treeNode*   mkleaf(int   num)
//{
//	treeNode   *tmpTreeNode = new   treeNode;
//	if (tmpTreeNode == NULL)
//	{
//		cout << "Memory   allot   failed!" << endl;
//		exit(1);
//	}
//	tmpTreeNode->left = NULL;
//	tmpTreeNode->right = NULL;
//	tmpTreeNode->val.opnd = num;
//	return   tmpTreeNode;
//}
//
///**************************************************************************
//*   descr     :   建立二叉树运算符结点(内结点)
//*   param     :   op运算符
//*   param     :   left左子树指针
//*   param     :   right右子树指针
//*   return   :   二叉树内结点指针   treeNode*
//**************************************************************************/
//treeNode*   mknode(char   op, treeNode*   left, treeNode*   right)
//{
//	treeNode   *tmpTreeNode = new   treeNode;
//	if (tmpTreeNode == NULL)
//	{
//		cout << "Memory   allot   failed!" << endl;
//		exit(1);
//	}
//	if (left == NULL || right == NULL)
//	{
//		cout << "Lossing   operand!" << endl;
//		exit(1);
//	}
//	tmpTreeNode->left = left;
//	tmpTreeNode->right = right;
//	tmpTreeNode->val.optr = op;
//	return   tmpTreeNode;
//}
//
///**************************************************************************
//*   descr     :   建立表达式二叉树(参考严蔚敏，吴伟民的《数据结构》P/53)
//*   return   :   二叉树跟结点指针
//**************************************************************************/
//treeNode*   CreateBinaryTree()
//{
//	int     lookahead;
//	char   op;
//	treeNode   *opnd1, *opnd2;
//	OptrStack.push('$');
//	lookahead = lexan();
//	while (lookahead != '$' || OptrStack.top() != '$')
//	{
//		if (lookahead == NUM)
//		{
//			ExprStack.push(mkleaf(tokenval));
//			lookahead = lexan();
//		}
//		else
//		{
//			switch (Precede(OptrStack.top(), lookahead))
//			{
//			case   '<':
//				OptrStack.push(lookahead);
//				lookahead = lexan();
//				break;
//			case   '=':
//				OptrStack.pop();
//				lookahead = lexan();
//				break;
//			case   '>':
//				opnd2 = ExprStack.top(); ExprStack.pop();
//				opnd1 = ExprStack.top(); ExprStack.pop();
//				op = OptrStack.top(); OptrStack.pop();
//				ExprStack.push(mknode(op, opnd1, opnd2));
//				break;
//			}
//		}
//	}
//	return   ExprStack.top();
//}
//
///**************************************************************************
//*   descr     :   输出前缀表达式
//*   param     :
//*   return   :
//**************************************************************************/
//int   PreOrderTraverse(treeNode*   T)
//{
//	if (T == NULL)
//		return   1;
//	if (T->left != NULL)
//	{
//		cout << T->val.optr << "   ";
//		if (PreOrderTraverse(T->left))
//			if (PreOrderTraverse(T->right))
//				return   1;
//		return   0;
//	}
//	else
//	{
//		cout << T->val.opnd << "   ";
//		return   1;
//	}
//}
//
///**************************************************************************
//*   descr     :   输出后缀表达式
//*   param     :
//*   return   :
//**************************************************************************/
//int   FollowOrderTraverse(treeNode*   T)
//{
//	if (T == NULL)
//		return   1;
//	if (T->left != NULL)
//	{
//		if (FollowOrderTraverse(T->left))
//			if (FollowOrderTraverse(T->right))
//			{
//				cout << T->val.optr << "   ";
//				return   1;
//			}
//		return   0;
//
//	}
//	else
//	{
//		cout << T->val.opnd << "   ";
//		return   1;
//	}
//}
//
////////////////////////////////////////////////////////////////////////////  
////   主程序  
////  
//int main()
//{
//	treeNode   *ExprTree;
//	ExprTree = CreateBinaryTree();
//	PreOrderTraverse(ExprTree);
//	cout << endl;
//	FollowOrderTraverse(ExprTree);
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <cstring>
//#include <stdlib.h>
//#include <cstdio>
//using namespace std;
//
//typedef struct TreeNode
//{
//	struct TreeNode* lchild;
//	struct TreeNode* rchild;
//	char elem;
//}TreeNode;
////构造树
//TreeNode *CreateTree()
//{
//	char c = getchar();
//	if (c == '#')
//		return NULL;
//	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
//	root->elem = c;
//	root->lchild = CreateTree();
//	root->rchild = CreateTree();
//	return root;
//}
////中序遍历树
//void Traversal(TreeNode *root)
//{
//	if (root == NULL)
//		return;
//	Traversal(root->lchild);
//	cout << root->elem;
//	Traversal(root->rchild);
//}
//
//int main()
//{
//	TreeNode *root = CreateTree();
//	Traversal(root);
//	cout << endl;
//}


//#include <iostream>
//#include <stack>
//#include <queue>
//#include <string>
//#include<math.h>
//using namespace std;
//class TNode//节点类
//{
//public:
//	char oper;
//	TNode *left;
//	TNode *right;
//	int s; int t;
//		TNode()
//	{
//		left = right = NULL;
//		oper = 0;
//	}
//	TNode(char op)
//	{
//		left = right = NULL;
//		oper = op;
//	}
//};
//bool isOper(char op)//判断是否为运算符
//{
//	char oper[] = { '(',')','+','-','*','/','^' };
//	for (int i = 0; i < sizeof(oper); i++)
//	{
//		if (op == oper[i])
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//int getOperOrder(char op)//返回运算符op所对应的优先级
//{
//	switch (op)
//	{
//	case '(':
//		return 1;
//	case '+':
//	case '-':
//		return 2;
//	case '*':
//	case '/':
//		return 3;
//	case '^':
//		return 4;
//	default:
//		//定义在栈中的右括号和栈底字符的优先级最低
//		return 0;
//	}
//}
//void freeTree(TNode *&p) //释放树
//{
//	if (p->left != NULL)
//		freeTree(p->left);
//	if (p->right != NULL)
//		freeTree(p->right);
//	delete(p);
//	cout << "Memory free ";
//}
//
//void postOrder(TNode *p) //先序遍历
//{
//	if (p)
//	{
//		postOrder(p->left);
//		postOrder(p->right);
//		cout << p->oper;
//	}
//}
//
//void preOrder(TNode *p) //后序遍历
//{
//	if (p)
//	{
//		cout << p->oper;
//		preOrder(p->left);
//		preOrder(p->right);
//	}
//}
//
//void inOrder(TNode *p)//中序遍历
//{
//	if (p)
//	{
//		if (p->left)
//		{
//			if (isOper(p->left->oper)
//				&& getOperOrder(p->left->oper)
//				< getOperOrder(p->oper))
//			{
//				cout << "(";
//				inOrder(p->left);
//				cout << ")";
//			}
//			else {
//				inOrder(p->left);
//			}
//		}
//		cout << p->oper;
//		if (p->right)
//		{
//			if (isOper(p->right->oper)
//				&& getOperOrder(p->right->oper)
//				<= getOperOrder(p->oper))
//			{
//				cout << "(";
//				inOrder(p->right);
//				cout << ")";
//			}
//			else {
//				inOrder(p->right);
//			}
//		}
//	}
//}
//
//void ExpTree1(TNode *&p, string str)//后缀表达式生成二叉树
//{
//	stack <TNode*> nodeStack;
//	char temp;
//	int i = 0;
//	temp = str[i++];
//	while (temp != '\0')
//	{
//		if (temp != '\0' && !isOper(temp))//不是运算符，则进栈
//		{
//			p = new TNode(temp);//以temp为结点值构造二叉树结点
//			nodeStack.push(p);
//			temp = str[i++];
//		}
//		else
//		{
//			p = new TNode(temp);
//			if (nodeStack.size())
//			{
//				p->right = nodeStack.top();//若非空则弹栈并设为结点的右孩子
//				nodeStack.pop();
//			}
//			if (nodeStack.size())
//			{
//				p->left = nodeStack.top();//若非空则弹栈并设为结点的左孩子
//				nodeStack.pop();
//			}
//			nodeStack.push(p);
//			temp = str[i++];
//		}
//	}
//}
//void ExpTree3(TNode *&p, string str)//前缀表达式生成二叉树
//{
//	stack <TNode*> nodeStack;
//	char temp;
//	int i = str.size() - 1;
//	temp = str[i--];
//	while (temp != '\0')
//	{
//		if (temp != '\0' && !isOper(temp))
//		{
//			p = new TNode(temp);//以temp为内容来建立新的结点
//			nodeStack.push(p);
//			temp = str[i--];
//		}
//		else
//		{
//			p = new TNode(temp);
//			if (nodeStack.size())//若栈顶指针所指结点左孩子为空
//			{
//				p->left = nodeStack.top(); //则当前结点设置成其左孩子
//				nodeStack.pop();
//			} if (nodeStack.size())//若栈顶指针所指结点右孩子为空 
//			{
//				p->right = nodeStack.top();//则当前结点设置成其右孩子
//				nodeStack.pop();//栈顶元素左右孩子指针设置完毕弹出 
//			}
//				nodeStack.push(p);
//				temp = str[i--];
//			}
//		}
//	}
//
//	void ExpTree2(TNode *&p, string str)//中缀表达式转换成后缀表达式生成二叉树
//	{
//		stack<char> a;
//		char temp;
//		string Postfixexp = "";
//		int i = 0;
//		temp = str[i++];
//		while (temp != '\0')
//		{
//			if (!isOper(temp))
//			{
//				Postfixexp += temp;
//				temp = str[i++];
//			}
//			else if (temp == '(')//进栈
//			{
//				a.push(temp);
//				temp = str[i++];
//			}
//			else if (temp == ')') {
//				while (a.top() != '(')//脱括号
//				{
//					Postfixexp += a.top();
//					a.pop();//在碰到开括号和栈为空前反复弹出栈中元素 
//				}
//					a.pop();
//					temp = str[i++];
//				}
//			else if (temp == '+' || temp == '-' || temp == '*' || temp == '/')//出栈
//			{
//				while (!a.empty() && a.top() != '('&&getOperOrder(a.top()) >= getOperOrder(temp))//若栈非空栈顶不是左括号且栈顶元素优先级不低于输入运算符时，
//																								 //将栈顶元素弹出到后缀表达式中，并且str下标加1
//				{
//					Postfixexp += a.top();
//					a.pop();
//				}
//			a.push(temp);
//			temp = str[i++];
//			}
//		}
//		while (!a.empty())
//		{
//			Postfixexp += a.top();
//			a.pop();
//		}
//		ExpTree1(p, Postfixexp);
//	}
//	void count(TNode *p, int &height, int n)//求值函数
//	{
//		if (p->left == NULL&&p->right == NULL)
//		{
//			if (n > height)
//				height = n;
//		}
//		if (p->left != NULL)
//			count(p->left, height, n + 1);
//		if (p->right != NULL)
//			count(p->right, height, n + 1);
//	}
//	void paint(TNode *p)//输出函数
//	{
//		int height = 0;
//		int h = 0;
//		int i;
//		using std::queue;
//		queue<TNode*> aQueue;
//		count(p, height, 1);
//		TNode *pointer = p;
//		TNode *lastpointer;
//		if (pointer)
//		{
//			pointer->s = 1;
//			pointer->t = 1;
//			aQueue.push(pointer);
//		}
//		while (!aQueue.empty())
//		{
//			lastpointer = pointer;
//			pointer = aQueue.front();
//			aQueue.pop();
//			if (pointer->s > h)
//			{
//				cout << endl;
//				h = pointer->s;
//			}
//			if (pointer->t == 1)
//			{
//				for (i = 0; i < pow(2, height - pointer->s) - 1; i++)
//					cout << " ";
//			}
//			else if (lastpointer->s != pointer->s) {
//				for (i = 0; i < (pointer->t - 1)*(pow(2, height - pointer->s + 1) - 1) + (pointer->t - 1) - 1 + pow(2, height - pointer->s); i++)
//					cout << " ";
//			}
//			else
//			{
//				for (i = 0; i < (pointer->t - lastpointer->t)*(pow(2, height - pointer->s + 1) - 1) + (pointer->t - lastpointer->t) - 1; i++)
//					cout << " ";
//			}
//			cout << pointer->oper;
//			if (pointer->left != NULL) {
//				pointer->left->s = pointer->s + 1;
//				pointer->left->t = pointer->t * 2 - 1;
//				aQueue.push(pointer->left);
//			}
//			if (pointer->right != NULL) {
//				pointer->right->s = pointer->s + 1;
//				pointer->right->t = pointer->t * 2;
//				aQueue.push(pointer->right);
//			}
//		}
//	}
//	int main()
//	{
//		string expression;
//		TNode *tree;
//		cout << endl << "请输入字符串表达式:";
//		cin >> expression;
//		if (isOper(expression[0]))
//			ExpTree3(tree, expression);
//		else if (isOper(expression[1]))
//			ExpTree2(tree, expression);
//		else
//			ExpTree1(tree, expression);
//		paint(tree);
//		cout << endl;
//		cout << "中缀表达式为:";
//		inOrder(tree);
//		cout << endl;
//		cout << "前缀表达式为:";
//		preOrder(tree);
//		cout << endl;
//		cout << "后缀表达式为:";
//		postOrder(tree);
//		cout << endl;
//		freeTree(tree);
//		cout << endl;
//		system("pause");
//		return 0;
//	}


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//树结点的设计
typedef struct node
{
	//数字和运算符
	union
	{
		char oper;
		int data;
	};

	struct node *lchild;
	struct node *rchild;

}TreeNode;

//树栈的设计
typedef struct
{
	TreeNode *buf[MAX];
	int n;

}TreeStack;

//创建空栈
TreeStack *create_empty_stack()
{
	TreeStack *pstack;

	pstack = (TreeStack *)malloc(sizeof(TreeStack));
	pstack->n = -1;

	return pstack;
}

//入栈
int push_stack(TreeStack *p, TreeNode *data)
{
	p->n++;
	p->buf[p->n] = data;

	return 0;
}

//出栈
TreeNode *pop_stack(TreeStack *p)
{
	TreeNode *data;

	data = p->buf[p->n];
	p->n--;

	return data;
}

//判断空栈
int is_empty_stack(TreeStack *p)
{
	if (p->n == -1)
	{
		return 1;

	}
	else {
		return 0;
	}
}

//后缀表达式树的创建
TreeNode *create_express_tree(char *str, TreeStack *p)
{
	int i = 0;
	TreeNode *current;
	TreeNode *left, *right;

	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			current = (TreeNode *)malloc(sizeof(TreeNode));
			current->data = str[i] - '0';
			current->lchild = current->rchild = NULL;
			push_stack(p, current);

		}
		else {
			current = (TreeNode *)malloc(sizeof(TreeNode));
			current->oper = str[i];
			right = pop_stack(p);
			left = pop_stack(p);
			current->lchild = left;
			current->rchild = right;
			push_stack(p, current);
		}

		i++;
	}

	return p->buf[p->n];
}

//打印结点
void print_node(TreeNode *p)
{
	if (p->lchild == NULL && p->rchild == NULL)
	{
		printf("%d ", p->data);

	}
	else {

		printf("%c ", p->oper);
	}

	return;
}

//访问结点
int vist_node(TreeNode *p)
{
	print_node(p);

	return 0;
}

//树的后序遍历
int PostOrder(TreeNode *p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);//左
		PostOrder(p->rchild);//右
		vist_node(p);//根
	}

	return 0;
}

//树的中序遍历
int InOrder(TreeNode *p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);//左
		vist_node(p);//根
		InOrder(p->rchild);//右
	}

	return 0;
}

//树的前序遍历
int PreOrder(TreeNode *p)
{
	if (p != NULL)
	{
		vist_node(p);//根
		PreOrder(p->lchild);//左
		PreOrder(p->rchild);//右
	}

	return 0;
}

// 队列的设计
struct _node_
{
	TreeNode *data;
	struct _node_ *next;
};

typedef struct
{
	struct _node_ *front;
	struct _node_ *rear;

}Queue;

//创建空队列
Queue *create_empty_queue()
{
	struct _node_ *pnode;
	Queue *qhead;

	qhead = (Queue *)malloc(sizeof(Queue));
	pnode = (struct _node_ *)malloc(sizeof(struct _node_));
	pnode->next = NULL;

	qhead->front = qhead->rear = pnode;

	return qhead;
}

//入队
int EnterQueue(Queue *qhead, TreeNode *data)
{
	struct _node_ *temp;

	temp = (struct _node_ *)malloc(sizeof(struct _node_ *));
	temp->data = data;
	temp->next = NULL;

	qhead->rear->next = temp;
	qhead->rear = temp;

	return 0;
}

//出队
TreeNode *DeleteQueue(Queue *qhead)
{
	struct _node_ *temp;

	temp = qhead->front;
	qhead->front = temp->next;
	free(temp);
	temp = NULL;

	return qhead->front->data;
}

//队列为空
int is_empty_queue(Queue *qhead)
{
	if (qhead->front == qhead->rear)
		return 1;
	else
		return 0;
}

//树的层次遍历
int NoOrder(TreeNode *p)
{
	Queue *qhead;
	TreeNode *pdata;

	qhead = create_empty_queue();
	EnterQueue(qhead, p);

	while (!is_empty_queue(qhead))
	{
		pdata = DeleteQueue(qhead);
		vist_node(pdata);

		if (pdata->lchild)EnterQueue(qhead, pdata->lchild);
		if (pdata->rchild)EnterQueue(qhead, pdata->rchild);
	}

	return 0;
}

int main()
{
	TreeNode *thead;
	TreeStack *pstack;
	int i = 0;
	char buf[100];

	while ((buf[i++] = getchar()) != '\n' && i < 100);
	buf[i - 1] = 0;

	pstack = create_empty_stack();
	thead = create_express_tree(buf, pstack);

	printf("PostOrder:: ");
	PostOrder(thead);
	printf("\n");

	printf("InOrder:: ");
	InOrder(thead);
	printf("\n");

	printf("PreOrder:: ");
	PreOrder(thead);
	printf("\n");

	printf("NoOrder::");
	NoOrder(thead);
	printf("\n");

	return 0;
}
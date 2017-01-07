///**
//* �����������׺���ʽΪ��
//* ��a+b)*((c+d)*e+f*h*g)
//*
//* 1���Զ�������Ĵ洢�ṹ����һ�á�
//* 2���ȸ�����Ϊ������׺���ʽ��ǰ׺���ʽ
//* 3���������Ϊ������׺���ʽ�ĺ�׺���ʽ
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
////   �������Ͷ�����  
////  
//typedef   struct nodeTag { /*   ���ʽ�������������   */
//	union {
//		int opnd;
//		char optr;
//	}val;
//	struct   nodeTag *left;
//	struct   nodeTag *right;
//}treeNode;
//
//typedef   struct pTag { /*   ���ȱ�������   */
//	char op;
//	int f;
//	int g;
//}Prior;
//
////////////////////////////////////////////////////////////////////////////  
////   ȫ�ֱ���������  
////  
//Prior pList[] = { /*   ���ȱ�   */
//	'+',   2,   1,
//	'-',   2,   1,
//	'*',   4,   3,
//	'/',   4,   3,
//	'^',   4,   5,
//	'(',   0,   5,
//	')',   6,   0,
//	'$',   0,   0
//};
//stack<char> OptrStack; /*   ������ջ   */
//stack<treeNode*> ExprStack; /*   ���ʽջ   */
//const   int   NUM = 256;
//const   int   OPTR = 257;
//int tokenval; /*   ��һ����ֵ   */
//
//			  /**************************************************************************
//			  *   descr     :�Ƚ�ջ�����������һ������������ȹ�ϵ
//			  *   param     :opf   ջ�������
//			  *   param     :opg   ��һ���������
//			  *   return   :��ϵ'>',   '=',   '<'
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
//			; //ȥ���հ��ַ�  
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
//*   descr     :   ���������������(Ҷ���)
//*   param     :   num   ������
//*   return   :   ������Ҷ���ָ��   treeNode*
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
//*   descr     :   ������������������(�ڽ��)
//*   param     :   op�����
//*   param     :   left������ָ��
//*   param     :   right������ָ��
//*   return   :   �������ڽ��ָ��   treeNode*
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
//*   descr     :   �������ʽ������(�ο���ε������ΰ��ġ����ݽṹ��P/53)
//*   return   :   �����������ָ��
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
//*   descr     :   ���ǰ׺���ʽ
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
//*   descr     :   �����׺���ʽ
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
////   ������  
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
////������
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
////���������
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
//class TNode//�ڵ���
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
//bool isOper(char op)//�ж��Ƿ�Ϊ�����
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
//int getOperOrder(char op)//���������op����Ӧ�����ȼ�
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
//		//������ջ�е������ź�ջ���ַ������ȼ����
//		return 0;
//	}
//}
//void freeTree(TNode *&p) //�ͷ���
//{
//	if (p->left != NULL)
//		freeTree(p->left);
//	if (p->right != NULL)
//		freeTree(p->right);
//	delete(p);
//	cout << "Memory free ";
//}
//
//void postOrder(TNode *p) //�������
//{
//	if (p)
//	{
//		postOrder(p->left);
//		postOrder(p->right);
//		cout << p->oper;
//	}
//}
//
//void preOrder(TNode *p) //�������
//{
//	if (p)
//	{
//		cout << p->oper;
//		preOrder(p->left);
//		preOrder(p->right);
//	}
//}
//
//void inOrder(TNode *p)//�������
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
//void ExpTree1(TNode *&p, string str)//��׺���ʽ���ɶ�����
//{
//	stack <TNode*> nodeStack;
//	char temp;
//	int i = 0;
//	temp = str[i++];
//	while (temp != '\0')
//	{
//		if (temp != '\0' && !isOper(temp))//��������������ջ
//		{
//			p = new TNode(temp);//��tempΪ���ֵ������������
//			nodeStack.push(p);
//			temp = str[i++];
//		}
//		else
//		{
//			p = new TNode(temp);
//			if (nodeStack.size())
//			{
//				p->right = nodeStack.top();//���ǿ���ջ����Ϊ�����Һ���
//				nodeStack.pop();
//			}
//			if (nodeStack.size())
//			{
//				p->left = nodeStack.top();//���ǿ���ջ����Ϊ��������
//				nodeStack.pop();
//			}
//			nodeStack.push(p);
//			temp = str[i++];
//		}
//	}
//}
//void ExpTree3(TNode *&p, string str)//ǰ׺���ʽ���ɶ�����
//{
//	stack <TNode*> nodeStack;
//	char temp;
//	int i = str.size() - 1;
//	temp = str[i--];
//	while (temp != '\0')
//	{
//		if (temp != '\0' && !isOper(temp))
//		{
//			p = new TNode(temp);//��tempΪ�����������µĽ��
//			nodeStack.push(p);
//			temp = str[i--];
//		}
//		else
//		{
//			p = new TNode(temp);
//			if (nodeStack.size())//��ջ��ָ����ָ�������Ϊ��
//			{
//				p->left = nodeStack.top(); //��ǰ������ó�������
//				nodeStack.pop();
//			} if (nodeStack.size())//��ջ��ָ����ָ����Һ���Ϊ�� 
//			{
//				p->right = nodeStack.top();//��ǰ������ó����Һ���
//				nodeStack.pop();//ջ��Ԫ�����Һ���ָ��������ϵ��� 
//			}
//				nodeStack.push(p);
//				temp = str[i--];
//			}
//		}
//	}
//
//	void ExpTree2(TNode *&p, string str)//��׺���ʽת���ɺ�׺���ʽ���ɶ�����
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
//			else if (temp == '(')//��ջ
//			{
//				a.push(temp);
//				temp = str[i++];
//			}
//			else if (temp == ')') {
//				while (a.top() != '(')//������
//				{
//					Postfixexp += a.top();
//					a.pop();//�����������ź�ջΪ��ǰ��������ջ��Ԫ�� 
//				}
//					a.pop();
//					temp = str[i++];
//				}
//			else if (temp == '+' || temp == '-' || temp == '*' || temp == '/')//��ջ
//			{
//				while (!a.empty() && a.top() != '('&&getOperOrder(a.top()) >= getOperOrder(temp))//��ջ�ǿ�ջ��������������ջ��Ԫ�����ȼ����������������ʱ��
//																								 //��ջ��Ԫ�ص�������׺���ʽ�У�����str�±��1
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
//	void count(TNode *p, int &height, int n)//��ֵ����
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
//	void paint(TNode *p)//�������
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
//		cout << endl << "�������ַ������ʽ:";
//		cin >> expression;
//		if (isOper(expression[0]))
//			ExpTree3(tree, expression);
//		else if (isOper(expression[1]))
//			ExpTree2(tree, expression);
//		else
//			ExpTree1(tree, expression);
//		paint(tree);
//		cout << endl;
//		cout << "��׺���ʽΪ:";
//		inOrder(tree);
//		cout << endl;
//		cout << "ǰ׺���ʽΪ:";
//		preOrder(tree);
//		cout << endl;
//		cout << "��׺���ʽΪ:";
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

//���������
typedef struct node
{
	//���ֺ������
	union
	{
		char oper;
		int data;
	};

	struct node *lchild;
	struct node *rchild;

}TreeNode;

//��ջ�����
typedef struct
{
	TreeNode *buf[MAX];
	int n;

}TreeStack;

//������ջ
TreeStack *create_empty_stack()
{
	TreeStack *pstack;

	pstack = (TreeStack *)malloc(sizeof(TreeStack));
	pstack->n = -1;

	return pstack;
}

//��ջ
int push_stack(TreeStack *p, TreeNode *data)
{
	p->n++;
	p->buf[p->n] = data;

	return 0;
}

//��ջ
TreeNode *pop_stack(TreeStack *p)
{
	TreeNode *data;

	data = p->buf[p->n];
	p->n--;

	return data;
}

//�жϿ�ջ
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

//��׺���ʽ���Ĵ���
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

//��ӡ���
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

//���ʽ��
int vist_node(TreeNode *p)
{
	print_node(p);

	return 0;
}

//���ĺ������
int PostOrder(TreeNode *p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);//��
		PostOrder(p->rchild);//��
		vist_node(p);//��
	}

	return 0;
}

//�����������
int InOrder(TreeNode *p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);//��
		vist_node(p);//��
		InOrder(p->rchild);//��
	}

	return 0;
}

//����ǰ�����
int PreOrder(TreeNode *p)
{
	if (p != NULL)
	{
		vist_node(p);//��
		PreOrder(p->lchild);//��
		PreOrder(p->rchild);//��
	}

	return 0;
}

// ���е����
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

//�����ն���
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

//���
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

//����
TreeNode *DeleteQueue(Queue *qhead)
{
	struct _node_ *temp;

	temp = qhead->front;
	qhead->front = temp->next;
	free(temp);
	temp = NULL;

	return qhead->front->data;
}

//����Ϊ��
int is_empty_queue(Queue *qhead)
{
	if (qhead->front == qhead->rear)
		return 1;
	else
		return 0;
}

//���Ĳ�α���
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
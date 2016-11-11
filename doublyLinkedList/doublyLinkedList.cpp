#include <iostream>           //引用输入输出流库函数的头文件
//#include "SeqList.cpp"           //引用顺序表的类声明和定义
#include "doublyLinkedList.h"
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int r[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	try
	{
		//构造一个顺序表，可能抛异常
	LinkedList<int> doublylinklist(r, 10); //修改const int MaxSize = 4; 会抛出"参数非法"异常

									  // 输出线性表
		cout << "链表结点数据为：";
		doublylinklist.PrintList();              //输出所有元素
		cout << endl;
		cout << "链表的长度：";
		cout<< doublylinklist.Length();
		cout << endl;

		cout << "链表结点插入前数据为：";
		doublylinklist.PrintList();              //输出所有元素
		cout << endl;
		cout << "插入后：";
		doublylinklist.Insert(4,77);
		doublylinklist.PrintList();              //输出所有元素
		cout << endl;

		cout << "链表结点删除前数据为：";
		doublylinklist.PrintList();              //输出所有元素
		cout << endl;
		doublylinklist.Delete(4);
		cout << "删除后：";
		doublylinklist.PrintList();              //输出所有元素
		cout << endl;
		//// 线性表长度
		//cout << "线性表的长度为：" << seqList.Length() << endl;

		// 按位查找
		//cout << "第4个元素为:";
		//cout << seqList.Get(4) << endl;    //查找第4个元素
		//								   //cout << seqList.Get(40) << endl;    //查找第40个元素，抛出“查找位置非法”

		//								   //								   // 按值查找操作
		//cout << "值为3的元素位置为:";
		//cout << doublylinklist.Locate(3) << endl;    //查找元素3，并返回在线性表中位置
		//cout << "值为33的元素位置为:";
		//cout << doublylinklist.Locate(33) << endl;    //查找元素33，查找不成功，返回0

		//									   //									   // 插入操作
		//cout << "执行插入操作前数据为：";
		//seqList.PrintList();              //输出所有元素
		//cout << endl;
		//seqList.Insert(2, 3); //修改const int MaxSize = 5; 会抛出"参数非法"异常
		//					  //seqList.Insert(20, 3); // 抛出“位置异常”
		//cout << "执行插入操作后数据为：";
		//seqList.PrintList();              //输出所有元素
		//cout << endl;

		//// 删除操作
		//cout << "删除前数据为：";
		//seqList.PrintList();              //输出所有元素
		//cout << endl;
		//seqList.Delete(3);                //删除第m个元素
		//cout << "删除后数据为：";
		//seqList.PrintList();              //输出所有元素
		//cout << endl;

		//cout << "删除位置为0的数据：";
		//doublylinklist.Delete(0);                //抛出“位置异常”
		//cout << "删除位置为10的数据：";
		//doublylinklist.Delete(10);                //抛出“位置异常”
	}
	catch (char *s)
	{
		cout << s << endl;
	}

	//cin.ignore();	// 解决控制台“一闪而过”。 Windows操作系统中可用system("PAUSE");语句替代（不推荐，不跨平台）
	return 0;
}

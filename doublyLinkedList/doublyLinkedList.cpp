#include <iostream>           //��������������⺯����ͷ�ļ�
//#include "SeqList.cpp"           //����˳�����������Ͷ���
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
		//����һ��˳����������쳣
	LinkedList<int> doublylinklist(r, 10); //�޸�const int MaxSize = 4; ���׳�"�����Ƿ�"�쳣

									  // ������Ա�
		cout << "����������Ϊ��";
		doublylinklist.PrintList();              //�������Ԫ��
		cout << endl;
		cout << "����ĳ��ȣ�";
		cout<< doublylinklist.Length();
		cout << endl;

		cout << "���������ǰ����Ϊ��";
		doublylinklist.PrintList();              //�������Ԫ��
		cout << endl;
		cout << "�����";
		doublylinklist.Insert(4,77);
		doublylinklist.PrintList();              //�������Ԫ��
		cout << endl;

		cout << "������ɾ��ǰ����Ϊ��";
		doublylinklist.PrintList();              //�������Ԫ��
		cout << endl;
		doublylinklist.Delete(4);
		cout << "ɾ����";
		doublylinklist.PrintList();              //�������Ԫ��
		cout << endl;
		//// ���Ա���
		//cout << "���Ա�ĳ���Ϊ��" << seqList.Length() << endl;

		// ��λ����
		//cout << "��4��Ԫ��Ϊ:";
		//cout << seqList.Get(4) << endl;    //���ҵ�4��Ԫ��
		//								   //cout << seqList.Get(40) << endl;    //���ҵ�40��Ԫ�أ��׳�������λ�÷Ƿ���

		//								   //								   // ��ֵ���Ҳ���
		//cout << "ֵΪ3��Ԫ��λ��Ϊ:";
		//cout << doublylinklist.Locate(3) << endl;    //����Ԫ��3�������������Ա���λ��
		//cout << "ֵΪ33��Ԫ��λ��Ϊ:";
		//cout << doublylinklist.Locate(33) << endl;    //����Ԫ��33�����Ҳ��ɹ�������0

		//									   //									   // �������
		//cout << "ִ�в������ǰ����Ϊ��";
		//seqList.PrintList();              //�������Ԫ��
		//cout << endl;
		//seqList.Insert(2, 3); //�޸�const int MaxSize = 5; ���׳�"�����Ƿ�"�쳣
		//					  //seqList.Insert(20, 3); // �׳���λ���쳣��
		//cout << "ִ�в������������Ϊ��";
		//seqList.PrintList();              //�������Ԫ��
		//cout << endl;

		//// ɾ������
		//cout << "ɾ��ǰ����Ϊ��";
		//seqList.PrintList();              //�������Ԫ��
		//cout << endl;
		//seqList.Delete(3);                //ɾ����m��Ԫ��
		//cout << "ɾ��������Ϊ��";
		//seqList.PrintList();              //�������Ԫ��
		//cout << endl;

		//cout << "ɾ��λ��Ϊ0�����ݣ�";
		//doublylinklist.Delete(0);                //�׳���λ���쳣��
		//cout << "ɾ��λ��Ϊ10�����ݣ�";
		//doublylinklist.Delete(10);                //�׳���λ���쳣��
	}
	catch (char *s)
	{
		cout << s << endl;
	}

	//cin.ignore();	// �������̨��һ���������� Windows����ϵͳ�п���system("PAUSE");�����������Ƽ�������ƽ̨��
	return 0;
}

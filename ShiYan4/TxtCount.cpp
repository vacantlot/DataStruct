//#include <iostream>
//#include <fstream>
//#include <sstream>
//using namespace std;
//int main() 
//{
//	try
//	{
//		int count = 0;
//		FILE *infile;
//		char buffer[1003];  //���������洢��ȡ����ÿ�е�����
//		int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
//		int i;  // ��ǰ�����������ĵ�i���ַ�
//		char c;  // ��ȡ�����ַ�
//		int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
//		int charNum = 0;  // ��ǰ�е��ַ���
//		int wordNum = 0; // ��ǰ�еĵ�����	
//		int totalNum = 0;
//		errno_t err;
//		if ((err = fopen_s(&infile,"C:\\Users\\Chen\\Desktop\\����\\���ݽṹ\\DataStruct\\ShiYan4\\Debug\\TxtCount.txt" , "r")) == 0)
//		{
//			/*char temp[1023];
//			int state = 1;
//			while (!infile.eof())
//			{
//				temp = infile.getline();
//				if (temp == ' '|| temp == '\t')
//				{
//					state = 1;
//				}
//				else if (state == 1)
//				{
//					state = 0;
//					count++;
//				}*/			
//			// ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
//			while (fgets(buffer, 1003, infile) != NULL) 
//			{
//				bufferLen = strlen(buffer);			
//				// ����������������
//				for (i = 0; i < bufferLen; i++) {
//					c = buffer[i];					
//					if (c == ' ' || c == '\t')  // �����ո�
//					{ 
//						!isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
//						isLastBlank = 1;
//					}
//					else if (c != '\n'&&c != '\r') // ���Ի��з�
//					{  	
//						charNum++;
//						isLastBlank = 0;
//					}
//				}
//				!isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
//				isLastBlank = 1;  // ÿ�λ�������Ϊ1
//								  // һ�н����������ܵ�����
//				totalNum += wordNum;  // �ܵ�����			
//				// ���㣬����ͳ����һ��		
//				wordNum = 0;
//			}	
//			printf("Total: %d words %d chars\n" , totalNum , charNum);
//		}
//		else
//		{
//			printf("cannot open file\n");
//			exit(0);
//		}
//	}
//	catch (exception ex)
//	{		
//		cout << "����";
//	}
//}
//#include <stdio.h>
//#include <fstream>
//#include <sstream>
//#include <string.h>
//#include <corecrt_wstdio.h>
//#include <iostream>
//using namespace std;
//int *getCharNum(char *filename, int *totalNum);
//int main() {
//	char filename[30];
//	// totalNum[0]: ������  totalNum[1]: ���ַ���  totalNum[2]: �ܵ�����
//	int totalNum[3] = { 0, 0, 0 };
//	printf("Input file name: ");
//	cin >> filename;
//	if (getCharNum(filename, totalNum)) {
//		printf("Total: %d lines, %d words, %d chars\n", totalNum[0], totalNum[2], totalNum[1]);
//	}
//	else {
//		printf("Error!\n");
//	}
//	return 0;
//}
///**
//* ͳ���ļ����ַ�����������������
//*
//* @param  filename  �ļ���
//* @param  totalNum  �ļ�ͳ������
//*
//* @return  �ɹ�����ͳ�����ݣ����򷵻�NULL
//**/
//int *getCharNum(char *filename, int *totalNum) {
//	FILE *fp;  // ָ���ļ���ָ��
//	char buffer[1003];  //���������洢��ȡ����ÿ�е�����
//	int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
//	int i;  // ��ǰ�����������ĵ�i���ַ�
//	char c;  // ��ȡ�����ַ�
//	int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
//	int charNum = 0;  // ��ǰ�е��ַ���
//	int wordNum = 0; // ��ǰ�еĵ�����
//	if ((fp = fopen(filename, "rb")) == NULL) {
//		perror(filename);
//		return NULL;
//	}
//	printf("line   words  chars\n");
//	// ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
//	while (fgets(buffer, 1003, fp) != NULL) {
//		bufferLen = strlen(buffer);
//		// ����������������
//		for (i = 0; i<bufferLen; i++) {
//			c = buffer[i];
//			if (c == ' ' || c == '\t') {  // �����ո�
//				!isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
//				isLastBlank = 1;
//			}
//			else if (c != '\n'&&c != '\r') {  // ���Ի��з�
//				charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
//				isLastBlank = 0;
//			}
//		}
//		!isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
//		isLastBlank = 1;  // ÿ�λ�������Ϊ1
//						  // һ�н������������ַ������ܵ�������������
//		totalNum[0]++;  // ������
//		totalNum[1] += charNum;  // ���ַ���
//		totalNum[2] += wordNum;  // �ܵ�����
//		printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);
//		// ���㣬����ͳ����һ��
//		charNum = 0;
//		wordNum = 0;
//	}
//	return totalNum;
//}

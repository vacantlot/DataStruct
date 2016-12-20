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
//		char buffer[1003];  //缓冲区，存储读取到的每行的内容
//		int bufferLen;  // 缓冲区中实际存储的内容的长度
//		int i;  // 当前读到缓冲区的第i个字符
//		char c;  // 读取到的字符
//		int isLastBlank = 0;  // 上个字符是否是空格
//		int charNum = 0;  // 当前行的字符数
//		int wordNum = 0; // 当前行的单词数	
//		int totalNum = 0;
//		errno_t err;
//		if ((err = fopen_s(&infile,"C:\\Users\\Chen\\Desktop\\桌面\\数据结构\\DataStruct\\ShiYan4\\Debug\\TxtCount.txt" , "r")) == 0)
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
//			// 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
//			while (fgets(buffer, 1003, infile) != NULL) 
//			{
//				bufferLen = strlen(buffer);			
//				// 遍历缓冲区的内容
//				for (i = 0; i < bufferLen; i++) {
//					c = buffer[i];					
//					if (c == ' ' || c == '\t')  // 遇到空格
//					{ 
//						!isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
//						isLastBlank = 1;
//					}
//					else if (c != '\n'&&c != '\r') // 忽略换行符
//					{  	
//						charNum++;
//						isLastBlank = 0;
//					}
//				}
//				!isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
//				isLastBlank = 1;  // 每次换行重置为1
//								  // 一行结束，计算总单词数
//				totalNum += wordNum;  // 总单词数			
//				// 置零，重新统计下一行		
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
//		cout << "出错";
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
//	// totalNum[0]: 总行数  totalNum[1]: 总字符数  totalNum[2]: 总单词数
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
//* 统计文件的字符数、单词数、行数
//*
//* @param  filename  文件名
//* @param  totalNum  文件统计数据
//*
//* @return  成功返回统计数据，否则返回NULL
//**/
//int *getCharNum(char *filename, int *totalNum) {
//	FILE *fp;  // 指向文件的指针
//	char buffer[1003];  //缓冲区，存储读取到的每行的内容
//	int bufferLen;  // 缓冲区中实际存储的内容的长度
//	int i;  // 当前读到缓冲区的第i个字符
//	char c;  // 读取到的字符
//	int isLastBlank = 0;  // 上个字符是否是空格
//	int charNum = 0;  // 当前行的字符数
//	int wordNum = 0; // 当前行的单词数
//	if ((fp = fopen(filename, "rb")) == NULL) {
//		perror(filename);
//		return NULL;
//	}
//	printf("line   words  chars\n");
//	// 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
//	while (fgets(buffer, 1003, fp) != NULL) {
//		bufferLen = strlen(buffer);
//		// 遍历缓冲区的内容
//		for (i = 0; i<bufferLen; i++) {
//			c = buffer[i];
//			if (c == ' ' || c == '\t') {  // 遇到空格
//				!isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
//				isLastBlank = 1;
//			}
//			else if (c != '\n'&&c != '\r') {  // 忽略换行符
//				charNum++;  // 如果既不是换行符也不是空格，字符数加1
//				isLastBlank = 0;
//			}
//		}
//		!isLastBlank && wordNum++;  // 如果最后一个字符不是空格，那么单词数加1
//		isLastBlank = 1;  // 每次换行重置为1
//						  // 一行结束，计算总字符数、总单词数、总行数
//		totalNum[0]++;  // 总行数
//		totalNum[1] += charNum;  // 总字符数
//		totalNum[2] += wordNum;  // 总单词数
//		printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);
//		// 置零，重新统计下一行
//		charNum = 0;
//		wordNum = 0;
//	}
//	return totalNum;
//}

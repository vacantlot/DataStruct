#include "HuffmanTree.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//try
	//{
	//	char buffer[256] = "";
	//	int w_Ascii[256] = {0};
	//	/*ofstream outfile;
	//	outfile.open("huffman.txt");
	//	if (!outfile.is_open())
	//	{
	//		cout << "file is not exist" << endl;
	//	}
	//	else
	//	{
	//		for (int i = 97; i <123 ; i++)
	//		{
	//			outfile << (char)i << ' ';
	//		}
	//		outfile.close();
	//	}*/

	//	ifstream infile("huffman.txt");
	//	if (infile.is_open())
	//	{
	//		int k = 0;
	//		while (!infile.eof())
	//		{
	//			infile >> buffer[k];
	//			for (int i = 0 ; i < 128 ; i++)
	//			{
	//				if (buffer[k] == i)
	//				{
	//					w_Ascii[i]++;
	//				}
	//			}
	//			k++;
	//		}
	//					
	//		infile.close();

	//		HuffmanTree<char> huffTree(buffer, w_Ascii, 128);
	//		huffTree.Bulid();
	//		huffTree.Print();
	//	}
	//	else
	//	{
	//		cout << "file is not exist" << endl;
	//	}
	//}
	//catch (char ex[])
	//{
	//	cout << *ex;
	//}
	//
	char ch[] = {'a' , 'b' , 'c' , 'd' , 'e'};
	int w[] = {35,25,15,15,10};
	
	HuffmanTree<char> huffTree(ch, w, 5);
	huffTree.Bulid();
	huffTree.Print();
	int huff[5];
	cin.ignore();
}
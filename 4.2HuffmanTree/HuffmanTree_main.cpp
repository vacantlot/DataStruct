#include "HuffmanTree.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//char ch[] = { 'a' , 'b' , 'c' , 'd' , 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	/*int w[26];
	char ch[26];
	char chTemp[26];
	for (int i = 0 ; i < 26 ; i++)
	{
		chTemp[i] = 0;
		 w[i] = 0;
	}
	*/
		/*ofstream outfile;
		outfile.open("huffman.txt",ios::app);
		if (!outfile.is_open())
		{
			cout << "file is not exist" << endl;
		}
		else
		{
			for (int i = 97; i <123 ; i++)
			{
				outfile << (char)i;
				cout << i;
			}
			outfile.close();
		}*/

		//ifstream infile("huffman.txt");
		//if (infile.is_open())
		//{
		//	char k;
		//	while (!infile.eof())
		//	{
		//		infile >> k;
		//		chTemp[int(k - 97)]++;
		//		w[int(k - 97)]++;//统计各字符的频率
		//	}
		//}
		//	infile.close();

		//	for (int i = 0 ; i < 26  ; i++)
		//	{
		//		if (chTemp[i] != 0)
		//		{
		//			ch[i] = char(i + 97);
		//		}
		//		
		//		cout << ch[i]<<" ";
		//	}
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
	char ch[] = { 'a' , 'b' , 'c' , 'd' , 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int w[] = { 2,1,1,5,1,4,6,19,12,13,14,31,51,1,17,1,1,15,1,14,1,19,12,11,13,16 };
	HuffmanTree<char> huffTree(ch , w , 26);
	huffTree.Bulid();
	huffTree.Print();
	LinkStack<int> *lStack = new LinkStack<int>();
	try
	{
		huffTree.HuffmanTree_Code(50,lStack);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	cin.ignore();
}
#include "HuffmanTree.h"
#include <iostream>
int main()
{
	char ch[] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h'};
	int w[] = {1 , 2 , 3 ,4 , 5 , 6 , 7 , 8};
	HuffmanTree<char> huffTree(ch ,w ,sizeof(w)/4);
	huffTree.Print();

}
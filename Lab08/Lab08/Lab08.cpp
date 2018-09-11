#include "stdafx.h"
#include "RedBlack.h"
#include <iostream>


int main()
{
	RedBlack<int, int> tree;
	for (int i = 1; i < 10; ++i)
	{
		tree.Insert(i, i);
		tree.Dump();
		std::cout << "\n-------------------------------------------------------------\n\n";
	}
	tree.Delete(9);
	tree.Delete(8);
	tree.Dump();
	system("pause");
    return 0;
}


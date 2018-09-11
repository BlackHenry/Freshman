#include "stdafx.h"
#include "OuterSort.h"


int main()
{
	OuterSort<int> os = OuterSort<int>("input.txt");
	os.Sort();
    return 0;
}


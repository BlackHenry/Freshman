// Lab03.cpp: определяет точку входа для консольного приложения.
//

#include <vector>
#include <map>
#include "MusicTable.h"

using namespace std;

MusicTable table("save.txt");

void load() {
	table.LoadTable();
	table.PrintTable();
}

void save() {
	table.AddColumn("Name");
	table.AddColumn("Duration");
	table.AddColumn("Author");
	table.AddRow(1);
	table.SaveTable();
	table.PrintTable();
}

int main()
{
	save();
    return 0;
}


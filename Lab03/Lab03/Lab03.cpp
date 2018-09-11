// Lab03.cpp: определяет точку входа для консольного приложения.
//

#include <vector>
#include <map>
#include "stdafx.h"
#include "MusicTable.h"

using namespace std;

MusicTable table("save.txt");

int main()
{
	string s = "";
	bool t = true;
	while (t) {
		cin >> s;
		if (s == "addRow") {
			table.AddRow();
			continue;
		}
		if (s == "removeRow") {
			int n;
			cout << "Enter row number:\n\n";
			cin >> n;
			table.RemoveRow(n);
			continue;
		}
		if (s == "search") {
			string s1, s2;
			cout << "Enter column:\n";
			cin >> s1;
			cout << "Enter value:\n";
			cin >> s2;
			vector<int> vr = table.Search(s1, s2);
			if (vr.size() == 0) {
				cout << "Song not found\n";
				continue;
			}
			table.PrintRow(0);
			for (int i = 0; i < vr.size(); i++) {
				table.PrintRow(vr[i]);
			}
			continue;
		}
		if (s == "printAnalysis") {
			table.PrintAnalysys();
			continue;
		}
		if (s == "changeCell") {
			char s[32];
			fill(s, s + 31, ' ');
			s[31] = '\0';
			int x, y;
			cout << "Enter x and y coordinates:\n";
			cin >> x >> y;
			if (x > table.size_x || y >= table.size_y) {
				cout << "Coordinates out of range!\n";
				continue;
			}
			cout << "Enter value:\n";
			scanf(" %32[^\n]s", s);
			table.Normalize(s);
			table.ChangeCell(x, y, s);
			continue;
		}
		if (s == "printTable") {
			table.PrintTable();
			continue;
		}
		if (s == "help") {
			cout << "List of commands:\naddRow - insert a row at the end of the table;\nremoveRow - delete a row from the table;\nsearch - search for a value in the table;\nprintAnalysis - print a short analysis of the table;\nchangeCell - change value in the cell with specific coordinates;\nprintTable - print the contents of the table;\nexit - exit the program;\n\n";
			continue;
		}
		if (s == "exit") {
			t = false;
			continue;
		}
		cout << "Command not found! Type \"help\" for list of commands\n";
	}
    return 0;
}


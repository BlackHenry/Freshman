// Lab04.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Program.h"

int main()
{
	Program p;
	string s = "";
	bool t = true;
	while (t) {
		cin >> s;
		if (s == "addRule") {
			string s1, s2;
			cout << "Print the first word of the rule:\n";
			cin >> s1;
			cout << "Print the second word of the rule:\n";
			cin >> s2;
			p.AddRule(Rule(s1 + "->" + s2));
			continue;
		}
		if (s == "run") {
			string s0, s1;
			cout << "Enter starting data:\n";
			cin >> s0;
			cout << "Run in debug?(y/n)\n";
			cin >> s1;
			if(s1 == "y")
				cout << p.Run(s0, 1) << endl;
			if (s1 == "n")
				cout << p.Run(s0) << endl;
			continue;
		}
		if (s == "save") {
			cout << "Enter file name:\n";
			string s = "";
			cin >> s;
			p.Save(s);
			continue;
		}
		if (s == "load") {
			cout << "Enter file name:\n";
			string s = "";
			cin >> s;
			p.Load(s);
			continue;
		}
		if (s == "help") {
			cout << "List of commands:\naddRule - create a new rule;\nrun - print processed data;\nexit - exit the program;\nsave - save ruleset to a file;\nload - load ruleset from a file;\n\n";
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


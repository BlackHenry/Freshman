#include "stdafx.h"
#include "Program.h"


Program::Program()
{
}

void Program::AddRule(Rule r, bool b) {
	program.add(0, r);
	if(b) size++;
}

void Program::RemoveRule(string s) {
	Rule r = Rule(s);
	program.remove(r);
}

void Program::Load(string path) {
	ifstream f(path);
	f >> size;
	for (int i = 0; i < size; i++) {
		string s = "";
		noskipws(f);
		fixed(f);
		do {
			getline(f, s);
		} while (!s.size());
		AddRule(s, 0);
		if (program.back().IsTerm())
			terminator = i;
	}
	f.close();
}

void Program::Save(string path) {
	ofstream z(path);
	z << size << endl;
	MyList<Rule>::iterator it;
	for (it = program.begin(); it != program.end(); it++) {
		z << (*it).Get(1) << "->";
		if ((*it).IsTerm())
			z << "!";
		z << (*it).Get(2);
		z << endl;
	}
	z.close();
}

string Program::Run(string t, bool debug) {
	int iterations = 0;
	string target = t;
	bool is_running = true;
	while (is_running && target.size() && iterations < 100000) {
		size_t a;
		MyList<Rule>::iterator it;
		for (it = program.begin(); it != program.end(); it++) {
			a = target.find((*it).Get(1));
			if (a != string::npos) {
				target.replace(a, (*it).Get(1).length(), (*it).Get(2));
				if ((*it).IsTerm())
					is_running = false;
				break;
			}
		}
		if (a == string::npos)
			is_running = false;
		if (debug) {
			cout << target << endl;
			cout << "waiting for input...\n";
			string s = "";
			cin >> s;
			if (s == "b")
				break;
		}
		iterations++;
	}
	if (iterations == 1000000) {
		cout << "Too many iterations!\n";
		return "";
	}
	if (debug) {
		cout << "Program took " << iterations << " iterations.\n";
	}
	return target;
}


Program::~Program()
{
}

#pragma once
#include <list>
#include "Rule.h"
#include "MyList.h"
#include <set>
#include <fstream>

using namespace std;

class Program
{
private:
	MyList<Rule> program;
	set<string> alphabet;
	int position, terminator = -1, size;
public:
	Program();
	void AddRule(Rule, bool b = 1);
	void RemoveRule(string);
	void Load(string);
	void Save(string);
	string Run(string, bool b = false);
	~Program();
};


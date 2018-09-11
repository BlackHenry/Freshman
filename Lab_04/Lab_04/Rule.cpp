#include "stdafx.h"
#include "Rule.h"

Rule::Rule(string s) {
	is_terminator = 0;
	first_word = s.substr(0, s.find("->"));
	second_word = s.substr(s.find("->") + 2, s.size());
	if (second_word[0] == '!') {
		is_terminator = true;
		second_word.erase(second_word.begin());
	}
}

string Rule::Get(int n) {
	if (n > 2) {
		cerr << "There are only two rules!\n";
		return "";
	}
	if (n == 1) {
		return first_word;
	}
	else {
		return second_word;
	}
}

void Rule::Set(int n, string s) {
	if (n > 2) {
		cerr << "There are only two rules!\n";
		return;
	}
	if (n == 1) {
		first_word = s;
	}
	else {
		second_word = s;
	}
}


Rule::~Rule()
{
}

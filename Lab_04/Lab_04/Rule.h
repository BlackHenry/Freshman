#pragma once
#include <string>
#include <iostream>

using namespace std;

class Rule
{
private:
	string first_word, second_word;
	bool is_terminator = false;
public:
	bool operator==(Rule other) { return (first_word + second_word) == (other.first_word + other.second_word); }
	Rule() {};
	Rule(string s1, string s2, bool b = false) : first_word(s1), second_word(s2), is_terminator(b) {};
	Rule(string);
	bool IsTerm() { return is_terminator; };
	string Get(int);
	void Set(int, string);
	~Rule();
};


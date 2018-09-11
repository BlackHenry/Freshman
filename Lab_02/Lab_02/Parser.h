#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef enum { num_type = 0, num_op_type, logic_op_type, char_type, type_type, string_type, punc_type, id_type, key_type } token_type;

class Parser
{
public:
	vector<pair<token_type, string> > code;
	vector<pair<string, int> > vars;
	vector<string> types = { "num_type", "num_op_type", "logic_op_type", "char_type", "type_type", "string_type", "punc_type", "id_type", "key_type" };
	fstream file;
	FILE* C_file;

	void print_code();

	bool is_num_op(char);

	bool is_logic_op(char);

	bool is_type(string);

	bool is_punc(char);

	bool is_key(string);

	string get_symb(fstream&, char);

	string get_int(fstream&, char);

	string get_symb(FILE*, char);

	string get_int(FILE*, char);

	bool parse();

	bool c_parse();

	char PeekC(FILE*);

	Parser(string);

	Parser(char*);
	
	~Parser();
};


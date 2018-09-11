#pragma once
#include "stdafx.h"
#include "Parser.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Analyzer
{
public:
	vector<pair<token_type, string> > code;
	vector<pair<string, int> > vars;
	vector<string> types = { "num_type", "num_op_type", "logic_op_type", "char_type", "type_type", "string_type", "punc_type", "id_type", "key_type" };

	int is_line(int position);

	bool init(string name);

	int is_expression(int position);

	int is_assigment(int position);

	int is_assigment_without_semicolon(int position);

	int is_return(int position);

	int is_declaration(int position);

	int is_while(int position);

	int is_if(int position);

	int is_for(int position);

	int is_param(int position);

	int is_func(int position);

	Analyzer();

	Analyzer(vector<pair<token_type, string> > c) :code(c) {};
	
	~Analyzer();
};


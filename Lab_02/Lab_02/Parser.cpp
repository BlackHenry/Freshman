#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Parser.h"

//Конструктор

Parser::Parser(string file_path)
{
	file = fstream(file_path);
}

Parser::Parser(char* file_path)
{
	fopen_s(&C_file, file_path, "r");
}

//Перевірка на належність до Мат_оператор

bool Parser::is_num_op(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

//Перевірка на належність до Лог_оператор

bool Parser::is_logic_op(char c) {
	return c == '&' || c == '!' || c == '=' || c == '<' || c == '>';
}

//Перевірка на належність до Типу

bool Parser::is_type(string s) {
	return s == "int" || s == "void" || s == "double" || s == "float" || s == "char" || s == "string";
}

//Перевірка на належність до Пунктуації

bool Parser::is_punc(char c) {
	return c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']' || c == ';' || c == '\"' || c == '\'';
}

//Перевірка на належність до Зарезервованого слова

bool Parser::is_key(string s) {
	return s == "for" || s == "while" || s == "if" || s == "else" || s == "cout" || s == "cin";
}

//Функія для отримання Строк

string Parser::get_symb(fstream& f, char c) {
	string res = "";
	char p;
	res += c;
	while (isalpha(f.peek()) || isdigit(f.peek())) {
		res += f.get();
	}
	return res;
}

char Parser::PeekC(FILE* f) {
	char c = getc(f);
	ungetc(c, f);
	return c;
}

string Parser::get_symb(FILE* f, char c) {
	string res = "";
	char p;
	res += c;
	while (isalpha(PeekC(f)) || isdigit(PeekC(f))) {
		res += getc(f);
	}
	return res;
}

//Функція для отримання Чисел

string Parser::get_int(FILE* f, char c) {
	string res = "";
	bool is_float = false;
	char p;
	res += c;
	while (isdigit(PeekC(f)) || (PeekC(f) == '.' && !is_float)) {
		res += getc(f);
		if (res.back() == '.')
			is_float = true;
	}
	return res;
}

//Функція для отримання Чисел

string Parser::get_int(fstream& f, char c) {
	string res = "";
	bool is_float = false;
	char p;
	res += c;
	while (isdigit(f.peek()) || (f.peek() == '.' && !is_float)) {
		res += f.get();
		if (res.back() == '.')
			is_float = true;
	}
	return res;
}

//Функція для виводу обробленого коду

void Parser::print_code() {
	for (int i = 0; i < code.size(); i++) {
		cout << i << "\t" << types[code[i].first] << " " << code[i].second << endl;
	}
}

//Функція обробки коду

bool Parser::parse()
{
	char c;
	string s = "";
	while (file.get(c)) {
		if (c == ' ' || c == '\t' || c == '\n')
			continue;
		if (isalpha(c) || c == '_') {
			s = get_symb(file, c);
			if (is_type(s)) {
				code.push_back(make_pair(type_type, s));
				s = "";
			}
			if (is_key(s)) {
				code.push_back(make_pair(key_type, s));
				s = "";
			}
			if (s.size()) {
				code.push_back(make_pair(id_type, s));
				s = "";
			}
			continue;
		}
		if (isdigit(c)) {
			s = get_int(file, c);
			code.push_back(make_pair(num_type, s));
			s = "";
			continue;
		}
		if (is_punc(c)) {
			s = c;
			code.push_back(make_pair(punc_type, s));
			s = "";
			continue;
		}
		if (is_num_op(c)) {
			s = c;
			code.push_back(make_pair(num_op_type, s));
			s = "";
			continue;
		}
		if (is_logic_op(c)) {
			s = c;
			if (is_logic_op(file.peek())) {
				if (file.peek() == '=' || (file.peek() == c && c != '<' && c != '>')) {
					s += file.get();
				}
			}
			code.push_back(make_pair(logic_op_type, s));
			s = "";
			continue;
		}
		cout << "Unexpected symbol!\n";
		return false;
	}
	return true;
}

bool Parser::c_parse()
{
	char c = 'a';
	string s = "";
	while (c) {
		c = getc(C_file);
		if (c == EOF)
			break;
		if (c == ' ' || c == '\t' || c == '\n')
			continue;
		if (isalpha(c) || c == '_') {
			s = get_symb(C_file, c);
			if (is_type(s)) {
				code.push_back(make_pair(type_type, s));
				s = "";
			}
			if (is_key(s)) {
				code.push_back(make_pair(key_type, s));
				s = "";
			}
			if (s.size()) {
				code.push_back(make_pair(id_type, s));
				s = "";
			}
			continue;
		}
		if (isdigit(c)) {
			s = get_int(C_file, c);
			code.push_back(make_pair(num_type, s));
			s = "";
			continue;
		}
		if (is_punc(c)) {
			s = c;
			code.push_back(make_pair(punc_type, s));
			s = "";
			continue;
		}
		if (is_num_op(c)) {
			s = c;
			code.push_back(make_pair(num_op_type, s));
			s = "";
			continue;
		}
		if (is_logic_op(c)) {
			s = c;
			if (is_logic_op(file.peek())) {
				if (file.peek() == '=' || (file.peek() == c && c != '<' && c != '>')) {
					s += file.get();
				}
			}
			code.push_back(make_pair(logic_op_type, s));
			s = "";
			continue;
		}
		cout << "Unexpected symbol!\n";
		return false;
	}
	return true;
}


//Деструктор

Parser::~Parser()
{
}

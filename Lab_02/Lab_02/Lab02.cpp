
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Parser.h"
#include "analyzer.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

/*
���_�������� = ">" | "<" | "=" | "&" | "|" | "!" 
���_�������� = "+" | "-" | "*" | "/"  | "%"
����� = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" | "0" 
������ = "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z"
����� = {�����}
�� = ������ | "_", {������ | "_" | �����}
����� = {�� | �����, ���_��������}, �� | �����
��������� = ��, ("++" | "--") | ( [���_��������], "=", �����), ";"
���������� = "return", �����, ";"
���������� = �������_��, ["=", �����]
If = "if", "(", �����, ")", ������� | "{", {�������}, "}", ["else", ������� | "{", {�������}, "}"]
While = "while", "(", �����, ")", ������� | "{", {�������}, "}"
For = "for", "(", ���������� | ���������, �����, ��������� ��� ������ � �����, ")", ������� | "{", {�������}, "}"
�������� = ���, ��, [ "=", �����]
������� = ���, �������_��, "(", {��������},  ")", "{", {�������}, "}"
������� = ���������� | If | While | ��������� | ����������
*/

int main()
{
	Parser p("code.txt");
	if (p.c_parse()) {
		Analyzer a(p.code);
		p.print_code();
		cout << endl;
		if (a.is_func(0)) {
			cout << "Everything is OK\n";
		}
	}
	system("pause");
    return 0;
}

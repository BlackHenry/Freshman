#pragma once
#include "stdafx.h"
#include <string>

typedef enum {}operation;

class MarkovOperation
{
public:
	string op1, op2;
	MarkovOperation() {};
	MarkovOperation(string s1, string s2) op1: s1, op2:s2;
	~MarkovOperation();
};


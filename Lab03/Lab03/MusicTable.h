#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

class MusicTable
{
public:
	char header[10][32];
	char* path;
	char row[256][32];
	int size_x, size_y = 1;
	void AddColumn(string);
	void AddRow();
	void RemoveRow(int);
	void Normalize(char*);
	char* Truncate(char*);
	void ChangeCell(int, int, char*);
	vector<int> Search(string, string);
	void PrintTable();
	void PrintRow(int);
	void PrintAnalysys();
	void ReadRow(int n);
	void WriteRow(int n);
	void ReadSize();
	void WriteSize();
	void EmptyRow();
	MusicTable() {};
	MusicTable(char*);
	~MusicTable();
};


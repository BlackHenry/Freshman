#ifndef MUSICTABLE_H
#define MUSICTABLE_H


#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class MusicTable
{
public:
	char* path;
	int size;
	size_t size_of_table = 40;
	unordered_map<char*, vector<char*> > database;
	unordered_map<char*, vector<char*> >::iterator it;
	void AddColumn(char*);
	void AddRow(int);
	void RemoveRow(int);
	int Search(char*, char*);
	void SaveTable();
	void LoadTable();
	void PrintTable();
	MusicTable() {};
	MusicTable(char*);
	~MusicTable();
};


#endif // MUSICTABLE_H

#pragma once
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <set>

class Graph
{
private:
	bool memory[65536] = {0};
	std::vector<std::vector<int> > adj_matrix;
	int size;
	bool is_K5();
	bool is_K3_3();
	void remove_vertex(int);
	void remove_edge(int, int);
	void contract_edge(int, int);
	int hash();
	int modul_pow(int, int, int);
public:
	Graph() {};
	Graph(std::vector<std::vector<int> > );
	Graph(std::vector<int> );
	bool is_planar();
	~Graph() {};
};


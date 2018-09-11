#include "stdafx.h"
#include "Graph.h"


Graph::Graph(std::vector<std::vector<int> > seed) {
	size = seed.size();
	adj_matrix = seed;
}

Graph::Graph(std::vector<int> seed) {
	size = seed.size();
	adj_matrix.resize(size);
	char buffer[33];
	for (int i = 0; i < size; i++) {
		itoa(seed[i], buffer, 2);
		for (int j = 0; j < strlen(buffer); j++) {
			adj_matrix[i].push_back(buffer[j] - '0');
			std::reverse(adj_matrix[i].begin(), adj_matrix[i].end()));
		}
	}
}

bool Graph::is_K5() {
	if (size != 5) {
		return 0;
	}
	int num_edges = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			num_edges += adj_matrix[i][j];
		}
	}
	return num_edges == 20;
}

bool Graph::is_K3_3() {
	if (size != 6) {
		return 0;
	}
	int num_edges = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			num_edges += adj_matrix[i][j];
		}
	}
	if (num_edges != 18) {
		return 0;
	}
	std::vector<int> vert_powers(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (adj_matrix[i][j]) {
				vert_powers[i]++;
			}
		}
	}
	for (auto it : vert_powers) {
		if (it != 3) {
			return 0;
		}
	}
	int v1 = 0, v2 = 0;
	for (int i = 1; i < size; i++) {
		if (!adj_matrix[0][i]) {
			if (!v1) {
				v1 = i;
			}
			else {
				v2 = i;
			}
		}
	}
	return !adj_matrix[v1][v2];
}

void Graph::remove_vertex(int n) {
	adj_matrix.erase(adj_matrix.begin() + n);
	for (auto it : adj_matrix) {
		it.erase(it.begin() + n);
	}
	size--;
}

void Graph::remove_edge(int n, int m) {
	adj_matrix[n][m] = 0;
	adj_matrix[m][n] = 0;
}

void Graph::contract_edge(int n, int m) {
	for (int i = 0; i < size; i++) {
		adj_matrix[i][n] = std::min(adj_matrix[i][m] + adj_matrix[i][n], 1);
	}
	remove_vertex(m);
}

int Graph::modul_pow(int a, int p, int m) {
	int res = a;
	for (int i = 1; i < p; i++) {
		res = (res * a) % m;
	}
	return res;
}

int Graph::hash() {
	std::vector<int> short_matrix;
	int res = 0;
	for (auto it : adj_matrix) {
		int a = 0;
		for (int i = 0; i < size; i++) {
			a += std::pow(2, size - i - 1) * it[i];
		}
		short_matrix.push_back(a);
	}
	for (int i = 0; i < size; i++) {
		res += short_matrix[i] * modul_pow(23, i, 65536) % 65536;
	}
	return res;
}

bool Graph::is_planar() {
	int h = hash();
	if (memory[h]) {
		return 1;
	}
	memory[h] = 1;
	if (is_K5() || is_K3_3()) {
		return 0;
	}
	for (int i = 0; i < size; i++) {
		std::vector<std::vector<int> > backup = adj_matrix;
		remove_vertex(i);
		if (!is_planar()) {
			return 0;
		}
		adj_matrix = backup;
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (adj_matrix[i][j]) {
				std::vector<std::vector<int> > backup = adj_matrix;
				remove_edge(i, j);
				if (!is_planar()) {
					return 0;
				}
				adj_matrix = backup;
				contract_edge(i, j);
				if (!is_planar()) {
					return 0;
				}
				adj_matrix = backup;
			}
		}
	}
	return 1;
}

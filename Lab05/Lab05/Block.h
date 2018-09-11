#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

template <class T>
class Block
{
private:
	int size;
public:
	Block() {};
	Block(int s) { size = s; };
	void Load(std::string path, int pos = 0) {
		std::ifstream f(path);
		for (int i = 0; i < pos; i++) {
			T element;
			f >> element;
		}
		int i = 0;
		for (i = 0; i < size; i++) {
			T element;
			f >> element;
			content.push_back(element);
		}
		f.close();
	}
	void Save(std::string path) {
		std::ofstream z(path);
		for (auto it : content) {
			z << it << std::endl;
		}
		z.close();
	}
	void Sort() {
		std::sort(content.begin(), content.end());
	}
	std::vector<T> content;
	~Block() {};
};


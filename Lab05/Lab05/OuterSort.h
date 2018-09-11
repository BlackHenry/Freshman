#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Block.h"

template <class T>
class OuterSort
{
private:
	std::string path;
	int max_size, file_size = 0;
public:
	OuterSort() {};
	OuterSort(std::string p, int m_s = 1000) { path = p; max_size = m_s/2; };
	int GetFileSize() {
		std::cout << "Getting file size..." << std::endl;
		T element;
		std::ifstream f(path);
		while (f >> element) {
			file_size++;
		}
		return file_size;
	}
	void PrepareBlocks() {
		int k = 0;
		std::cout << "Preparing blocks..." << std::endl;
		for (int i = 0; i < file_size; i += max_size) {
			Block<T> b = Block<T>(max_size);
			b.Load(path, i);
			b.Sort();
			b.Save(path + "Block" + std::to_string(k));
			k++;
			std::cout << k << std::endl;
		}
	}
	void SaveBlocks(std::string save_path) {
		std::ofstream z(save_path);
		for (int i = 0; i < file_size / max_size; i++) {
			Block<T> b = Block<T>(max_size);
			b.Load(path + "Block" + std::to_string(i));
			for (auto it : b.content) {
				z << it << std::endl;
			}
		}
		z.close();
	}
	void Sort() {
		GetFileSize();
		PrepareBlocks();
		std::cout << "Sorting..." << std::endl;
		for (int i = 0; i < file_size / max_size - 1; i++) {
			Block<T> b_i = Block<T>(max_size);
			b_i.Load(path + "Block" + std::to_string(i));
			for (int j = i + 1; j < file_size / max_size; j++) {
				Block<T> b_j = Block<T>(max_size);
				b_j.Load(path + "Block" + std::to_string(j));
				std::vector<T> merged;
				merged.insert(merged.end(), b_i.content.begin(), b_i.content.end());
				merged.insert(merged.end(), b_j.content.begin(), b_j.content.end());
				std::sort(merged.begin(), merged.end());
				for (int h = 0; h < merged.size(); h++) {
					if (h < max_size) {
						b_i.content[h] = merged[h];
					}
					else {
						b_j.content[h - max_size] = merged[h];
					}
				}
				b_j.Save(path + "Block" + std::to_string(j));
			}
			b_i.Save(path + "Block" + std::to_string(i));
		}
		SaveBlocks("final" + path);
	}
	~OuterSort() {};
};


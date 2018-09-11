// Lab06.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyList.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

MyList<std::string> bucket_sort(MyList<std::string> sorted_list) {
	MyList<std::string>::iterator it;
	int max_size = -1;
	for (it = sorted_list.begin(); it != sorted_list.end(); it++) {
		max_size = std::max(max_size, int((*it).size()));
	}
	for (it = sorted_list.begin(); it != sorted_list.end(); it++) {
		int el_size = (*it).size();
		for (int i = 0; i < max_size - el_size; i++) {
			(*it) += '`';
		}
	}
	std::vector<MyList<std::string> > buckets(27);
	for (int i = max_size - 1; i >= 0; i--) {
		for (it = sorted_list.begin(); it != sorted_list.end(); it++) {
			buckets[(*it)[i] - '`'].add((*it));
		}
		sorted_list.clear();
		for (int j = 0; j < buckets.size(); j++) {
			sorted_list.insert_back(buckets[j]);
			buckets[j].clear();
		}
	}
	for (it = sorted_list.begin(); it != sorted_list.end(); it++) {
		if ((*it).find('`') != std::string::npos)
			(*it) = (*it).erase((*it).find('`'), (*it).size() - (*it).find('`'));
	}
	return sorted_list;
}

int main()
{
	std::string arr[12] = { "abc", "abcd", "des", "fsn", "and", "indssa", "dsc", "poas", "qwmx", "xzk", "ja" , "lreu"};
	MyList<std::string> a;
	MyList<std::string>::iterator it;
	for (int i = 0; i < 10; i++) {
		a.add(arr[i]);
	}
	a = bucket_sort(a);
	for (it = a.begin(); it != a.end(); it++) {
		std::cout << (*it) << std::endl;
	}
	system("pause");
    return 0;
}


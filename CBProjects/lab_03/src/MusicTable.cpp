
#include "MusicTable.h"


MusicTable::MusicTable(char* save_file_path)
{
	path = save_file_path;
}

void MusicTable::AddColumn(char* s) {
	vector<char*> vr;
	database.insert(make_pair(s, vr));
}

void MusicTable::AddRow(int n) {
    char s0[256];
    string s;
	size++;
	if (n > size) {
		cout << "Element number is too big!\n";
		return;
	}
	for (it = database.begin(); it != database.end(); it++) {
		cout << "Enter value for column \"" << it->first << "\":\n";
		gets(s0);
		if (it->second.size() == n - 1) {
			it->second.push_back(s0);
		}
		else
			it->second.insert(it->second.begin() + n - 1, s0);
	}
}

void MusicTable::RemoveRow(int n) {
	for (it = database.begin(); it != database.end(); it++) {
		it->second.erase(it->second.begin() + n - 1);
	}
}

void MusicTable::PrintTable() {
	for (it = database.begin(); it != database.end(); it++) {
		printf("%s | ", (it->first));
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (it = database.begin(); it != database.end(); it++) {
			printf("%s\t", (it->second[i]));
			printf("%s\n", it->second.back());
		}
		cout << "\n";
	}
}

int MusicTable::Search(char* column, char* value) {
	if (database.find(column) == database.end()) {
		return 0;
	}
	vector<char*> vr = database[column];
	for (int i = 0; i < vr.size(); i++) {
		if (vr[i] == value) return i;
	}
	return -1;
}

void MusicTable::SaveTable() {
	FILE* save = fopen(path, "w");
	fprintf(save, "%d\n", database.size());
	fprintf(save, "%d\n", size);
	for (it = database.begin(); it != database.end(); it++) {
		fprintf(save, "%s\n", it->first);
	}
	for (int i = 0; i < size; i++) {
		for (it = database.begin(); it != database.end(); it++) {
			fprintf(save, "%s\n", it->second[i]);
		}
	}
}

void MusicTable::LoadTable() {

	FILE* save = fopen(path, "r");
    int table_size;
    fscanf(save, "%d", &table_size);
	fscanf(save, "%d", &size);
	it = database.begin();
	for (int i = 0; i < table_size; it++, i++) {
		vector<char*> vs;
		char* s;
		fscanf(save, "%s", s);
		database[s] = vs;
	}
	for (int i = 0; i < size; i++) {
		for (it = database.begin(); it != database.end(); it++) {
			char* s = "";
			fscanf(save, "%s", s);
			it->second.push_back(s);
		}
	}
}

MusicTable::~MusicTable()
{
}

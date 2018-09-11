#include <iostream>
#include <vector>
#include <unordered_map>

/*
void MusicTable::SaveTable() {
	FILE* save = fopen(path, "w");
	fprintf(save, "%d", );
	for (it = database.begin(); it != database.end(); it++) {
		fprintf(save, "%s", it->first);
	}
	for (int i = 0; i < size; i++) {
		for (it = database.begin(); it != database.end(); it++) {
			fprintf(save, "%s", it->second[i]);
		}
	}
}

void MusicTable::LoadTable() {

	FILE* save = fopen(path, "r");

	fscanf(save, "%d", &size);
	it = database.begin();
	for (int i = 0; i < size; it++, i++) {
		vector<string> vs;
		string s;
		fscanf(save, "%s", s);
		database[s] = vs;
	}
	for (int i = 0; i < size; i++) {
		for (it = database.begin(); it != database.end(); it++) {
			string s = "";
			fscanf(save, "%s", s);
			it->second.push_back(s);
		}
	}
}
*/

using namespace std;

int main()
{
    char* s1;
    gets(s1);
    printf("%s\n", s1);
    return 0;
}

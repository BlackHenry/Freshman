#include "stdafx.h"
#include "MusicTable.h"


MusicTable::MusicTable(char* save_file_path)
{
	ReadSize();
	path = save_file_path;
	ReadRow(0);
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < 31; j++) {
			if(row[i][j] != ' ')
				header[i][j] = row[i][j];
		}
	}
}

void MusicTable::ReadSize() {
	FILE* f = fopen("size.txt", "r");
	fscanf(f, "%d %d", &size_x, &size_y);
	fflush(f);
}

void MusicTable::WriteSize() {
	FILE* f = fopen("size.txt", "w");
	fprintf(f, "%d %d", size_x, size_y);
	fflush(f);
}

void MusicTable::AddColumn(string s) {
	strcpy(row[size_x], s.c_str());
	size_x++;
	WriteSize();
}

void MusicTable::Normalize(char* s) {
	for (int i = 0; i < 31; i++) {
		if (!(s[i]))
			s[i] = ' ';
	}
	s[31] = '\0';
}

char* MusicTable::Truncate(char* s0) {
	char s[32];
	fill(s, s + 31, ' ');
	s[31] = '\0';
	strcpy(s, s0);
	for (int i = 0; i < 31; i++) {
		if (s[i] == ' ' && s[i + 1] == ' ') {
			s[i] = '\0';
			break;
		}
	}
	return s;
}

void MusicTable::AddRow() {
	char s[32] = {};
	fill(s, s + 32, ' ');
	EmptyRow();
	for (int i = 0; i < size_x; i++) {
		printf("\nInput the \"%s\" column value:\n\n", header[i]);
		scanf(" %32[^\n]s", s);
		Normalize(s);
		strcpy(row[i], s);
		fill(s, s + 32, ' ');
	}
	WriteRow(size_y);
	size_y++;
	WriteSize();
}

void MusicTable::EmptyRow() {
	char s[32];
	fill(s, s + 32, ' ');
	s[31] = '\0';
	for (int i = 0; i < size_x; i++) {
		strcpy(row[i], s);
	}
}

void MusicTable::RemoveRow(int y) {
	if (y > size_y) {
		cout << "Y value out of range\n\n";
		return;
	}
	EmptyRow();
	WriteRow(size_y);
	for (int j = y; j <= size_y; j++) {
		ReadRow(j);
		WriteRow(j - 1);
	}
	size_y--;
	WriteSize();
}

void MusicTable::PrintAnalysys() {
	if (size_y == 1) {
		cout << "Too few elements!\n\n";
		return;
	}
	map<int,pair<char*, int> > mp;
	for (int i = 1; i < size_y; i++) {
		ReadRow(i);
		char s1[256][32];
		fill(s1[i], s1[i] + 31, ' ');
		s1[i][31] = '\0';
		int a = strtoll(row[3], NULL, 36) % 1000000000;
		mp[a].second++;
		strcpy(s1[i], Truncate(row[3]));
		mp[a].first = s1[i];
	}
	vector<char* > vr;
	int m = -1;
	for (auto it : mp) {
		m = max(m, it.second.second);
	}
	for (auto it : mp) {
		if (it.second.second == m) {
			vr.push_back(it.second.first);
		}
	}
	if (vr.size() > 1) {
		cout << "\nMost popular genres: "; 
		printf("%s", vr[0]);
		for (int i = 1; i < vr.size(); i++) {
			printf(", %s", vr[i]);
		}
		cout << "\n\n";
	}
	if (vr.size() == 1) {
		cout << "\nMost popular genre: ";
		printf("%s\n", vr[0]);
	}
	double s = 0;
	for (int i = 1; i < size_y; i++) {
		ReadRow(i);
		s += atoi(row[1]) / (double)(size_y - 1);
	}
	cout << "Average duration: " << s << endl << endl;
	return;
}

void MusicTable::PrintTable() {
	cout << "\n";
	for (int i = 0; i < size_y; i++) {
		ReadRow(i);
		for (int j = 0; j < size_x; j++) {
			printf("%.24s", row[j]);
		}
		printf("\n\n");
	}
}

void MusicTable::ReadRow(int n) {
	FILE* f = fopen(path, "r+b");
	int row_size = size_x * 32;
	char s[32];
	for (int i = 0; i < size_x; i++) {
		fseek(f, row_size * (n)+i * 32, SEEK_SET);
		fgets(s, 32, f);
		strcpy(row[i], s);
	}
	fflush(f);
}

void MusicTable::WriteRow(int n) {
	FILE* f = fopen(path, "r+b");
	rewind(f);
	int row_size = size_x * 32;
	char s[32];
	fill(s, s + 32, ' ');
	for (int i = 0; i < size_x; i++) {
		fseek(f, row_size * (n)+i * 32, SEEK_SET);
		strcpy(s, row[i]);
		fputs(s, f);
	}
	fflush(f);
}

void MusicTable::PrintRow(int i) {
	ReadRow(i);
	for (int j = 0; j < size_x; j++) {
		printf("%.24s", row[j]);
	}
	printf("\n\n");
}

vector<int> MusicTable::Search(string column, string value) {
	vector<int> vr;
	int c = -1;
	char s[32], s0[32];
	fill(s, s + 31, ' ');
	s[31] = '\0';
	fill(s0, s0 + 31, ' ');
	s0[31] = '\0';
	strcpy(s, column.c_str());
	strcpy(s0, value.c_str());
	Normalize(s);
	Normalize(s0);
	ReadRow(0);
	for (int i = 0; i < size_x; i++) {
		if (!strcmp(row[i], s)) {
			c = i;
		}
	}
	if (c == -1) {
		cout << "No such column!\n\n";
		return vr;
	}
	for (int i = 0; i < size_y; i++) {
		ReadRow(i);
		if (!strcmp(row[c], s0)) {
			vr.push_back(i);
		}
	}
	return vr;
}

void MusicTable::ChangeCell(int x, int y, char* s) {
	ReadRow(y);
	Normalize(s);
	strcpy(row[x - 1], s);
	WriteRow(y);
}

MusicTable::~MusicTable()
{
}

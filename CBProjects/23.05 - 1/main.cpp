#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

struct rect {
	float x1, y1, x2, y2;
};

struct node {
	rect rectangle;
	vector<node*> leaves;
	int data;
} *tree;

int last_node = 0;
vector<rect> vr;
list<vector<int> > adj_struct;
ofstream p("output.txt");

void print_rect(rect r) {
	p << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << endl;
}

bool in(rect z1, rect z2) {
	if (!(min(z1.x1, z1.x2) <= min(z2.x1, z2.x2) && max(z1.x1, z1.x2) >= max(z2.x1, z2.x2) && min(z1.y1, z1.y2) <= min(z2.y1, z2.y2) && max(z1.y1, z1.y2) >= max(z2.y1, z2.y2)))
		return false;
	return true;
}

bool cross(rect z1, rect z2) {
	if (min(z1.x1, z1.x2) >= max(z2.x1, z2.x2) || max(z1.x1, z1.x2) <= min(z2.x1, z2.x2) || min(z1.y1, z1.y2) >= max(z2.y1, z2.y2) || max(z1.y1, z1.y2) <= min(z2.y1, z2.y2))
		return false;
	return true;
}

rect generate_rect() {
	rect r;
	r.x1 = (rand()%10001 - 1) / 1000.0;
	r.y1 = (rand()% 10001 - 1) / 1000.0;
	r.x2 = (rand()% 10001 - 1) / 1000.0;
	r.y2 = (rand()% 10001 - 1) / 1000.0;
	while (abs(y2 - y1) < 2) {
		r.y1 = (rand() % 10001 - 1) / 1000.0;
		r.y2 = (rand() % 10001 - 1) / 1000.0;
	}
	return r;
}

void print_element(node *tree) {
	rect r = tree->rectangle;
	p << endl << "Прямоугольник: " << tree->data << " " << r.x1 << " " << r.x2 << " " << r.y1 << " " << r.y2 << endl;
}

void print_tree(node *root) {
	vector<node*> to_print;
	to_print.push_back(root);
	for (int i = 0; i < to_print.size(); i++) {
        p << "Дети: ";
        node *tree = to_print[i];
        print_element(tree);
        to_print.insert(to_print.end(), tree->leaves.begin(), tree->leaves.end());
        p << tree->data << ": ";
        for (auto it : tree->leaves) {
            p << it->data << " ";
        }
        p << endl << endl;
    }
}

void insert_tree(node *root, rect r) {
	for (auto child : root->leaves) {
		if (in(child->rectangle, r)) {
			insert_tree(child, r);
			return;
		}
	}
	node *new_child = new node;
	new_child->data = ++last_node;
	new_child->rectangle = r;
	root->leaves.push_back(new_child);
}

void print_adj_struct() {
	p << endl << "Структура смежности:" << endl;
	int i = 1;
	for (auto it: adj_struct) {
        p << i << ": ";
		for (int j = 0; j < it.size(); j++) {
            p << it[j] << " ";
		}
        i++;
		p << endl;
	}
}

void build_adj_struct() {
	for (int i = 0; i < 140 - 1; i++) {
        vector<int> adj;
		for (int j = 0; j < 140; j++) {
			if (cross(vr[i], vr[j]) && (i - j)) {
				adj.push_back(j);
			}
		}
		adj_struct.push_back(adj);
    }
}

void task_1() {
	int k1 = 0, k2 = 0;
	p << "Сгенерированные прямоугольники:" << endl << endl;
	for (int i = 0; i < 140; i++) {
		vr.push_back(generate_rect());
		print_rect(vr[i]);
		p << endl << endl;
	}
	for (int i = 0; i < 140; i++) {
		for (int j = 0; j < 140; j++) {
			if (i == j)
				continue;
			k1 += cross(vr[i], vr[j]);
			k2 += in(vr[i], vr[j]);
		}
	}
	k1 /= 2;
	float pairs = 140 * (140 - 1) / 2.0;
	p << "Прямоугольников пересекаются: " << k1 / pairs * 100 << endl <<"Прямоугольников содержится: " << k2 / pairs * 1000 << endl;
}

oid task_2() {
	node *root = new node;
	root->data = 0;
	rect root_rectangle;
	root_rectangle.x1 = -10;
	root_rectangle.x2 = 10;
	root_rectangle.y1 = -10;
	root_rectangle.y2 = 10;
	root->rectangle = root_rectangle;
	for (auto rectangle : vr) {
		insert_tree(root, rectangle);
	}
	print_tree(root);
}

void task_3() {
	build_adj_struct();
	print_adj_struct();
}

int main(){
	srand(time(0));
	task_1();
	task_2();
	task_3();
	system("pause");
	return 0;
}


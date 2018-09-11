#pragma once
#include <vector>
#include <algorithm>
template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
class MyList
{
private:
	int size_of_my_list = 0;
	node<T>* head;
	node<T>* tail;
public:
	class iterator {
	public:
		iterator() {}
		iterator(node<T>* p) { ptr = p; }
		void operator++(int) { ptr = (ptr)->next; }
		T& operator*() { return (ptr)->data; }
		iterator& operator=(node<T>* other) { ptr = other; return *this; }
		bool operator!=(const node<T>* p) { return ptr != p; }
	private:
		node<T>* ptr;
	};

	MyList() {
		head = nullptr; tail = nullptr;
	}

	~MyList() {};

	T max_element() {
		T max_el = -1e9;
		for (iterator it = begin(); it != end(); it++) {
			max_el = std::max(max_el, *it);
		}
		return max_el;
	}

	T min_element() {
		T min_el = 1e9;
		for (iterator it = begin(); it != end(); it++) {
			min_el = std::min(min_el, *it);
		}
		return min_el;
	}

	void clear() {
		size_of_my_list = 0;
		head = nullptr;
		tail = nullptr;
	}

	void bucket_sort() {
		if (max_element() == min_element()) {
			return;
		}
		std::vector<MyList<T> > buckets(size() + 1);
		int min_el = min_element();
		int bucket = std::round((max_element() - min_el) / float(size()));
		for (iterator it = begin(); it != end(); it++) {
			buckets[int((*it - min_el) / bucket)].add(*it);
		}
		MyList<T> temp;
		for (auto it1 : buckets) {
			if (it1.size() > 1) {
				it1.bucket_sort();
			}
			temp.insert_back(it1);
		}
		*this = temp;
	}

	void cycle() {
		tail->next = head;
	}

	void insert_back(MyList<T> other) {
		if (!other.size()) {
			return;
		}
		size_of_my_list += other.size();
		if (tail == nullptr) {
			*this = other;
		}
		else {
			tail->next = other.head;
			tail = other.tail;
		}
	}

	int size() {
		return size_of_my_list;
	}

	void add(const T val, int pos = 0)
	{
		size_of_my_list++;
		node<T>* temp = new node<T>;
		temp->data = val;
		temp->next = nullptr;
		if (!pos) {
			if (head == nullptr)
			{
				head = temp;
				tail = temp;
				temp = nullptr;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}
		else {
			node<T>* pre = nullptr;
			node<T>* cur = nullptr;
			node<T>* temp = nullptr;
			cur = head;
			for (int i = 1; i < pos && cur; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			temp->data = val;
			pre->next = temp;
			temp->next = cur;
		}
	}

	void remove(T val) {
		size_of_my_list--;
		node<T>* temp_curr = head, *temp_prev = tail;
		while (temp_curr->next != nullptr) {
			if (temp_curr->data == val) {
				temp_prev->next = temp_curr->next;
				if (temp_curr == head)
					head = temp_curr->next;
				if (temp_curr == tail)
					tail = temp_prev;
				delete temp_curr;
				return;
			}
			temp_prev = temp_prev->next;

			temp_curr = temp_curr->next;
		}
	}

	T back() {
		return tail->data;
	}

	node<T>* begin() {
		return head;
	}

	node<T>* end() {
		return tail->next;
	}
};


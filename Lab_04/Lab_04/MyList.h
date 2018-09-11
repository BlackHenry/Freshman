#pragma once
#include "stdafx.h"

template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
class MyList
{
private:
	node<T>* head;
	node<T>* tail;
public:
	class iterator {
	public:
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
	void add(int pos, const T val)
	{
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
		node<T>* temp_curr = head, *temp_prev = head;
		while (temp_curr->next != nullptr) {
			if (temp_curr->data == val) {
				temp_prev->next = temp_curr->next;
				delete temp_curr;
			}
			if (temp_curr != head) {
				temp_prev = temp_prev->next;
			}
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
		return nullptr;
	}
};


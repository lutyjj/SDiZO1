#pragma once
struct ElemList {
	int data;
	ElemList* next;
	ElemList* prev;
};

struct List {
	ElemList* head = nullptr;
	int size = 0;
	void display();
	void fill_random(int);
	void push_front(int);
	void pop_front();
	void push_back(int);
	void pop_back();
	void clear();
	bool search(int);
	void push_at(int, int);
	void pop_at(int);
	void readFromFile(std::string);
};


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
	void push_front(int);
	void pop_front();
	void push_back(int);
	void pop_back();
	void clear();
	bool search(int);
	void push_random(int, int);
	void pop_random();
	void readFromFile(std::string);
};


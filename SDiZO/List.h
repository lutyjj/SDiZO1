#pragma once
struct ElemList {
	int data;
	ElemList* next;
	ElemList* prev;
};

struct List {
	ElemList* head = NULL;
	void display();
	void push_front(int);
	void pop_front();
	void push_back(int);
	void pop_back();
};


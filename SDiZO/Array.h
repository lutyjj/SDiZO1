#pragma once
struct Array {
	Array();
	int* head;
	int size;
	void display();
	void fill_random(int);
	void push_front(int);
	void pop_front();
	void push_back(int);
	void pop_back();
	bool search(int);
	void push_at(int, int);
	void pop_at(int);
	void readFromFile(std::string);
};
#pragma once
#include <iostream>

struct BinaryHeap
{
	BinaryHeap();
	int* heapArr;
	int size;
	void push(int);
	void pop();
	void pop_value(int);
	void display(std::string, std::string, int);
	void display();
	bool search(int);
	void heapifyFromTop(int);
	void heapifyFromBottom(int);
	void fillRandom(int);
	void readFromFile(std::string);
	void build();
};
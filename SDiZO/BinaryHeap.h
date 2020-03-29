#pragma once
#include <iostream>

struct BinaryHeap
{
	BinaryHeap();
	int* heapArr;
	int size;
	void push(int);
	void pop();
	void display(std::string, std::string, int);
	bool search(int);
	void heapify(int);
	void fillRandom(int);
	void readFromFile(std::string);
	void build();
};
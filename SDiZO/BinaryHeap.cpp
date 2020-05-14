#include "BinaryHeap.h"
#include <string>
#include <iostream>
#include <random>
#include <fstream>

BinaryHeap::BinaryHeap() {
	heapArr = new int[20000];
	size = 0;
}

bool BinaryHeap::search(int value) {
	// Cycle through whole heap array and compare
	for (int i = 0; i < size; i++) {
		if (heapArr[i] == value)
			return true;
	}
	return false;
}

void BinaryHeap::push(int value) {
	// Add value to heap
	heapArr[size] = value;
	size++;

	// Repair heap
	int i = size - 1;
	int parent = (i - 1) / 2;
	while (i > 0 && heapArr[parent] < heapArr[i]) {
		int tmp = heapArr[i];
		heapArr[i] = heapArr[parent];
		heapArr[parent] = tmp;

		i = parent;
		parent = (i - 1) / 2;
	}
}

void BinaryHeap::pop() {
	if (size == 0)
		return;

	heapArr[0] = heapArr[size - 1];
	heapArr[size - 1] = 0;
	size--;

	heapifyFromTop(0);
}

void BinaryHeap::pop_value(int value) {
	int index = 0;

	for (int i = 0; i < size; i++) {
		if (heapArr[i] == value) {
			index = i;
			break;
		}
	}

	if (index == 0) {
		pop();
		return;
	}

	size--;
	if (size == 0) 
		return;
	heapArr[index] = heapArr[size];

	heapifyFromTop(index);
	heapifyFromBottom(index);
}

void BinaryHeap::heapifyFromTop(int index) {
	int left, right, largest;

	while (true) {
		left = 2 * index + 1;
		right = 2 * index + 2;
		largest = index;

		if (left < size && heapArr[left] > heapArr[largest]) 
			largest = left;

		if (right < size && heapArr[right] > heapArr[largest])
			largest = right;

		if (largest == index)
			break;

		int tmp = heapArr[index];
		heapArr[index] = heapArr[largest];
		heapArr[largest] = tmp;
		index = largest;
	}
}

void BinaryHeap::heapifyFromBottom(int index) {
	int parent = (index - 1) / 2;
	int tmp = 0;

	while (parent || index) {
		if (heapArr[parent] < heapArr[index]) {
			tmp = heapArr[parent];
			heapArr[parent] = heapArr[index];
			heapArr[index] = tmp;
		}
		index = parent;
		parent = (index - 1) / 2;
	}
}

void BinaryHeap::fillRandom(int size) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 100);

	// Clear heap array
	for (int i = 0; i < size; i++) {
		heapArr[i] = 0;
	}
	this->size = 0;

	// Fill array with random numbers between [0, 100]
	for (int i = 0; i < size; i++) {
		push(dist(rng));
	}
}

void BinaryHeap::build() {
	for (int i = (size - 2) / 2; i >= 0; i--)
		heapifyFromTop(i);
}

void BinaryHeap::display(std::string sp, std::string sn, int value) {
	std::string stringR, stringL, stringP;
	std::string s;
	stringR = stringL = stringP = "  ";
	stringR[0] = 218; stringR[1] = 196;
	stringL[0] = 192; stringL[1] = 196;
	stringP[0] = 179;

	if (value < size) {
		s = sp;
		if (sn == stringR) { s[s.length() - 2] = ' '; }

		display(s + stringP, stringR, 2 * value + 2);
		s = s.substr(0, sp.length() - 2);
		std::cout << s << sn << heapArr[value] << std::endl;

		s = sp;
		if (sn == stringL) { s[s.length() - 2] = ' '; }

		display(s + stringP, stringL, 2 * value + 1);
	}
}

void BinaryHeap::display() {
	display("", "", 0);
}

void BinaryHeap::readFromFile(std::string fileName) {
	// Clear array
	delete[] heapArr;
	size = 0;
	std::ifstream file;
	int value;
	// Open file with entered name
	file.open(fileName);
	// Check if file exists
	if (file) {
		// First line is always reserved for number of elements
		// as per project requierements
		file >> value;
		std::cout << "Number of items: " << value;
		heapArr = new int[value];
		// Push every value from file to tail of list
		while (file >> value) {
			push(value);
		}
	}
	else std::cerr << "Error while reading file";
	file.close();
}
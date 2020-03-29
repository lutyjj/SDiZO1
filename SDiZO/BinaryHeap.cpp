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
	// Poprawic
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

	heapify(0);
}

void BinaryHeap::heapify(int i) {
	int leftChild;
	int rightChild;
	int largestChild;

	while (true) {
		leftChild = 2 * i + 1;
		rightChild = 2 * i + 2;
		largestChild = i;

		if (leftChild < size && heapArr[leftChild] > heapArr[largestChild]) 
			largestChild = leftChild;

		if (rightChild < size && heapArr[rightChild] > heapArr[largestChild])
			largestChild = rightChild;

		if (largestChild == i)
			break;

		int temp = heapArr[i];
		heapArr[i] = heapArr[largestChild];
		heapArr[largestChild] = temp;
		i = largestChild;
	}
}

void BinaryHeap::fillRandom(int size) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 100);

	// Clear heap array
	delete[] heapArr;
	heapArr = new int[20000];
	this->size = 0;

	int counter = 0;
	// Fill array with random numbers between [0, 100]
	while (counter < size) {
		push(dist(rng));
		counter++;
	}
	build();
}

void BinaryHeap::build() {
	for (int i = size / 2; i >= 0; i--) {
		heapify(i);
	}
}

void BinaryHeap::display(std::string sp, std::string sn, int value)
{
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

void BinaryHeap::readFromFile(std::string fileName) {
	// Clear list
	delete[] heapArr;
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
		// Push every value from file to tail of list
		while (file >> value) {
			push(value);
		}
	}
	else std::cerr << "Error while reading file";
	file.close();
}
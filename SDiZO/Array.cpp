#include <iostream>
#include <random>
#include <fstream>
#include "Array.h"

Array::Array() {
	size = 0;
	head = new int[size];
}

void Array::display() {
	int* tmp = head;
	if (tmp) {
		for (int i = 0; i < size; i++) {
			std::cout << tmp[i] << " ";
		}
	}
}

void Array::push_front(int value) {
	size++;
	int* new_arr = new int[size];
	new_arr[0] = value;
	for (int i = 1; i < size; i++) {
		new_arr[i] = head[i - 1];
	}
	delete[] head;
	head = new_arr;
}

void Array::push_at(int value, int index) {
	if (size == 0) push_front(value);
	else if (index >= size) push_back(value);
	else {
		size++;
		int* new_arr = new int[size];
		for (int i = 0; i < index; i++) {
			new_arr[i] = head[i];
		}
		new_arr[index] = value;
		for (int i = index + 1; i < size; i++) {
			new_arr[i] = head[i - 1];
		}
		delete[] head;
		head = new_arr;
	}
}

void Array::push_back(int value) {
	size++;
	int* new_arr = new int[size];
	for (int i = 0; i < size - 1; i++) {
		new_arr[i] = head[i];
	}

	delete[] head;
	head = new_arr;
	head[size - 1] = value;
}

void Array::pop_front() {
	if (head && size > 0) {
		size--;
		int* new_arr = new int[size];
		for (int i = 0; i < size; i++) {
			new_arr[i] = head[i + 1];
		}
		delete[] head;
		head = new_arr;
	}
}

void Array::pop_at(int index) {
	if (index == 0) pop_front();
	else if (index >= size) pop_back();
	else {
		size--;
		int* new_arr = new int[size];
		for (int i = 0; i < index; i++) {
			new_arr[i] = head[i];
		}
		for (int i = index; i < size; i++) {
			new_arr[i] = head[i + 1];
		}
		delete[] head;
		head = new_arr;
	}
}

void Array::pop_back() {
	if (head && size > 0) {
		size--;
		int* new_arr = new int[size];
		for (int i = 0; i < size; i++) {
			new_arr[i] = head[i];
		}
		delete[] head;
		head = new_arr;
	}
}

bool Array::search(int value) {
	if (head && size > 0) {
		for (int i = 0; i < size; i++) {
			if (head[i] == value) {
				return true;
				break;
			}
		}
	}
	return false;
}

void Array::fill_random(int size) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 100);

	// Clear array
	delete[] head;
	head = new int[size];
	this->size = 0;
	// Fill array with random numbers between [0, 100]
	for (int i = 0; i < size; i++) {
		push_back(dist(rng));
	}
}

void Array::readFromFile(std::string fileName) {
	// Clear list
	delete[] head;
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
			push_back(value);
		}
	}
	else std::cerr << "Error while reading file";
	file.close();
}
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
	// Create new array with bigger size
	int* new_arr = new int[size];

	// Insert new value in front
	new_arr[0] = value;

	// Copy rest of array
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
		// Copy array part before index of new element
		for (int i = 0; i < index; i++) {
			new_arr[i] = head[i];
		}
		// Insert new element
		new_arr[index] = value;

		// Copy rest of array
		for (int i = index + 1; i < size; i++) {
			new_arr[i] = head[i - 1];
		}
		delete[] head;
		head = new_arr;
	}
}

void Array::push_back(int value) {
	size++;
	int* newArr = new int[size];

	// Copy array to new array
	for (int i = 0; i < size - 1; i++) {
		newArr[i] = head[i];
	}

	delete[] head;
	head = newArr;

	// Insert new element
	head[size - 1] = value;
}

void Array::pop_front() {
	if (head && size > 0) {
		size--;
		// Create smaller array
		int* new_arr = new int[size];

		// Copy all elements from main array except first element
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
		// Create smaller array
		int* new_arr = new int[size];

		// Copy part of array to new array
		for (int i = 0; i < index; i++) {
			new_arr[i] = head[i];
		}

		// Skip element at index and copy rest
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

		// Create smaller array
		int* new_arr = new int[size];

		// Copy all elements except last one
		for (int i = 0; i < size; i++) {
			new_arr[i] = head[i];
		}
		delete[] head;
		head = new_arr;
	}
}

bool Array::search(int value) {
	if (head && size > 0) {
		// Check every element of array
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
	// Clear array
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
		head = new int[value];
		// Push every value from file to tail of list
		while (file >> value) {
			push_back(value);
		}
	}
	else std::cerr << "Error while reading file";
	file.close();
}
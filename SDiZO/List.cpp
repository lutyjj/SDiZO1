#include <iostream>
#include <fstream>
#include <random>
#include "List.h"

List::List() {
	head = nullptr;
	size = 0;
}

void List::display() {
	// Set pointer to head of list
	ElemList* tmp = head;
	std::cout << "Size: " << size << std::endl;
	if (head) {
		// Cycle through list and show every element
		std::cout << "[ ";
		while (tmp) {
			std::cout << tmp->data << " ";
			tmp = tmp->next;
		}
		std::cout << "]" << std::endl;

		tmp = head;
		std::cout << "[ ";
		while (tmp && tmp->next) {
			tmp = tmp->next;
		}
		while (tmp != head) {
			std::cout << tmp->data << " ";
			tmp = tmp->prev;
		}
		std::cout << tmp->data << " ]" << std::endl;
	}
}

void List::clear() {
	// Check if head exists
	if (head) {
		ElemList* tmp = head, *tmp_next;
		// Cycle through every element and delete if exists
		while (tmp) {
			tmp_next = tmp->next;
			delete tmp;
			tmp = tmp_next;
		}
		head = nullptr;
		size = 0;
	}
}

bool List::search(int value) {
	// Check if head exists
	if (head) {
		ElemList* tmp = head;
		// Cycle through list until needed value found
		while (tmp) {
			if (tmp->data == value) return true;
			tmp = tmp->next;
		}
	}
	return false;
}

void List::push_at(int value, int index) {
	// Check if list size is smaller than index
	// False -> push value to the back
	// True -> check where to place 
	// If index > 0 and head exists, cycle through
	// list and place element at index
	if (index > size - 1) push_back(value);
	else if (index == 0 || head == nullptr) push_front(value);
	else {
		ElemList* tmp = head;
		while (index > 1 && tmp->next) {
			tmp = tmp->next;
			index--;
		}
		ElemList* p = new ElemList;
		p->data = value;
		p->next = tmp->next;
		p->prev = tmp;
		tmp->next = p;
		size++;
	}
}

void List::pop_at(int index) {
	// Check if head exists
	if (head) {
		// Check if list size is <= than index
		// False -> pop element at tail
		// True -> check where to pop 
		// If index > 0, cycle through
		// list and pop element at index
		if (index >= size - 1) pop_back();
		else if (index == 0) pop_front();
		else {
			ElemList* tmp = head;
			while (index > 0 && tmp->next) {
				tmp = tmp->next;
				index--;
			}
			// Re-attach prev and next elemets
			// near popped element
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			delete tmp;
			size--;
		}
	}
}

void List::fill_random(int size) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 100);

	// Clear list
	clear();
	int counter = 0;
	// Fill list with random numbers between [0, 100]
	while (counter < size) {
		push_back(dist(rng));
		counter++;
	}
}

void List::readFromFile(std::string fileName) {
	// Clear list
	clear();
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

void List::push_front(int value) {
	// Create new element
	ElemList* p = new ElemList;
	// Fill element data with entered value
	p->data = value;
	// Attach head as next element for p
	// since we want to push list from front
	p->next = head;
	// If head exists, attach new element as previous
	if (head) head->prev = p;
	// Make new element head
	head = p;
	size++;
}

void List::pop_front() {
	// Check if head exists
	if (head) {
		// Copy head to a reserve element
		ElemList* p = head;
		// Make second element new head head
		head = head->next;
		// Free previous head
		delete p;
		size--;
	}
}

void List::pop_back() {
	// Copy head to a reserve element
	ElemList* p = head;
	// Check if head exists
	if (head) {
		// If head has next element, cycle through list
		if (head->next) {
			while (p->next->next)
				p = p->next;
			// Delete last element of list
			delete p->next;
			// Make new last element point at null
			p->next = nullptr;
			size--;
		}
		// If head is the only element, delete it
		// and make head point at null
		else {
			delete p;
			head = nullptr;
			size = 0;
		}
	}
}

void List::push_back(int value) {
	// Create new element
	ElemList* v = new ElemList;
	// Copy head to a reserve element
	ElemList* e = head;
	// Fill new element with data
	v->data = value;
	// Since we want to push new element to tail,
	// make it point to null
	v->next = nullptr;
	// Check if head exists
	if (head) {
		// Cycle through list
		while (e->next)
			e = e->next;
		// Make last element point at new element
		e->next = v;
		// Attach new element last field to last element
		v->prev = e;
	}
	// If head doesn't exist, make new element head
	else head = v;
	size++;
}